//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_LOADINGSCENE_H
#define PROJ_ANDROID_LOADINGSCENE_H
#include "cocos2d.h"
USING_NS_CC;
class LoadingScene:public Scene{
public:
    LoadingScene();
    ~LoadingScene();
    virtual bool init();
    CREATE_FUNC(LoadingScene);
};

#endif //PROJ_ANDROID_LOADINGSCENE_H
