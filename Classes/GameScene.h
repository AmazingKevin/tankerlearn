//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_GAMESCENE_H
#define PROJ_ANDROID_GAMESCENE_H
#include "cocos2d.h"
USING_NS_CC;
class GameScene:public Scene{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);

    virtual void onEnterTransitionDidFinish();

};

#endif //PROJ_ANDROID_GAMESCENE_H
