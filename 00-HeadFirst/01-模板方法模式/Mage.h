#pragma once
#include "Fighter.h"

class Mage : public Fighter {
public:
    Mage() = default;
    Mage(int life, int magic, int attack) : Fighter(life, magic, attack) {}
private:
    virtual void EffectEnemy();
    virtual void EffectSelf();
};