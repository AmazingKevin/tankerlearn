//
//  Bullet.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include "cocos2d.h"
#include "Global.h"
USING_NS_CC;
class Bullet :public Sprite
{
public:
    Bullet();
    ~Bullet();
    static Bullet* create(void* owner,float speed,int power,Vec2 pos,Direction direction);
    bool init(void* owner,float speed,int power,Vec2 pos,Direction direction);
    void* getOwner(){return _owner;}
private:
    void update(float dt);
    void move();
    void collide();//碰撞检测
    void collideMap();//与地图边界以及障碍物检测
    void collideBorder();//与地图
    void collideObstacle();
    void collideBullet();
    void collideTank();
    
    void* _owner;//发出该子弹的坦克
    float _speed;//子弹的速度
    int _power;//子弹的强度(0不能打铁,1可以打铁)
    Vec2 _newPos;//子弹下一帧位置
    Direction _direction;//子弹的方向
    Vec2 _bombPos;//子弹爆炸的位置
    bool _bomb;//子弹是否爆炸
    float _dt;//两帧之间的时间间隔
};











#endif /* Bullet_hpp */
