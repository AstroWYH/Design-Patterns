#pragma once
#include <memory>
#include <string>
#include "Monster.h"
#include "MonsterBuilder.h"

using namespace std;

class MonsterDirector {
public:
	MonsterDirector(shared_ptr<MonsterBuilder> builder) {
		builder_ = builder;
	}

	void SetBuilder(shared_ptr<MonsterBuilder> builder) {
		builder_ = builder;
	}

	shared_ptr<Monster> Construct(string model_name) {
		builder_->LoadTrunkModel(model_name);
		builder_->LoadHeadModel(model_name);
		builder_->LoadLimbsModel(model_name);
		return builder_->GetResult();
	}

private:
	shared_ptr<MonsterBuilder> builder_;
};