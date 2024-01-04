//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_RIFLEDECIDER_H
#define CFAIHELPER_RIFLEDECIDER_H

#include "ActionDecider.h"
class RifleDecider :public ActionDecider {
public:
    std::string getDeciderName() override;
    void decide(ActionExecutor* executor, std::vector<YoloObject> objs, cv::Mat& originImage) override;
    ~RifleDecider() override;
private:
    int simplePID(int error);
};


#endif //CFAIHELPER_RIFLEDECIDER_H
