//
// Created by admin on 2018/12/29.
//

#include "Joystick.h"
#include "Global.h"

enum KeyTag//虚拟手柄每个按键精灵tag
{
    kKeyUpTag,
    kKeyRightTag,
    kKeyDownTag,
    kKeyLeftTag,
    kKeySelectTag,
    kKeyStartTag,
    kKeyBTag,
    kKeyATag
};
Joystick::Joystick() {
    Scene::onEnter();
}
Joystick::~Joystick() {
    Scene::onExit();
}
bool Joystick::init()
{
    if(!Layer::init())
    {
        return false;
    }
    auto up = Sprite::create("key1.png");
    up->setOpacity(100);
    up->setPosition(90, 150);
    this->addChild(up, 0, kKeyUpTag);

    auto right = Sprite::create("key1.png");
    right->setOpacity(100);
    right->setRotation(90);
    right->setPosition(150, 90);
    this->addChild(right, 0, kKeyRightTag);

    auto down = Sprite::create("key1.png");
    down->setOpacity(100);
    down->setRotation(180);
    down->setPosition(90, 30);
    this->addChild(down, 0, kKeyDownTag);

    auto left = Sprite::create("key1.png");
    left->setOpacity(100);
    left->setRotation(270);
    left->setPosition(30, 90);
    this->addChild(left, 0, kKeyLeftTag);

    auto select = Sprite::create("key2.png");
    select->setOpacity(100);
    select->setPosition(SCREEN_CX - 35, 23);
    this->addChild(select, 0, kKeySelectTag);

    auto start = Sprite::create("key2.png");
    start->setOpacity(100);
    start->setPosition(SCREEN_CX + 35, 23);
    this->addChild(start, 0, kKeyStartTag);

    auto b = Sprite::create("key3.png");
    b->setOpacity(100);
    b->setPosition(SCREEN_WIDTH - 135, 40);
    this->addChild(b, 0, kKeyBTag);

    auto a = Sprite::create("key4.png");
    a->setOpacity(100);
    a->setPosition(SCREEN_WIDTH - 45, 40);
    this->addChild(a, 0, kKeyATag);

    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [=](Touch * touch,Event * event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        this->setTouch(target,touch->getLocation(), true);
        return true;
    };
    listener->onTouchEnded = [=](Touch* touch,Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        this->setTouch(target,touch->getStartLocation(),false);
    };
    listener->onTouchCancelled = listener->onTouchEnded;
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

    auto keyboardEventListener = EventListenerKeyboard::create();
    keyboardEventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
        this->setKeyState(keyCode, true);
    };
    keyboardEventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
        this->setKeyState(keyCode, false);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardEventListener, this);





    return true;
}

void Joystick::setTouch(Sprite *target, Vec2 location, bool state) {

    auto locationInNode = target->convertToNodeSpace(location);
    for(auto child :this->getChildren())
    {
        if(child->getBoundingBox().containsPoint(locationInNode))
        {
            auto tag = child->getTag();
            switch (tag)
            {
                case kKeyUpTag:
                    g_keyUp = state;
                    break;
                case kKeyRightTag:
                    g_keyRight = state;
                    break;
                case kKeyDownTag:
                    g_keyDown = state;
                    break;
                case kKeyLeftTag:
                    g_keyLeft = state;
                    break;
                case kKeySelectTag:
                    g_keySelect = state;
                    break;
                case kKeyStartTag:
                    g_keyStart = state;
                    break;
                case kKeyBTag:
                    g_keyB = state;
                    break;
                case kKeyATag:
                    g_keyA = state;
                    break;
                default:
                    break;
            }

        }

    }

}

void Joystick::setKeyState(EventKeyboard::KeyCode keyCode,bool state)
{
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_W:
            g_keyUp = state;
            break;
        case EventKeyboard::KeyCode::KEY_S:
            g_keyDown = state;
            break;
        case EventKeyboard::KeyCode::KEY_A:
            g_keyLeft = state;
            break;
        case EventKeyboard::KeyCode::KEY_D:
            g_keyRight = state;
            break;
        case EventKeyboard::KeyCode::KEY_V:
            g_keySelect = state;
            break;
        case EventKeyboard::KeyCode::KEY_B:
            g_keyStart = state;
            break;
        case EventKeyboard::KeyCode::KEY_J:
            g_keyB = state;
            break;
        case EventKeyboard::KeyCode::KEY_K:
            g_keyA = state;
            break;
        default:
            break;
    }

}


































