//
// Created by admin on 2018/12/29.
//

#ifndef PROJ_ANDROID_JOYSTICK_H
#define PROJ_ANDROID_JOYSTICK_H

#include "cocos2d.h"
USING_NS_CC;
class Joystick:public Layer
{
public:
    Joystick();
    ~Joystick();
    CREATE_FUNC(Joystick);
    virtual bool init();

private:
    /* 设置 触摸 虚拟手柄*/
    void setTouch(Sprite* target,Vec2 location,bool state);
    /* 设置按键状态（键盘） */
    void setKeyState(EventKeyboard::KeyCode keyCode, bool state);
};


#endif //PROJ_ANDROID_JOYSTICK_H
