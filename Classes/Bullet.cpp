//
//  Bullet.cpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#include "Bullet.hpp"
#include "GameScene.h"
#include "AudioM.h"
Bullet::Bullet():
_bomb(false),
_dt(0)
{
}

Bullet::~Bullet()
{
}
Bullet* Bullet::create(void* owner, float speed, int power, Vec2 pos, Direction direction)
{
    Bullet * pRet = new Bullet();
    if(pRet && pRet->init(owner, speed, power, pos, direction))
    {
        pRet->autorelease();
        return pRet;
    }else{
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
bool Bullet::init(void* owner,float speed,int power,Vec2 pos,Direction direction)
{
    this->initWithFile("bullet.png");
    _owner = owner;
    _speed = speed;
    _power = power;
    _direction = direction;
    this->setPosition(pos);
    this->setRotation((direction - 1)*90);
    _newPos = pos;
    this->scheduleUpdate();
    
    return true;
}

void Bullet::update(float dt)
{
    _dt = dt;
     
}






















