//
//  TankM.hpp
//  tanker-mobile
//
//  Created by Jinlong Wu on 2019/1/1.
//

#ifndef TankM_hpp
#define TankM_hpp

#include "cocos2d.h"
#include "Global.h"
#include "PlayerTank.hpp"
#include "EnemyTank.hpp"
USING_NS_CC;
using namespace std;
class TankM:public Layer
{
public:
    TankM();
    ~TankM();
    CREATE_FUNC(TankM);
    bool init();
    PlayerTank* getPlayerTank(){return _playerTank;}
    Vector<EnemyTank*> getEnemyTanks(){ return _enemyTanks;}
    Vector<Tank*>& getAllTanks(){return _tanks;}
    void removeTank(Tank* tank,bool addScore = false);
    int * getkillEnemyNum(){return _killEnemyNum;}
    void playerBombEnd();
    void fail();
    void killAllEnemy();
    void setHaltEnemy();
    /* 暂停游戏 */
    void pauseGame();
    /* 继续游戏 */
    void resumeGame();
    /* 播放敌人坦克行走音效 */
    void playEnemyMoveAudio();
    /* 停止敌人坦克行走音效 */
    void stopEnemyMoveAudio();


private:
    void timer(float dt);//定时器
    Sprite* createBore(const function<void(Node*)> callback);//创造坦克出现闪光点
    void createNewPlayer();
    void createNewEnemy();
    void startAudioEnd(Ref* obj);
    int _pos;

    bool _allApear;
    PlayerTank* _playerTank;
    Vector<EnemyTank*> _enemyTanks;
    Vector<Tank*> _tanks;//
    int _killEnemyNum[5];
    bool halt;
    int _enemyMoveAudioId;
};













#endif /* TankM_hpp */
