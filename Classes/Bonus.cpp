//
//  Bonus.cpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#include "Bonus.hpp"
#include "Global.h"
#include "GameScene.h"
#include "AudioM.h"

Bonus::Bonus()
{
}
Bonus::~Bonus()
{
}
Bonus* Bonus::create(BonusType type)
{
    Bonus * pRet = new Bonus();
    if(pRet && pRet->init(type))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
bool Bonus::init(BonusType type)
{
    _type = type;
    this->initWithSpriteFrameName(String::createWithFormat("bonus_%02d.png",_type)->getCString());
    int row,col;
    
    row = rand()%20 + 3;
    col = rand()%24 + 1;
    
}


























bool Bonus::isCollidePlayer()
{
    
    return true;
    
}










