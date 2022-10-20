#include <stdio.h>
#include "Fighter.h" // 注意，不能写成#include <Fighter.h>，会从系统路径找，导致找不到。

// 模板方法模式的核心在于此，Burn是父类函数，且不是虚函数，但其内调用的都是子类的函数，需要其内的函数比较固定，
// 是一个相对稳定的结构，这就是“模板方法”的由来。
void Fighter::Burn() {
    EffectEnemy();
    EffectSelf();
    Show();
}

void Fighter::EffectEnemy() {}

void Fighter::EffectSelf() {}

void Fighter::Show() {
    printf("Fighter 施放技能\n");
}