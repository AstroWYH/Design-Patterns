#pragma once
#include "Monster.h"
#include "stdio.h"

class Undead : public Monster {
public:
    Undead() = default;
    Undead(int life, int magic, int attack) : Monster(life, magic, attack) {
        printf("一只亡灵怪物诞生~\n");
    }
};