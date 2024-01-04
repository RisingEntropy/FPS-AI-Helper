//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_FILEFRAMESOURCE_H
#define CFAIHELPER_FILEFRAMESOURCE_H
#include <string>
#include <opencv2/opencv.hpp>
#include "FrameSource.h"

class FileFrameSource :public FrameSource{
public:
    std::string getSourceName() override;
    cv::Mat getFrame() override;
    ~FileFrameSource() override = default;
};


#endif //CFAIHELPER_FILEFRAMESOURCE_H
