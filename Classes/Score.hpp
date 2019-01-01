//
//  Score.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2018/12/30.
//

#ifndef Score_hpp
#define Score_hpp
#include "cocos2d.h"
USING_NS_CC;
class Score:public Scene
{
public:
    Score();
    ~Score();
    CREATE_FUNC(Score);
    virtual bool init(); void setCallBack(const std::function<void()> callback);
private:
    void count(float dt);
    int _step;
    int _countNum;
    int _countScore;
    int _killEnemyNum[5];
    LabelAtlas* _numLabel;
    LabelAtlas* _scoreLabel;
    std::function<void()> _callback;
    
    
};

#endif /* Score_hpp */
