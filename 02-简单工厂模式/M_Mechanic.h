#pragma once
#include "Monster.h"
#include "stdio.h"

class M_Mechanic : public Monster {
public:
    M_Mechanic() = default;
    M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack) {
        printf("一只机械怪物诞生~\n");
    }
};