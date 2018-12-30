//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_LEVELSCENE_H
#define PROJ_ANDROID_LEVELSCENE_H
#include "cocos2d.h"
USING_NS_CC;
/*关卡过渡场景 每两关之间显示第几关 的 类 */
class LevelScene:public Scene{
public:
    LevelScene();
    ~LevelScene();
    virtual bool init();
    CREATE_FUNC(LevelScene);
    virtual void onEnterTransitionDidFinish();
private:
    void update(float dt);
    /* 更新显示的关卡id */
    void updateLevel();
    int _id;//关卡id
    bool _first;//是否刚从菜单进入游戏
    bool _start;//是否开始游戏
    float _interval;//控制选关 变化时间间隔
    Sprite * _stage;//"Stage" 图片精灵
    LabelAtlas * _num;//关卡id的标签
};

#endif //PROJ_ANDROID_LEVELSCENE_H
