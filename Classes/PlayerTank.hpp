//
//  PlayerTank.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#ifndef PlayerTank_hpp
#define PlayerTank_hpp
#include "cocos2d.h"
#include "Tank.hpp"
USING_NS_CC;

class PlayerTank:public Tank
{
public:
    PlayerTank();
    ~PlayerTank();
    static PlayerTank * create(int type);
    bool init(int type);
    void initPos();
    virtual void hit();
    bool isShield(){return _shield!=nullptr;}
    void setShield(float time = 10.0f);
    int getLife(){return _life;}
    int getLevel(){return _level;}
    void addLife();
    void addLevel();
    void pauseGame();
    void resumeGame();
    void playMoveAudio();
    void stopMoveAudio();
    
    
private:
    void update(float dt);
    void setLevel(int level);
    void trackSlip();//冰上打滑
    Sprite* _shield;//保护盾
    float _shootInterverval;//两次子弹间隔
    int _life;//生命数
    int _inertia;//冰上打滑
    bool _move;//是否行走
    int _moveAudioId;//行走音效
    
    
};


















#endif /* PlayerTank_hpp */
