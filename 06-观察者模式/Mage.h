#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "Fighter.h"

using namespace std;

class Mage : public Fighter {
public:
	Mage(int id, string name) : Fighter(id, name) {}
};