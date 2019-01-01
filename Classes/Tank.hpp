//
//  Tank.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#ifndef Tank_hpp
#define Tank_hpp

#include "cocos2d.h"
#include "Global.h"
USING_NS_CC;
class Tank:public Sprite
{
public:
    Tank();
    ~Tank();
    virtual bool init(int type);
    int getType(){return _type;};
    virtual void hit() = 0 ;
protected:
    void initPos();
    void setPos(Vec2 pos,Direction direction);
    void moveUp();
    void moveRight();
    void moveLeft();
    void moveDown();
    void turnRight();
    void turnLeft();
    void turnUp();
    void turnDown();
    void adjustPosX();
    void adjustPosY();
    bool shoot();
    void addStep();
    bool collide();
    bool collideTank();
    bool collideMap();
    bool overlapCheck();//监测是否与其他坦克重叠
    
    
    
    
    bool _bomb;
    Vec2 _newPos;
    int _step;
    int _stepMax;
    float _speed;
    int _level;
    int _type;
    Direction _direction;
    int _bulletPower;
    float _bulletSpeed;
    int _bulletNumMax;
    bool _onIce;
    float _dt;
    
};


#endif /* Tank_hpp */
