//
// Created by admin on 2019/1/2.
//

#ifndef PROJ_ANDROID_BOMB_H
#define PROJ_ANDROID_BOMB_H
#include "cocos2d.h"
USING_NS_CC;
enum BombType
{
    kPlayerTankBomb,
    kEnemyTankBomb,
    kStrongholdBomb,
    kBulletBomb
};

class Bomb:public Sprite {
public:
    Bomb();
    ~Bomb();
    static Bomb* create(BombType type,int score );
    virtual bool init(BombType tpye,int score );
private:
    void bombEnd(Node* sender);
    BombType _type;
    int _score;
};


#endif //PROJ_ANDROID_BOMB_H
