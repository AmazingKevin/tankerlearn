//
// Created by admin on 2018/12/28.
//

#include "MenuScene.h"
#include "SceneM.h"
#include "Global.h"
#include "DataM.h"

MenuScene::MenuScene():
_moveOver(false),
_option(ONE_PLAYER)
{
}
MenuScene::~MenuScene()
{
}
bool MenuScene::init()
{
    _bg = Sprite::create("menu.png");
    _bg->setAnchorPoint(CCPointZero);
    _bg->setPosition(Vec2(0, -SCREEN_HEIGHT));
    this->addChild(_bg);
    auto action = Sequence::create(
                     MoveBy::create(5.0f,Vec2(0,SCREEN_HEIGHT)),
                     CallFunc::create(CC_CALLBACK_0(MenuScene::moveOver, this)),
                     nullptr
    );
    _bg->runAction(action);
    
    auto hightScore = DataM::getInstance()->getHighScore();
    auto strHightScore = String::createWithFormat("%02d",hightScore)->getCString();
    auto hightScoreLabel = LabelAtlas::create(strHightScore,"num1.plist");
    hightScoreLabel->setAnchorPoint(Vec2(1.0f,0.5f));
    hightScoreLabel->setPosition(Vec2(329,425));
    _bg->addChild(hightScoreLabel);
    
    this->scheduleUpdate();


    return true;
}


void MenuScene::update(float dt)
{
    if(g_keyStart)
    {
        g_keyStart = false;
        if(_moveOver)
        {
            switch(_option)
            {
                case ONE_PLAYER:
                    this->removeAllChildren();
                    DataM::getInstance()->init();
                    SceneM::getInstance()->changeScene(kLevelScene,kTransitionExB);
                    break;
                default:
                    break;
            }
        }
        else//菜单移动中点击开始按键 会直接移动完毕
        {
            _bg->stopAllActions();
            _bg->setPosition(Vec2(0,0));
            this->moveOver();
        }
    }
    if (g_keySelect)
    {
        g_keySelect = false;
        if(_moveOver)
        {
            _option++;
            if(_option>2)
            {
                _option = 0;
            }
            this->setOption(_option);
        }
    }
    
    
    
}

void MenuScene::moveOver() {
    _moveOver = true;
    _tank = Sprite::createWithSpriteFrameName("player1_1_2_1.png");
    this->addChild(_tank);
    this->setOption(ONE_PLAYER);
    
    Vector<SpriteFrame*> animFrames(2);
    auto cache = SpriteFrameCache::getInstance();
    for (auto i = 1; i<3; i++) {
        auto animation = String::createWithFormat("player1_1_2%d.png",1)->getCString();
        auto frame = cache->getSpriteFrameByName(animation);
        animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames,0.01f);
    _tank->runAction(RepeatForever::create(Animate::create(animation)));
    
}

void MenuScene::setOption(int option)
{
    _option = option;
    auto x = 145.0f;
    auto y = 202.0f - option * 32.0f;
    _tank->setPosition(Vec2(x, y));
}


