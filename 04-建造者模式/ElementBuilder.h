#pragma once
#include <memory>
#include "MonsterBuilder.h"
#include "Element.h"
#include <iostream>
#include <string>

using namespace std;

class ElementBuilder : public MonsterBuilder {
public:
	ElementBuilder() {
		ptr_monster_ = make_shared<Element>();
	}

	virtual void LoadTrunkModel(string name) {
		cout << "载入精灵类躯干模型：" << name.substr(0, 2) << endl;
	}

	virtual void LoadHeadModel(string name) {
		cout << "载入精灵类大脑模型：" << name.substr(3, 2) << endl;
	}

	virtual void LoadLimbsModel(string name) {
		cout << "载入精灵类肢体模型：" << name.substr(6, 2) << endl;
	}
};
