#pragma once
#include "FlyBehavior.h"

class FlyNoWay : public FlyBehavior {
public:
    virtual void Fly() override;
};