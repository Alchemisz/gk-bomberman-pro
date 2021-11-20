#pragma once
#include "GameObject.h"
class UpdatableObject :
    public GameObject
{
    virtual void update();
};

