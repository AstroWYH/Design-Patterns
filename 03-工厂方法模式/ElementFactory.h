#pragma once
#include "MonsterFactory.h"
#include "Element.h"
#include <memory>

using namespace std;

//这里的public继承非常重要，如果遗漏会导致外面的main函数无法正确执行
//shared_ptr<MonsterFactory> factory = make_shared<ElementFactory>();
class ElementFactory : public MonsterFactory {
public:
	ElementFactory() = default;
	virtual ~ElementFactory() {}

	virtual shared_ptr<Monster> CreateMonster() override {
		return make_shared<Element>(200, 80, 100);
	}
};