//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_MENUSCENE_H
#define PROJ_ANDROID_MENUSCENE_H
#include "cocos2d.h"
USING_NS_CC;
enum Option{//选项
    ONE_PLAYER,//一个玩家
    TWO_PLAYER

};
class MenuScene:public Scene{
public:
    MenuScene();
    ~MenuScene();
    
    virtual bool init();
    CREATE_FUNC(MenuScene);
private:
    void update(float dt);
    /* 移动完毕,显示坦克 箭头 */
    void moveOver();
    /* 设置坦克 所指选项 */
    void setOption(int option);
    Sprite *_bg;		// 菜单背景
    Sprite *_tank;		// 坦克（箭头）
    bool _moveOver;		// 是否移动完毕
    int _option;		// 选项
};

#endif //PROJ_ANDROID_MENUSCENE_H
