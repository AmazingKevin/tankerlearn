//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_LEVELSCENE_H
#define PROJ_ANDROID_LEVELSCENE_H
#include "cocos2d.h"
USING_NS_CC;
class LevelScene:public Scene{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(LevelScene);
};

#endif //PROJ_ANDROID_LEVELSCENE_H
