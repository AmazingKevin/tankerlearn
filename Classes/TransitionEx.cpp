//
// Created by admin on 2018/12/28.
//

#include "TransitionEx.h"
SplitExA* SplitExA::create(float duration)
{
    SplitExA *action = new (std::nothrow) SplitExA();

    if (action)
    {
        if (action->initWithDuration(duration))
        {
            action->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(action);
        }
    }

    return action;
}
bool SplitExA::initWithDuration(float duration)
{
    return TiledGrid3DAction::initWithDuration(duration, Size(1, 2));
}





























