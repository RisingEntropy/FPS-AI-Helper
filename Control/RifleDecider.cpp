//
// Created by RisingEntropy on 12/11/2023.
//

#include "RifleDecider.h"
#include <algorithm>
std::string RifleDecider::getDeciderName() {
    return "Rifle Decider";
}

void RifleDecider::decide(ActionExecutor *executor, std::vector<YoloObject> objs, cv::Mat& originImage) {
    if(objs.empty())return;// no target, do nothing
    std::sort(objs.begin(),objs.end(),[](YoloObject &o1, YoloObject &o2)->bool {
        return (o1.y2-o1.y1)*(o1.x2-o1.x1)>(o2.y2-o2.y1)*(o2.x2-o2.x1);
    });
    auto mPos = executor->getMousePosition();
    int mouseX = mPos.first, mouseY = mPos.second;
    auto target = objs[0];// the biggest target
    int target_x = target.x1+(target.x2-target.x1)/2, target_y = target.y1+(target.y2-target.y1)/2;
    target_x+=480;
    target_y+=130;
    int dx = target_x - mouseX, dy = target_y - mouseY;
    if(executor->mouseRightState()==ActionExecutor::KEY_STATE_UP)return;// not enabled
    executor->moveMouseRelative(simplePID(dx),simplePID(dy));
}

int RifleDecider::simplePID(int error) {
    return error*0.3;
}

RifleDecider::~RifleDecider() {

}
