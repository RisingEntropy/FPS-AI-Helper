//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_CONTROLMODEL_H
#define CFAIHELPER_CONTROLMODEL_H

#include <string>
#include <map>
#include "ActionExecutor.h"
#include "FrameSource.h"
#include "../AIBackend/YoloEngine.h"
#include "ActionDecider.h"
#include <vector>
#include <QTimer>
class ControlModel {
public:
    static const int CONTROLLER_TYPE_UI = 0x00;
    class ControlInterface{
    public:
        virtual bool setModelPath(std::string path) = 0;
        virtual bool setParamPath(std::string path) = 0;
        virtual bool setUseGPU(bool useGpu) = 0;
        virtual bool setConfThreshold(float threshold) = 0;
        virtual bool setNMSThreshold(float threshold) = 0;
        virtual bool setCPUThreads(int threads) = 0;
        virtual bool startAIEngine() = 0;
        virtual bool stopAIEngine() = 0;
        virtual bool setActionExecutor(std::string name) = 0;
        virtual bool setFrameSource(std::string name) = 0;
        virtual bool setDecider(std::string name) = 0;
        virtual bool isGPUAvailable() = 0;
        virtual std::vector<std::string> getActionExecutorNames() = 0;
        virtual std::vector<std::string> getFrameSourceNames() = 0;
        virtual std::vector<std::string> getDeciderNames() = 0;
        virtual bool start() = 0;
        virtual bool stop() = 0;
        virtual bool setFrameRate(double rate) = 0;

    };
    ControlModel();
    ~ControlModel();
    ControlInterface * getControlInterface(int type);
private:
    YoloEngine engine;
    YoloEngine::YoloSetting setting;
    std::map<std::string, ActionExecutor *> executors;
    std::map<std::string, FrameSource *> frameSources;
    std::map<std::string, ActionDecider *> deciders;
    ActionExecutor * selectedExecutor = nullptr;
    FrameSource * selectedFrameSource = nullptr;
    ActionDecider * selectedDecider = nullptr;
    int interval = 0;
    double frameRate = 0.0f;
    bool working = false;
    QTimer timer;
    friend class UIControlInterface;


    class UIControlInterface:public ControlModel::ControlInterface{
    public:
        explicit UIControlInterface(ControlModel *controlModel);
        bool setModelPath(std::string path) override;
        bool setParamPath(std::string path) override;
        bool setUseGPU(bool useGpu) override;
        bool setConfThreshold(float threshold) override;
        bool setNMSThreshold(float threshold) override;
        bool setCPUThreads(int threads) override;
        bool startAIEngine() override;
        bool stopAIEngine() override;
        bool setActionExecutor(std::string name) override;
        bool setFrameSource(std::string name) override;
        bool start() override;
        bool stop() override;
        bool setFrameRate(double rate) override;
        bool setDecider(std::string name) override;
        bool isGPUAvailable() override;
        std::vector<std::string> getActionExecutorNames() override;
        std::vector<std::string> getFrameSourceNames() override;
        std::vector<std::string> getDeciderNames() override;
    private:
        ControlModel *model = nullptr;

    };
private Q_SLOTS:
    void timerOut();
};


#endif //CFAIHELPER_CONTROLMODEL_H
