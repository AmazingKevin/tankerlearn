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
MenuScene::init()
{
    _bg = Sprite::create("menu.png");
    _bg->setAnchorPoint(CCPointZero);
    _bg->setPosition(Vec2(0, -SCREEN_HEIGHT));
    this->addChild(_bg);


    return true;
}

void MenuScene::moveOver() {
    _moveOver = true;
    _tank = Sprite::createWithSpriteFrameName("player1_1_2_1.png");
    this->addChild(_tank);
    this->setOption(ONE_PLAYER);
}

void MenuScene::setOption(int option)
{
    _option = option;
    auto x = 145.0f;
    auto y = 202.0f - option * 32.0f;
    _tank->setPosition(Vec2(x, y));
}


