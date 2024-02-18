#pragma once
#include "Fighter.h"

class Warrior : public Fighter {
public:
    // 注意：这里Warrior由于自定义了带参构造函数，所以如果还想要无参构造，有两种方法：
    // 1) Warrior() : Fighter() {}; // 不能是Warrior() {}，因为需要父类帮忙初始化成员。
    // 2) Warrior() = default; // 编译器自动生成，无视需父类构造。
    Warrior() : Fighter() {};
    Warrior(int life, int magic, int attack) : Fighter(life, magic, attack) {}
private:
    virtual void EffectEnemy();
    virtual void EffectSelf();
};