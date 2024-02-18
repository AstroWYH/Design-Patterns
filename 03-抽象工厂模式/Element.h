#pragma once
#include "Monster.h"
#include "stdio.h"

class Element : public Monster {
public:
    Element() = default;
    Element(int life, int magic, int attack) : Monster(life, magic, attack) {
        printf("一只精灵怪物诞生~\n");
    }
};