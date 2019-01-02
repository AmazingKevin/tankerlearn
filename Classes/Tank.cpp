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
void Tank::setPos(Vec2 pos, Direction direction)
{
    _direction = direction;
    this->setPosition(pos);
    _newPos = pos;
    _step = 0;
}
void Tank::moveUp()
{
    _newPos.y = _position.y + _speed;
    this->addStep();
}
void Tank::moveDown()
{
    _newPos.y = _position.y-_speed;
    this->addStep();
}
void Tank::moveLeft()
{
    _newPos.x = _position.x- _speed;
    this->addStep();
}
void Tank::moveRight()
{
    _newPos.x = _position.x + _speed;
    this->addStep();
}

void Tank::turnLeft()
{
    if(_direction==UP||_direction==DOWN)
        adjustPosY();
    _direction = LEFT;
}

void Tank::turnRight()
{
    if(_direction==UP||_direction==DOWN)
        adjustPosY();
    _direction = RIGHT;
}
void Tank::turnUp()
{
    if(_direction==RIGHT||_direction==LEFT)
        adjustPosX();
    _direction = UP;
}
void Tank::turnDown()
{
    if(_direction==RIGHT || _direction==LEFT)
        adjustPosX();
    _direction = DOWN;
}

void Tank::adjustPosX()
{
   auto n =  _position.x /CELL_WIDTH;
   if((int)(n*10)%10 <4 )
   {
       _newPos.x = (int)n*CELL_WIDTH;
   }
   else
   {
       _newPos.x = (int)(n+1)*CELL_WIDTH;
   }
    this->setPositionX(_newPos.x);
}
void Tank::adjustPosY()
{
    auto n =  _position.y /CELL_HEIGHT;
    if((int)(n*10)%10 <4 )
    {
        _newPos.y = (int)n*CELL_HEIGHT;
    }
    else
    {
        _newPos.y = (int)(n+1)*CELL_HEIGHT;
    }
    this->setPositionY(_newPos.y);
}
bool Tank::shoot()
{
    bool isShoot = false;
    Vec2 bulletPos;

    
    
    return isShoot;
}



































