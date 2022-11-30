#pragma once
#include "Monster.h"
#include "stdio.h"

class Mechanic : public Monster {
public:
    Mechanic() = default;
    Mechanic(int life, int magic, int attack) : Monster(life, magic, attack) {
        printf("一只机械怪物诞生~\n");
    }
};