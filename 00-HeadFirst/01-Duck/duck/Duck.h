#pragma once
#include <memory>
#include "FlyBehavior.h";
#include "QuackBehavior.h";

class Duck {
public:
    virtual void Swim();
    virtual void Display();

    void PerformFly();
    void PerformQuack();

    std::unique_ptr<FlyBehavior> fly_behavior_;
    std::unique_ptr<QuackBehavior> quack_behavior_;
};