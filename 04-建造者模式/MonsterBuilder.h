#pragma once
#include <string>
#include <memory>
#include "Monster.h"
using namespace std;

class MonsterBuilder {
public:
	virtual ~MonsterBuilder() {}
	virtual void LoadTrunkModel(string model_name) = 0;
	virtual void LoadHeadModel(string model_name) = 0;
	virtual void LoadLimbsModel(string model_name) = 0;

	void Assemble(string model_name) { // 未调用
		LoadTrunkModel(model_name.substr(0, 2));
		LoadHeadModel(model_name.substr(4, 5));
		LoadLimbsModel(model_name.substr(7, 8));
	}
	
	shared_ptr<Monster> GetResult() {
		return ptr_monster_;
	}

protected:
	shared_ptr<Monster> ptr_monster_;
};