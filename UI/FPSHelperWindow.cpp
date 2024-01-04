//
// Created by RisingEntropy on 12/10/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_this.h" resolved

#include "FPSHelperWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <windows.h>
Ui::FPSHelperWindow::FPSHelperWindow(QWidget *parent, ControlModel::ControlInterface *controlInterface): QMainWindow(parent){
    this->setupUi(this);
    this->controlInterface = controlInterface;
}

Ui::FPSHelperWindow::~FPSHelperWindow() {

}

void Ui::FPSHelperWindow::chooseParam() {
    if(this->controlInterface == nullptr){
        std::cerr<<"Error! UI part gets a null pouinter for controlInterface\n";
        return;
    }
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose .param file"),"./", tr("param file(*.param);;"));
    if(fileName=="")return;
    this->controlInterface->setParamPath(fileName.toStdString());
    this->paramChosen = true;
}

void Ui::FPSHelperWindow::chooseBin() {
    if(this->controlInterface == nullptr){
        std::cerr<<"Error! UI part gets a null pouinter for controlInterface\n";
        return;
    }
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose .bin file"),"./", tr("bin file(*.bin);;"));
    if(fileName=="")return;
    this->controlInterface->setModelPath(fileName.toStdString());
    this->binChosen = true;
}

void Ui::FPSHelperWindow::confirmAIModel() {
    if(this->controlInterface == nullptr){
        std::cerr<<"Error! UI part gets a null pouinter for controlInterface\n";
        return;
    }
    if(!this->paramChosen){
        QMessageBox::critical(this,tr("Error"),tr("Please choose the .param file of AI model"),QMessageBox::Ok);
    }
    if(!this->binChosen){
        QMessageBox::critical(this,tr("Error"),tr("Please choose the .bin file of AI model"),QMessageBox::Ok);
    }
    this->groupBox_2->setEnabled(true);
    SYSTEM_INFO sysInfo;
    GetSystemInfo( &sysInfo );
    this->cpuThreadSpinBox->setMaximum(std::max(1,int(sysInfo.dwNumberOfProcessors-1)));//at least leave one core for game

    if(this->controlInterface->isGPUAvailable()){
        this->gpuCheckBox->setEnabled(true);
        this->gpuCheckBox->setText(tr(""));

    }else{
        this->gpuCheckBox->setEnabled(false);
        this->gpuCheckBox->setText(tr("GPU not available"));
    }

}

void Ui::FPSHelperWindow::confirmAIEngine() {
    if(this->controlInterface == nullptr){
        std::cerr<<"Error! UI part gets a null pouinter for controlInterface\n";
        return;
    }
    this->controlInterface->setConfThreshold(this->confidenceThresholdSpinBox->value());
    this->controlInterface->setNMSThreshold(this->nmsThresholdSpinBox->value());
    this->controlInterface->setUseGPU(this->gpuCheckBox->isChecked());
    this->controlInterface->setCPUThreads(this->cpuThreadSpinBox->value());
    this->stopButton->setEnabled(false);
    this->groupBox_3->setEnabled(true);
    this->modeCombBox->clear();
    this->controlModeComb->clear();
    this->imageSourceComb->clear();
    for(const auto& name:this->controlInterface->getDeciderNames()){
        if(!name.empty()) {
            this->modeCombBox->addItem(QString::fromStdString(name));
        }
    }
    this->modeCombBox->setCurrentIndex(0);
    for(const auto& name:this->controlInterface->getActionExecutorNames()){
        if(!name.empty())
            this->controlModeComb->addItem(QString::fromStdString(name));
    }
    this->controlModeComb->setCurrentIndex(0);
    for(const auto& name:this->controlInterface->getFrameSourceNames()){
        if(!name.empty())
            this->imageSourceComb->addItem(QString::fromStdString(name));
    }
    this->imageSourceComb->setCurrentIndex(0);
}

void Ui::FPSHelperWindow::start() {
    if(this->controlInterface == nullptr){
        std::cerr<<"Error! UI part gets a null pouinter for controlInterface\n";
        return;
    }
    this->controlInterface->setDecider(this->modeCombBox->currentText().toStdString());
    this->controlInterface->setActionExecutor(this->controlModeComb->currentText().toStdString());
    this->controlInterface->setFrameSource(this->imageSourceComb->currentText().toStdString());
    this->controlInterface->setFrameRate(this->frameRateSpinBox->value());
    this->startButton->setEnabled(false);
    this->stopButton->setEnabled(true);
    this->controlInterface->startAIEngine();
    this->controlInterface->start();
}

void Ui::FPSHelperWindow::stop() {
    if(this->controlInterface == nullptr){
        std::cerr<<"Error! UI part gets a null pouinter for controlInterface\n";
        return;
    }
    this->controlInterface->stop();
    this->startButton->setEnabled(true);
    this->stopButton->setEnabled(false);
    this->controlInterface->stopAIEngine();
}

