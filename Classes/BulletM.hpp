//
//  BulletM.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#ifndef BulletM_hpp
#define BulletM_hpp

#include "cocos2d.h"
#include "Bullet.hpp"
class BulletM:public Scene{
public:
    BulletM();
    ~BulletM();
    CREATE_FUNC(BulletM);
    bool init();
    /* 获取该坦克发射的子弹数目 */
    int getBulletNum(void* owner);
    /**
     * 创建子弹
     * owner 子弹所属的坦克
     * speed 子弹速度
     * power 子弹力量 0不可打破铁，可打破半块砖；1可打破铁，可打破整块砖
     * pos 子弹位置
     * direction 子弹方向
     */
    void createBullet(void* owner, float speed, int power, Vec2 pos, Direction direction);

};




















#endif /* BulletM_hpp */
