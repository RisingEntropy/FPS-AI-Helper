//
// Created by RisingEntropy on 12/8/2023.
//

#ifndef CFAIHELPER_YOLOENGINE_H
#define CFAIHELPER_YOLOENGINE_H
#include <vector>
#include <opencv2/opencv.hpp>
#include <string>
#include <ncnn/net.h>
class YoloObject{
public:
    static const int GLOBAL_RISK = 0;
    static const int BLACK_LIST = 1;
    float x1,y1,x2,y2;
    int id;
    float confidence;

};
class YoloEngine {
public:
    class YoloSetting{
    public:
        std::string modelPath,paramPath;
        bool useGPU = false;
        float confThreshold = 0.7;
        float nmsThreshold = 0.45;
        int cpuThreads = -1;
        YoloSetting() = default;
        YoloSetting(std::string& modelPath,std::string& paramPath, bool useGPU = false, float confThreshold = 0.7, float nmsThreshold = 0.45, int cpuThreads = -1);
    };
    YoloEngine() = default;
    ~YoloEngine();
    bool loadSetting(YoloSetting setting);
    std::vector<YoloObject> inference(const cv::Mat&);
    static int getGPUCount();
    void stop();
private:
    static bool checkFileExists(std::string& path);
    void nms(std::vector<YoloObject>& candidate);
    ncnn::Net net;
    const int target_size = 640;
    YoloSetting setting;
    bool ready = false;
    bool inferring = false;
};


#endif //CFAIHELPER_YOLOENGINE_H
