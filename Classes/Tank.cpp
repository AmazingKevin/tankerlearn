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
    auto bulletNum = GameScene::getBulletM()->getBulletNum(this);
    if (bulletNum < _bulletNumMax)
    {
        if (_direction == UP)
        {
            bulletPos.x = _position.x;
            bulletPos.y = _position.y + CELL_HEIGHT;
        }
        else if (_direction == DOWN)
        {
            bulletPos.x = _position.x;
            bulletPos.y = _position.y - CELL_HEIGHT;
        }
        else if (_direction == LEFT)
        {
            bulletPos.x = _position.x - CELL_WIDTH;
            bulletPos.y = _position.y;
        }
        else if (_direction == RIGHT)
        {
            bulletPos.x = _position.x + CELL_WIDTH;
            bulletPos.y = _position.y;
        }
        GameScene::getBulletM()->createBullet(this, _bulletSpeed, _bulletPower, bulletPos, _direction);
        isShoot = true;
    }
    return isShoot;
}
void Tank::addStep()
{
    _step++;
    if (_step >= _stepMax)
    {
        _step = 0;
    }
}

bool Tank::collide(){
    auto collide = false;
    if (collideMap())
    {
        collide = true;
    }
    if (collideTank())
    {
        collide = true;
    }
    this->setPosition(_newPos);
    return collide;
}

bool Tank::collideTank()
{
    auto collide = false;
    auto &tanks =  GameScene::getTankM()->getAllTanks();
    for(auto i = 0; i < tanks.size(); i++)
    {
        auto tank = tanks.at(i);
        if (tank == this) continue;
        auto otherPos = tank->getPosition();
        if (_newPos.x > otherPos.x - 2 * CELL_WIDTH && _newPos.x < otherPos.x + 2 * CELL_WIDTH)
        {
            if (_position.y >= otherPos.y + 2 * CELL_HEIGHT && _newPos.y < otherPos.y + 2 * CELL_HEIGHT)
            {
                _newPos.y = otherPos.y + 2 * CELL_HEIGHT;
                collide = true;
            }
            if (_position.y <= otherPos.y - 2 * CELL_HEIGHT && _newPos.y > otherPos.y - 2 * CELL_HEIGHT)
            {
                _newPos.y = otherPos.y - 2 * CELL_HEIGHT;
                collide = true;
            }
        }
        if (_newPos.y > otherPos.y - 2 * CELL_HEIGHT && _newPos.y < otherPos.y + 2 * CELL_HEIGHT)
        {
            if (_position.x >= otherPos.x + 2 * CELL_WIDTH && _newPos.x < otherPos.x + 2 * CELL_WIDTH)
            {
                _newPos.x = otherPos.x + 2 * CELL_WIDTH;
                collide = true;
            }

            if (_position.x <= otherPos.x - 2 * CELL_WIDTH && _newPos.x > otherPos.x - 2 * CELL_WIDTH)
            {
                _newPos.x = otherPos.x - 2 * CELL_WIDTH;
                collide = true;
            }
        }
    }
    return collide;
}


bool Tank::collideMap()
{
    int row, col;
    auto collide = false;
    auto stage = GameScene::getStage();
    if (_direction == UP)
    {
        col = (int)(_newPos.x / CELL_WIDTH);
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT) - 1;
        if (row < 0 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row, col - 1))
        {
            _newPos.y = (MAP_ROW - row - 2) * CELL_HEIGHT;
            collide = true;
        }
    }
    else if (_direction == DOWN)
    {
        col = (int)(_newPos.x / CELL_WIDTH);
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT) + 1;
        if (row > MAP_ROW - 1 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row, col - 1))
        {
            _newPos.y = (MAP_ROW - row + 1) * CELL_HEIGHT;
            collide = true;
        }
    }
    else if (_direction == LEFT)
    {
        col = (int)(_newPos.x / CELL_WIDTH) - 1;
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT);
        if (col < 0 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row - 1, col))
        {
            _newPos.x = (col + 2) * CELL_WIDTH;
            collide = true;
        }
    }
    else if (_direction == RIGHT)
    {
        col = (int)(_newPos.x / CELL_WIDTH) + 1;
        row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT);
        if (col > MAP_COL - 1 || !stage->isCanWalk(row, col) || !stage->isCanWalk(row - 1, col))
        {
            _newPos.x = (col - 1) * CELL_WIDTH;
            collide = true;
        }
    }
    return collide;
}
































