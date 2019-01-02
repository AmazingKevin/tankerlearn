//
// Created by admin on 2019/1/2.
//

#ifndef PROJ_ANDROID_BOMBM_H
#define PROJ_ANDROID_BOMBM_H
#include "cocos2d.h"
#include "Bomb.h"
USING_NS_CC;
class BombM:public Layer
{
public:
    BombM();
    ~BombM();
    CREATE_FUNC(BombM);
    /**
     * 创建爆炸
     * type 爆炸类型
     * pos 爆炸位置
     * score 爆炸后显示的分数
     */
    void createBomb(BombType type, Vec2 pos, int score = 0);
    /* 暂停游戏（暂停播放所有爆炸动画） */
    void pauseGame();
    /* 继续游戏（继续播放所有爆炸动画） */
    void resumeGame();



};







#endif //PROJ_ANDROID_BOMBM_H
