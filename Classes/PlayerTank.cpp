//
//  PlayerTank.cpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#include "PlayerTank.hpp"
#include "Global.h"
#include "GameScene.h"
#include "DataM.h"
#include "AudioM.h"

PlayerTank::PlayerTank():
_shield(nullptr),
_shootInterverval(0.0f),
_move(false)
{
    _stepMax = 2;
}

PlayerTank::~PlayerTank()
{
}

PlayerTank* PlayerTank::create(int type)
{
    PlayerTank *pRet = new PlayerTank();
    if(pRet && pRet->init(type))
    {
        pRet->autorelease();
        return pRet;
    }
    else{
        delete pRet;
        pRet = NULL;
        return NULL;
    }
};

bool PlayerTank::init(int type)
{
    _type = type;
    _life = DataM::getInstance()->getPlayerLife();
    this->initWithSpriteFrameName("player1_1_1_1.png");
    this->initPos();
    this->setLevel(DataM::getInstance()->getPlayerLevel());
    this->setShield(2.5f);
    this->scheduleUpdate();
    
    
    return true;
}

void PlayerTank::update(float dt)
{
    _dt = dt;
     
    
}
















































