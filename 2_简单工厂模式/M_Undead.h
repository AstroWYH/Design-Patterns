#pragma once
#include "Monster.h"
#include "stdio.h"

class M_Undead : public Monster {
public:
    M_Undead() = default;
    M_Undead(int life, int magic, int attack) : Monster(life, magic, attack) {
        printf("一只亡灵怪物诞生~\n");
    }
};