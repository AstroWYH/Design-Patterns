#pragma once
#include "MonsterFactory.h"
#include "Undead.h"
#include <memory>

using namespace std;

//这里的public继承非常重要，如果遗漏会导致外面的main函数无法正确执行
//shared_ptr<MonsterFactory> factory = make_shared<UndeadFactory>();
class UndeadFactory : public MonsterFactory {
public:
	UndeadFactory() = default;
	virtual ~UndeadFactory() {}

	virtual shared_ptr<Monster> CreateMonster() override {
		return make_shared<Undead>(300, 50, 80);
	}
};