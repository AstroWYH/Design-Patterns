#pragma once
#include "MonsterFactory.h"
#include "Mechanic.h"
#include <memory>

using namespace std;

//这里的public继承非常重要，如果遗漏会导致外面的main函数无法正确执行
//shared_ptr<MonsterFactory> factory = make_shared<MechanicFactory>();
class MechanicFactory : public MonsterFactory {
public:
	MechanicFactory() = default;
	virtual ~MechanicFactory() {}

	virtual shared_ptr<Monster> CreateMonster() override {
		return make_shared<Mechanic>(400, 0, 110);
	}
};