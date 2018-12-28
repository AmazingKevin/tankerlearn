//
// Created by admin on 2018/12/26.
//

#include "SceneM.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "LevelScene.h"
#include "LoadingScene.h"
#include "MenuScene.h"
#include "TransitionEx.h"


static SceneM *s_ShareSceneM = nullptr;
SceneM::SceneM(){}
SceneM::~SceneM(){}
SceneM * SceneM::getInstance() {
    if(!s_ShareSceneM){
        s_ShareSceneM = new (std::nothrow) SceneM();
    }
    return s_ShareSceneM;
}
bool SceneM::init()
{
}