//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_GAMESCENE_H
#define PROJ_ANDROID_GAMESCENE_H
#include "cocos2d.h"
#include "Stage.hpp"
#include "TankM.hpp"
#include "BulletM.hpp"

USING_NS_CC;

enum GameState//游戏状态
{
    kRunning,//进行中
    kPause,//暂停
    kWin,//胜利
    kFail,
    kNone
};



class GameScene:public Scene{
public:
    GameScene();
    ~GameScene();
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);

    virtual void onEnterTransitionDidFinish();
private:
    static GameState _gameState;//游戏状态
    static Stage * _stage;//舞台类
    
    
    

};

#endif //PROJ_ANDROID_GAMESCENE_H
