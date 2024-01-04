//
// Created by RisingEntropy on 12/11/2023.
//

#include "SoftwareSimulateExecutor.h"
#include <windows.h>
#include <winuser.h>
#include <iostream>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

void SoftwareSimulateExecutor::moveMouse(int x, int y) {
    INPUT inputs[2] = {};
    ZeroMemory(inputs, sizeof(inputs));
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dx = x;
    inputs[0].mi.dy = y;
    inputs[0].mi.mouseData = 0;
    inputs[0].mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void SoftwareSimulateExecutor::moveMouseRelative(int rel_x, int rel_y) {
//    static POINT p;
//    GetCursorPos(&p);
//    SetCursorPos(p.x+rel_x, p.y+rel_y);
    INPUT inputs[2] = {};
    ZeroMemory(inputs, sizeof(inputs));
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dx = rel_x;
    inputs[0].mi.dy = rel_y;
    inputs[0].mi.mouseData = 0;
    inputs[0].mi.dwFlags = MOUSEEVENTF_MOVE;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

std::pair<int, int> SoftwareSimulateExecutor::getMousePosition() {
    static POINT p;
    GetCursorPos(&p);
    return std::pair<int, int>(p.x,p.y);
}

void SoftwareSimulateExecutor::mouseLeftDown() {
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
}

void SoftwareSimulateExecutor::mouseLeftUp() {
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void SoftwareSimulateExecutor::mouseRightDown() {
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
}

void SoftwareSimulateExecutor::mouseRightUp() {
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
}

int SoftwareSimulateExecutor::mouseLeftState() {
    if(KEY_DOWN(VK_LBUTTON)){
        return KEY_STATE_DOWN;
    }else{
        return KEY_STATE_UP;
    }
}

int SoftwareSimulateExecutor::mouseRightState() {
    if(KEY_DOWN(VK_RBUTTON)){
        return KEY_STATE_DOWN;
    }else{
        return KEY_STATE_UP;
    }
}

void SoftwareSimulateExecutor::keyDown(int key) {
    keybd_event(key,0,0,0);
}

void SoftwareSimulateExecutor::keyUp(int key) {
    keybd_event(key,KEYEVENTF_KEYUP,0,0);
}

int SoftwareSimulateExecutor::keyState(int key) {
    if(KEY_DOWN(key)){
        return KEY_STATE_DOWN;
    }else{
        return KEY_STATE_UP;
    }
}

std::string SoftwareSimulateExecutor::getExecutorName() {
    return "SoftwareSimulateExecutor";
}

SoftwareSimulateExecutor::~SoftwareSimulateExecutor() = default;
