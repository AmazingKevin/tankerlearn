//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_MENUSCENE_H
#define PROJ_ANDROID_MENUSCENE_H
#include "cocos2d.h"
USING_NS_CC;
class MenuScene:public Scene{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
};

#endif //PROJ_ANDROID_MENUSCENE_H