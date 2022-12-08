#pragma once
#include "Monster.h"
#include <memory>

using namespace std;

class MonsterFactory {
public:
	MonsterFactory() = default;
	virtual ~MonsterFactory() {}

	virtual shared_ptr<Monster> CreateMonster() = 0;
};