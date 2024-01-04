//
// Created by RisingEntropy on 12/11/2023.
//

#ifndef CFAIHELPER_ACTIONEXECUTOR_H
#define CFAIHELPER_ACTIONEXECUTOR_H
#include <string>

class ActionExecutor {
public:
    static const int KEY_STATE_DOWN = 0;// key state, key here refers to both mouse and keyboard
    static const int KEY_STATE_UP = 1;
    virtual void moveMouse(int x,int y) = 0;
    virtual void moveMouseRelative(int rel_x,int rel_y) = 0;
    virtual void mouseLeftDown() = 0;
    virtual void mouseLeftUp() = 0;
    virtual void mouseRightDown() = 0;
    virtual void mouseRightUp() = 0;
    virtual std::pair<int,int> getMousePosition() = 0;
    virtual int mouseLeftState() = 0;
    virtual int mouseRightState() = 0;
    virtual void keyDown(int key) = 0;
    virtual void keyUp(int key) = 0;
    virtual int keyState(int key) = 0;
    virtual std::string getExecutorName() = 0;
    virtual ~ActionExecutor();
};


#endif //CFAIHELPER_ACTIONEXECUTOR_H
