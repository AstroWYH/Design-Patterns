#pragma once
#include "Monster.h"
#include "stdio.h"

class M_Element : public Monster {
public:
    M_Element() = default;
    M_Element(int life, int magic, int attack) : Monster(life, magic, attack) {
        printf("一只精灵怪物诞生~\n");
    }
};