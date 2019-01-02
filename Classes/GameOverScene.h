//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_GAMEOVERSCENE_H
#define PROJ_ANDROID_GAMEOVERSCENE_H


#include "cocos2d.h"

USING_NS_CC;

/* 游戏结束场景类 */
class GameOverScene : public Layer
{
public:
    GameOverScene();
    ~GameOverScene();
    CREATE_FUNC(GameOverScene);
    virtual bool init();
    
private:
    void update(float dt);
};

#endif //PROJ_ANDROID_GAMEOVERSCENE_H
