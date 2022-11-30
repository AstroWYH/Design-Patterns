#pragma once
#include "Monster.h"

class MonsterFactory {
public:
	MonsterFactory() = default;
	virtual ~MonsterFactory() {}

	virtual shared_ptr<Monster> CreateMonster() = 0;
};