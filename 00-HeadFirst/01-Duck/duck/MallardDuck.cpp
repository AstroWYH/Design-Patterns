#include <iostream>
#include <memory>
#include "MallardDuck.h"
#include "FlyWithWings.h"
#include "QuackSqueak.h"

MallardDuck::MallardDuck() {
    fly_behavior_ = std::make_unique<FlyWithWings>();
    quack_behavior_ = std::make_unique<QuackSqueak>();
}

void MallardDuck::Display() {
    std::cout << "My name is MallardDuck!" << std::endl;
}
