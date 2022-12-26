#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "Fighter.h"

using namespace std;

class Warrior : public Fighter {
public:
	Warrior(int id, string name) : Fighter(id, name) {}
};