//
// Created by RisingEntropy on 12/8/2023.
//

#include "YoloEngine.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cpu.h>

YoloEngine::YoloSetting::YoloSetting(std::string& modelPath, std::string& paramPath, bool useGPU, float confThreshold,
                                     float nmsThreshold, int cpuThreads) {
    this->modelPath = modelPath;
    this->paramPath = paramPath;
    this->useGPU = useGPU;
    this->confThreshold = confThreshold;
    this->nmsThreshold = nmsThreshold;
    this->cpuThreads = cpuThreads;
}


bool YoloEngine::loadSetting(YoloEngine::YoloSetting setting) {
    if((!YoloEngine::checkFileExists(setting.modelPath))||(!YoloEngine::checkFileExists(setting.paramPath))){
        return false;
    }
    if(ncnn::get_gpu_count()>=1){
        if(setting.useGPU){
            this->net.opt.use_vulkan_compute = true;
            std::cout<<"Enable GPU"<<std::endl;
        }else{
            this->net.opt.use_vulkan_compute = false;
            std::cout<<"Disable GPU"<<std::endl;
        }
    }else{
        this->net.opt.use_vulkan_compute = false;
        std::cout<<"No GPU"<<std::endl;
    }
    if(this->net.load_param(setting.paramPath.data())){
        return false;
    }
    if(this->net.load_model(setting.modelPath.data())){// load successful
        return false;
    }
    if(this->setting.cpuThreads!=-1){
        ncnn::set_omp_num_threads(this->setting.cpuThreads);
    }
    this->setting = setting;
    this->ready = true;
    std::cout<<"Engine loaded\n";
    return true;

}



std::vector<YoloObject> YoloEngine::inference(const cv::Mat& image) {
    if(!this->ready){
        return {};
    }

    if(image.empty())return {};
    if(image.type()!=CV_8UC3){
        std::cerr<<"Warning: image to infer is not in format CV_8UC3\n";
        return {};
    }
    if(this->inferring)return {};
    this->inferring = true;
    int w = image.cols;
    int h = image.rows;
    float scale = 1.f;
    if (w > h){
        scale = (float)target_size / w;
        w = target_size;
        h = h * scale;
    }else{
        scale = (float)target_size / h;
        h = target_size;
        w = w * scale;
    }
    const int wpad = target_size - w;
    const int hpad = target_size - h;
    ncnn::Mat in = ncnn::Mat::from_pixels_resize(image.data, ncnn::Mat::PIXEL_RGB, w, h, 640, 640);
    ncnn::Mat in_pad;
    ncnn::copy_make_border(in, in_pad, hpad / 2, hpad - hpad / 2, wpad / 2, wpad - wpad / 2, ncnn::BORDER_CONSTANT, 114.f);
    const float norm_vals[3] = { 1 / 255.f, 1 / 255.f, 1 / 255.f };
    in_pad.substract_mean_normalize(0, norm_vals);


    ncnn::Extractor extractor = net.create_extractor();
    extractor.set_light_mode(true);
    extractor.input("in0",in_pad);
    ncnn::Mat out;
    extractor.extract("out0",out);//center_x, center_y, width, height, conf, cls1_conf, cls2_conf


    std::vector<YoloObject> boxes;
    int totalCandidate = out.h;
    float *dataPtr = out.channel(0);
    for(int i = 0;i<totalCandidate;i++){
        float center_x = dataPtr[0];
        float center_y = dataPtr[1];
        float width = dataPtr[2];
        float height = dataPtr[3];
        float conf = dataPtr[4];
        float cls1_conf = dataPtr[5]*conf;
        float cls2_conf = dataPtr[6]*conf;
        if(cls1_conf>this->setting.confThreshold||cls2_conf>this->setting.confThreshold){
            boxes.push_back(YoloObject{center_x-width/2, center_y-height/2,
                                       center_x+width/2, center_y+height/2, cls2_conf>cls1_conf, std::max(cls1_conf, cls2_conf)});
        }
        dataPtr+=7;
    }
    this->nms(boxes);
    this->inferring = false;
    return boxes;
}

bool YoloEngine::checkFileExists(std::string& path) {
    std::ifstream f(path);
    return f.good();
}

int YoloEngine::getGPUCount() {
    return ncnn::get_gpu_count();
}

YoloEngine::~YoloEngine() {
    net.clear();
}

void YoloEngine::nms(std::vector<YoloObject>& candidate) {
    std::sort(candidate.begin(), candidate.end(),
              [](YoloObject a, YoloObject b) { return a.confidence > b.confidence; });
    std::vector<float> vArea(candidate.size());
    for (int i = 0; i < int(candidate.size()); ++i) {
        vArea[i] = (candidate.at(i).x2 - candidate.at(i).x1 + 1)
                   * (candidate.at(i).y2 - candidate.at(i).y1 + 1);
    }
    for (int i = 0; i < int(candidate.size()); ++i) {
        for (int j = i + 1; j < int(candidate.size());) {
            float xx1 = std::max(candidate[i].x1, candidate[j].x1);
            float yy1 = std::max(candidate[i].y1, candidate[j].y1);
            float xx2 = std::min(candidate[i].x2, candidate[j].x2);
            float yy2 = std::min(candidate[i].y2, candidate[j].y2);
            float w = std::max(float(0), xx2 - xx1 + 1);
            float h = std::max(float(0), yy2 - yy1 + 1);
            float inter = w * h;
            float ovr = inter / (vArea[i] + vArea[j] - inter);
            if (ovr >= this->setting.nmsThreshold) {
                candidate.erase(candidate.begin() + j);
                vArea.erase(vArea.begin() + j);
            } else {
                j++;
            }
        }
    }
}

void YoloEngine::stop() {
    this->ready = false;
    while(this->inferring);
    std::cout<<"Engine stop\n";
}

