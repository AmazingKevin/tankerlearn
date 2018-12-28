//
// Created by admin on 2018/12/26.
//

#ifndef PROJ_ANDROID_SCENEM_H
#define PROJ_ANDROID_SCENEM_H
#include "cocos2d.h"



USING_NS_CC;

enum SceneType			// 场景类型
{
    kLoadingScene,		// 加载场景
    kMenuScene,			// 菜单场景
    kLevelScene,		// 关卡过渡场景
    kGameScene,			// 游戏场景
    kGameOverScene		// 游戏结束场景
};

enum TransitionType		// 场景切换效果类型
{
    kTransitionNone,	// 无
    kTransitionExA,		// 扩展效果A（进入关卡过渡场景的效果）
    kTransitionExB,		// 扩展效果B（离开关卡过渡场景的效果）
};

class SceneM:public Ref{
public:
    SceneM();
    ~SceneM();
    static SceneM* getInstance();
    bool init();

    void changeScene(SceneType sceneTpye,TransitionType transitionType=kTransitionNone);
    Scene* getCurScene(){return _scene;}
private:
    Scene* _scene;
};













#endif //PROJ_ANDROID_SCENEM_H
