//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_FRAMESOURCE_H
#define CFAIHELPER_FRAMESOURCE_H
#include "string"
#include <opencv2/opencv.hpp>
class FrameSource {
public:
    virtual std::string getSourceName() = 0;
    virtual cv::Mat getFrame() = 0;
    virtual ~FrameSource();
};


#endif //CFAIHELPER_FRAMESOURCE_H
