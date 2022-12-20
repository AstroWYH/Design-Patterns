#pragma once
#include <memory>
#include "MonsterBuilder.h"
#include "Mechanic.h"
#include <iostream>
#include <string>

using namespace std;

class MechanicBuilder : public MonsterBuilder {
public:
	MechanicBuilder() {
		ptr_monster_ = make_shared<Mechanic>();
	}

	virtual void LoadTrunkModel(string name) {
		cout << "载入机械类躯干模型：" << name.substr(0, 2) << endl;
	}

	virtual void LoadHeadModel(string name) {
		cout << "载入机械类大脑模型：" << name.substr(3, 2) << endl;
	}

	virtual void LoadLimbsModel(string name) {
		cout << "载入机械类肢体模型：" << name.substr(6, 2) << endl;
	}
};
