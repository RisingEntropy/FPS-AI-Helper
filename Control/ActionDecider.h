//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_ACTIONDECIDER_H
#define CFAIHELPER_ACTIONDECIDER_H

#include "ActionExecutor.h"
#include "../AIBackend/YoloEngine.h"
#include <vector>
#include <string>
class ActionDecider {
public:
    virtual std::string getDeciderName() = 0;
    virtual void decide(ActionExecutor* executor, std::vector<YoloObject>, cv::Mat &originImage) = 0;
    virtual ~ActionDecider();
};


#endif //CFAIHELPER_ACTIONDECIDER_H
