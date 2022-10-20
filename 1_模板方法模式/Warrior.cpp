#include"Warrior.h"
#include<stdio.h>

void Warrior::EffectEnemy() {
    printf("Warrior 影响敌人\n");
}

void Warrior::EffectSelf() {
    printf("Warrior 影响自己\n");
    life_-=300;
}