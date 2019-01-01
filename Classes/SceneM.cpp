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
    return true;
}

void SceneM::changeScene(SceneType sceneTpye, TransitionType transitionType) {

    switch (sceneTpye)
    {
        case kLoadingScene:
            _scene=LoadingScene::create();
            break;
        case kMenuScene:
            _scene=MenuScene::create();
            break;
        case kLevelScene:
            _scene=LevelScene::create();
            break;
        case kGameScene:
            _scene = GameScene::create();
            break;
        case kGameOverScene:
            _scene = GameOverScene::create();
            break;

    }
    auto director = Director::getInstance();
    auto curScene = director->getRunningScene();
    switch (transitionType)
    {
        case kTransitionExA:
            _scene = TransitionExA::create(0.5f, _scene);
            break;
        case kTransitionExB:
            _scene = TransitionExB::create(0.5f, _scene);
            break;
        default:
            break;
    }
    if(curScene)
    {
        director->replaceScene(_scene);
    }
    else
    {
        director->runWithScene(_scene);
    }

}
