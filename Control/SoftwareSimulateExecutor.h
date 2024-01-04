//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_SOFTWARESIMULATEEXECUTOR_H
#define CFAIHELPER_SOFTWARESIMULATEEXECUTOR_H

#include "ActionExecutor.h"
class SoftwareSimulateExecutor : public ActionExecutor{
public:
    void moveMouse(int x,int y) override;
    void moveMouseRelative(int rel_x,int rel_y) override;
    void mouseLeftDown() override;
    void mouseLeftUp() override;
    void mouseRightDown() override;
    void mouseRightUp() override;
    int mouseLeftState() override;
    int mouseRightState() override;
    std::pair<int,int> getMousePosition() override;
    void keyDown(int key) override;
    void keyUp(int key) override;
    int keyState(int key) override;
    std::string getExecutorName() override;
    ~SoftwareSimulateExecutor() override;
};


#endif //CFAIHELPER_SOFTWARESIMULATEEXECUTOR_H
