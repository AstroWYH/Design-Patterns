#include <iostream>
#include "Duck.h"

void Duck::Swim() {
    std::cout << "I can swim!" << std::endl;
}

void Duck::Display() {
    std::cout << "My name is Duck!" << std::endl;
}

void Duck::PerformFly() {
    fly_behavior_->Fly();
}

void Duck::PerformQuack() {
    quack_behavior_->Quack();
}
