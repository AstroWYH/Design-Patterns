#pragma once

class Monster {
public:
    Monster() = default;
    Monster(int life, int magic, int attack) : life_(life), magic_(magic), attack_(attack) {}
    virtual ~Monster() {}

private:
    int life_ = 500;
    int magic_ = 300;
    int attack_ = 80;
};