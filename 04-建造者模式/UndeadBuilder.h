#pragma once
#include <memory>
#include "MonsterBuilder.h"
#include "Undead.h"
#include <iostream>
#include <string>

using namespace std;

class UndeadBuilder : public MonsterBuilder {
public:
	UndeadBuilder() {
		ptr_monster_ = make_shared<Undead>();
	}

	virtual void LoadTrunkModel(string name) {
		cout << "载入亡灵类躯干模型：" << name.substr(0, 2) << endl;
	}

	virtual void LoadHeadModel(string name) {
		cout << "载入亡灵类大脑模型：" << name.substr(3, 2) << endl;
	}

	virtual void LoadLimbsModel(string name) {
		cout << "载入亡灵类肢体模型：" << name.substr(6, 2) << endl;
	}
};