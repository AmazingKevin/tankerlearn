//
//  EnemyTank.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#ifndef EnemyTank_hpp
#define EnemyTank_hpp

#include "Tank.hpp"
class EnemyTank:public Tank
{
public:
    EnemyTank();
    ~EnemyTank();
    static EnemyTank* create(int type,Vec2 pos);
    bool init(int type,Vec2 pos);
    virtual void hit();
    void die();
    void setBonus();
    void cancelBonus();
private:
    void update(float dt);
    
    bool _addScore;
    bool _bonus;
    bool _bonusStep;
};



#endif /* EnemyTank_hpp */
