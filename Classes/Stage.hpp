//
//  Stage.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2018/12/30.
//

#ifndef Stage_hpp
#define Stage_hpp

#include "Global.h"
#include "Score.h"
#include "cocos2d.h"
USING_NS_CC;
enum{
    LAND,//地
    BRICK,//砖
    GRID,
    GRASS,
    WATER,
    ICE,
    HOME1,
    HOME2,
    HOME3,
    HOME4
}
class Stage:public LayerColor
{
public:
    Stage();
    ~Stage();
    CREATE_FUNC(Stage);
    virtual bool init();
    LayerColor* getBG(){return _bg;}
    void initInfo();
    void getMap(int (*&map)[MAP_COL]){ map = _map;};
    bool isCanHit(int row,int col);
    bool isCanWalk(int row,int col);
    bool isOnIce(Vec2 pos);
    /*更新剩余坦克数量*/
    void updateEnemyNum();
    
    
    
    
}





#endif /* Stage_hpp */
