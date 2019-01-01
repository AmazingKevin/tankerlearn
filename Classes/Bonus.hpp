//
//  Bonus.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#ifndef Bonus_hpp
#define Bonus_hpp

#include "cocos2d.h"
USING_NS_CC;
enum BonusType
{
  kTank = 1,
    kTime,
    kShovel,
    kBomb,
    kStar,
    kHelmet
};
class Bonus: public Sprite
{
public:
    Bonus();
    ~Bonus();
    static Bonus* create(BonusType type);
    bool init(BonusType type);
private:
    void update(float dt);
    bool isCollidePlayer();
    BonusType _type;
    
};

























#endif /* Bonus_hpp */
