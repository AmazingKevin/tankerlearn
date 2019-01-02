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
     if(GameScene::getGameState()==kPause) return;
    if(_visible)
    {
        this->move();
        this->collide();
    }
    if(_visible)
    {
        this->setPosition(_newPos);
    }
    else
    {
        if(_bomb)
        {
            GameScene::getBombM()->createBomb(kBulletBomb,_bombPos);
        }
        this->removeFromParent();
    }
}

void Bullet::move()
{
    if(_direction==UP)
    {
        _newPos.y = _position.y + _speed;
    }
    else if (_direction == DOWN)
    {
        //_newPos.y = _position.y - _speed * 60 * _dt;
        _newPos.y = _position.y - _speed;
    }
    else if (_direction == LEFT)
    {
        //_newPos.x = _position.x - _speed * 60 * _dt;
        _newPos.x = _position.x - _speed;
    }
    else if (_direction == RIGHT)
    {
        //_newPos.x = _position.x + _speed * 60 * _dt;
        _newPos.x = _position.x + _speed;
    }
}

void Bullet::collide()
{
    this->collideMap();			// 与地图的碰撞检测
    this->collideBullet();		// 与子弹的碰撞检测
    this->collideTank();		// 与坦克的碰撞检测
}
void Bullet::collideBullet() {
    auto &bullets = GameScene::getBulletM()->getChildren();





}































