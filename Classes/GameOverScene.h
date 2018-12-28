//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_GAMEOVERSCENE_H
#define PROJ_ANDROID_GAMEOVERSCENE_H

#include "cocos2d.h"
USING_NS_CC;
class GameOverScene:public Scene{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameOverScene);
};

#endif //PROJ_ANDROID_GAMEOVERSCENE_H
