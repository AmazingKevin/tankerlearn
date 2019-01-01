//
//  EnemyTank.cpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#include "EnemyTank.hpp"
#include "GameScene.h"
#include "AudioM.h"
#include "Global.h"

EnemyTank::EnemyTank():
_addScore(false),
_bonus(false),
_bonusStep(0)
{
    
}

EnemyTank::~EnemyTank()
{
}

EnemyTank* EnemyTank::create(int type, Vec2 pos)
{
    EnemyTank *pRet = new EnemyTank();
    if(pRet && pRet->init(type, pos))
    {
        pRet->autorelease();
        return pRet;
    }else{
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}







































