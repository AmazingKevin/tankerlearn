//
//  Tank.cpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#include "Tank.hpp"
#include "GameScene.h"
#include <vector>
Tank::Tank():
_bomb(false),
_onIce(false),
_step(0),
_dt(0)
{
}
Tank::~Tank()
{
}
bool Tank::init(int type)
{
    _type = type;
    return true;
}































