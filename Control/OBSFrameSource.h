//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_OBSFRAMESOURCE_H
#define CFAIHELPER_OBSFRAMESOURCE_H
#include <QSharedMemory>
#include "FrameSource.h"
#include <string>
class OBSFrameSource: public FrameSource{
public:
    std::string getSourceName() override;
    cv::Mat getFrame() override;
    OBSFrameSource(std::string sharedMemoryName);
    OBSFrameSource() = delete;
    ~OBSFrameSource() override;
private:
    QSharedMemory *sharedMemory;
    unsigned char * buf = nullptr;
    size_t buf_length = 0;

};


#endif //CFAIHELPER_OBSFRAMESOURCE_H
