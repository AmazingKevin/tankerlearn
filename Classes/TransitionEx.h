//
// Created by admin on 2018/12/28.
//

#ifndef PROJ_ANDROID_TRANSITIONEX_H
#define PROJ_ANDROID_TRANSITIONEX_H

#include "cocos2d.h"
USING_NS_CC;
class SplitExA:public TiledGrid3DAction
{
public:
    static SplitExA* create(float duration);
    virtual SplitExA* clone() const override ;
    virtual void update(float time) override ;
    virtual void startWithTarget(Node* target)override ;
    CC_CONSTRUCTOR_ACCESS:
    SplitExA(){};
    virtual ~SplitExA(){};
    bool initWithDuration(float duration);

protected:
    Size _winSize;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(SplitExA);

};


class SplitExB : public TiledGrid3DAction
{
public:

    static SplitExB* create(float duration);

    virtual SplitExB* clone() const override;
    virtual void update(float time) override;
    virtual void startWithTarget(Node *target) override;

CC_CONSTRUCTOR_ACCESS:
    SplitExB() {}
    virtual ~SplitExB() {}

    bool initWithDuration(float duration);

protected:
    Size _winSize;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(SplitExB);
};

class TransitionExA : public TransitionScene
{
public:
    static TransitionExA* create(float t, Scene* scene);
    virtual ActionInterval* action();

    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionExA();
    virtual ~TransitionExA();

protected:
    NodeGrid* _outSceneProxy;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionExA);
};

class TransitionExB : public TransitionScene
{
public:

    static TransitionExB* create(float t, Scene* scene);

    virtual ActionInterval* action();
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionExB();
    virtual ~TransitionExB();

protected:
    NodeGrid* _inSceneProxy;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionExB);
};















#endif //PROJ_ANDROID_TRANSITIONEX_H
