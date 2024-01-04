//
// Created by RisingEntropy on 12/11/2023.
//

#include "ControlModel.h"
#include "SoftwareSimulateExecutor.h"
#include "OBSFrameSource.h"
#include "RifleDecider.h"
#include "FileFrameSource.h"

ControlModel::ControlModel() {
    ActionExecutor* executor = new SoftwareSimulateExecutor();// temporally fixed, change later
    this->executors[executor->getExecutorName()] = executor;
    auto source = new OBSFrameSource("FPSHelperSHM");// temporally fixed, change later
    this->frameSources[source->getSourceName()] = source;
    this->frameSources["FileSource"] = new FileFrameSource();
    auto decider = new RifleDecider();
    this->deciders[decider->getDeciderName()] = decider;
//    QTimer::connect(&this->timer,&QTimer::timeout, this,&ControlModel::timerOut);



    this->timer.setInterval(500);
}
ControlModel::~ControlModel() {
    std::for_each(this->executors.begin(),this->executors.end(),[](const std::pair<std::string, ActionExecutor*> p){delete p.second;});
    std::for_each(this->frameSources.begin(),this->frameSources.end(),[](const std::pair<std::string, FrameSource*> p){delete p.second;});
    std::for_each(this->deciders.begin(),this->deciders.end(),[](const std::pair<std::string, ActionDecider*> p){delete p.second;});
    this->timer.stop();
}
ControlModel::ControlInterface *ControlModel::getControlInterface(int type) {
    if(type==ControlModel::CONTROLLER_TYPE_UI){
        return new ControlModel::UIControlInterface(this);
    }
    return nullptr;
}

void ControlModel::timerOut() {

    if(this->working){
        if(this->selectedDecider!= nullptr && this->selectedFrameSource!= nullptr && this->selectedExecutor != nullptr){
            cv::Mat img = this->selectedFrameSource->getFrame();
            this->selectedDecider->decide(this->selectedExecutor, this->engine.inference(img), img);
        }
    }
}


ControlModel::UIControlInterface::UIControlInterface(ControlModel *controlModel) {
    this->model = controlModel;

}

std::vector<std::string> ControlModel::UIControlInterface::getFrameSourceNames() {
    std::vector<std::string > names(this->model->frameSources.size());
    std::for_each(this->model->frameSources.begin(),this->model->frameSources.end(),
                  [&names](const std::pair<std::string , FrameSource*>& p){names.push_back(p.first);});
    std::sort(names.begin(),names.end());
    return names;
}

std::vector<std::string> ControlModel::UIControlInterface::getActionExecutorNames() {
    std::vector<std::string > names(this->model->frameSources.size());
    std::for_each(this->model->executors.begin(),this->model->executors.end(),
                  [&names](const std::pair<std::string , ActionExecutor *>& p){names.push_back(p.first);});
    std::sort(names.begin(),names.end());
    return names;
}
std::vector<std::string> ControlModel::UIControlInterface::getDeciderNames() {
    std::vector<std::string > names(this->model->deciders.size());
    std::for_each(this->model->deciders.begin(),this->model->deciders.end(),
                  [&names](const std::pair<std::string , ActionDecider *>& p){names.push_back(p.first);});
    std::sort(names.begin(),names.end());
    return names;
}


bool ControlModel::UIControlInterface::setFrameSource(std::string name) {
    if(this->model->frameSources.count(name)==0){
        return false;
    }
    this->model->selectedFrameSource = this->model->frameSources[name];
    return true;
}

bool ControlModel::UIControlInterface::setActionExecutor(std::string name) {
    if(this->model->executors.count(name)==0){
        return false;
    }
    this->model->selectedExecutor = this->model->executors[name];
    return true;
}


bool ControlModel::UIControlInterface::setDecider(std::string name) {
    if(this->model->deciders.count(name)==0){
        return false;
    }
    this->model->selectedDecider = this->model->deciders[name];
    return true;
}
bool ControlModel::UIControlInterface::stopAIEngine() {
    this->model->engine.stop();
    return true;
}

bool ControlModel::UIControlInterface::startAIEngine() {
    return this->model->engine.loadSetting(this->model->setting);
}

bool ControlModel::UIControlInterface::setModelPath(std::string path) {
    this->model->setting.modelPath = path;
    return true;
}
bool ControlModel::UIControlInterface::setParamPath(std::string path) {
    this->model->setting.paramPath = path;
    return true;
}

bool ControlModel::UIControlInterface::setUseGPU(bool useGpu) {
    this->model->setting.useGPU = useGpu;
    return true;
}

bool ControlModel::UIControlInterface::setConfThreshold(float threshold) {
    this->model->setting.confThreshold = threshold;
    return true;
}


bool ControlModel::UIControlInterface::setNMSThreshold(float threshold) {
    this->model->setting.nmsThreshold = threshold;
    return true;
}

bool ControlModel::UIControlInterface::setCPUThreads(int threads) {
    this->model->setting.cpuThreads = threads;
    return true;
}

bool ControlModel::UIControlInterface::start() {
    this->model->working = true;
    std::thread([=](){
        while(model->working){
            model->timerOut();
            if(model->working)
                std::this_thread::sleep_for(std::chrono::milliseconds(model->interval));
//            std::cout<<"delay at:"<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()<<std::endl;
        }
    }).detach();
    this->model->timer.start();
    return true;
}

bool ControlModel::UIControlInterface::stop() {
    this->model->working = false;
    this->model->timer.stop();
    return true;
}

bool ControlModel::UIControlInterface::setFrameRate(double rate) {
    this->model->frameRate = rate;
    this->model->interval = static_cast<int>(1.0/rate*1000);
    return true;
}

bool ControlModel::UIControlInterface::isGPUAvailable() {
    return this->model->engine.getGPUCount()>=1;
}

