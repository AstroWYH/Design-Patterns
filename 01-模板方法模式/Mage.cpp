#include"Mage.h"
#include<stdio.h>

void Mage::EffectEnemy() {
    printf("Mage 影响敌人\n");
    magic_ -= 20;
}

void Mage::EffectSelf() {
    printf("Mage 影响自己\n");
    life_ -= 100;
}