#include <iostream>
#include <memory>
#include "MallardDuck.h"

int main() {
    std::unique_ptr<Duck> mallard_duck = std::make_unique<MallardDuck>();
    mallard_duck->Swim();
    mallard_duck->Display();
    mallard_duck->PerformFly();
    mallard_duck->PerformQuack();
    return 0;
}