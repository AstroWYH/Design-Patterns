#pragma once
#include <memory>

class FlyBehavior;
class QuackBehavior;

class Duck {
public:
    virtual void Swim();
    virtual void Display();

    void PerformFly();
    void PerformQuack();

    std::unique_ptr<FlyBehavior> fly_behavior_;
    std::unique_ptr<QuackBehavior> quack_behavior_;
};