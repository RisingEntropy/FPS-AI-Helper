//
// Created by RisingEntropy on 12/11/2023.
//

#include "OBSFrameSource.h"


std::string OBSFrameSource::getSourceName() {
    return "OBS Frame Source";
}

cv::Mat OBSFrameSource::getFrame() {
    if(!this->sharedMemory->isAttached()){
        if(!this->sharedMemory->attach()){
            std::cerr<<"Error unable to attach to the shared memory named:"
            <<this->sharedMemory->nativeKey().data()<<std::endl;
            return {};
        }
    }
    if(this->buf == nullptr){
        this->buf_length = this->sharedMemory->size();
        this->buf = new unsigned char[this->sharedMemory->size()];
    }
    if(this->buf_length!=this->sharedMemory->size()){
        std::cerr<<"Warning! Shared memory size change detected!\n";
        delete this->buf;
        this->buf_length = this->sharedMemory->size();
        this->buf = new unsigned char[this->sharedMemory->size()];
    }
    this->sharedMemory->lock();
    memcpy(reinterpret_cast<unsigned char *>(this->buf),
           reinterpret_cast<unsigned char *>(this->sharedMemory->data()),
           this->buf_length);
    this->sharedMemory->unlock();
    unsigned int H = *reinterpret_cast<unsigned int *>(this->buf);
    unsigned int W = *reinterpret_cast<unsigned int *>(this->buf+4);
    cv::Mat img(W,H,CV_8UC4);
    uint8_t *data = reinterpret_cast<uint8_t *>(&this->buf[4]);
    memcpy(img.data, data, H*W*4);
    cv::Mat RGBImg;
    cv::cvtColor(img, RGBImg, cv::COLOR_RGBA2RGB);
    return RGBImg;
}

OBSFrameSource::~OBSFrameSource() {
    delete this->sharedMemory;
    delete this->buf;
}

OBSFrameSource::OBSFrameSource(std::string sharedMemoryName) {
    this->sharedMemory = new QSharedMemory;
    this->sharedMemory->setNativeKey(sharedMemoryName.data());
}
