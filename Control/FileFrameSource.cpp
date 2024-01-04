//
// Created by RisingEntropy on 12/11/2023.
//

#include "FileFrameSource.h"

std::string FileFrameSource::getSourceName() {
    return "FileSource";
}

cv::Mat FileFrameSource::getFrame() {
    cv::Mat ret;
    cv::cvtColor(cv::imread("tmp - Copy.jpg"),ret,cv::COLOR_BGR2RGB);
    return ret;
}
