//
// Created by admin on 2018/12/29.
//

#include "DataM.h"
#include "Global.h"
#include "GameScene.h"

static DataM * s_ShareDataM = nullptr;
DataM::DataM():_levelId(1),_highScore(20000),_score(0),_playerLife(PLAYER_LIFE),_playerLevel(PLAYER_INIT_LEVEL)
{}
DataM::~DataM()
{
}
DataM* DataM::getInstance() {
    if(!s_ShareDataM)
    {
        s_ShareDataM = new (std::nothrow)DataM();
        CCASSERT(s_ShareDataM, "FATAL: Not enough memory");
        s_ShareDataM->init();
    }

    return s_ShareDataM;
}

bool DataM::init() {

    _selectLevelEnable = true;
    _score = 0;
    _levelId = 1;
    _playerLife = PLAYER_LIFE;
    _playerLevel = PLAYER_INIT_LEVEL;

    while (!_addLifeScore.empty())_addLifeScore.pop();
    for (auto score : ADD_LIFE_SCORE)
    {
        _addLifeScore.push(score);
    }


    return true;
}

void DataM::addScore(int score)
{
    _score += score;
    if (!_addLifeScore.empty() && _score >= _addLifeScore.top())
    {
        _addLifeScore.pop();
        // GameScene::getTankM()->getPlayerTank()->addLife();
    }
}