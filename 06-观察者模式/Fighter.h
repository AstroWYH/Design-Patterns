#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "Notifier.h"

using namespace std;

class Fighter : public enable_shared_from_this<Fighter> { // 对于this取shared_ptr的写法，多态也能适用
public:
	Fighter(int id, string name) : player_id_(id), player_name_(name) {}
	virtual ~Fighter() {}

	void SetFamilyId(int id) {
		family_id_ = id;
	}

	int GetFamilyId() {
		return family_id_;
	}

	void SayWords(shared_ptr<Notifier> notifier, string content) {
		notifier->Notify(shared_from_this(), content); // 对于this取shared_ptr的写法，多态也能适用
	}

	virtual void NotifyWords(shared_ptr<Fighter> talker, string content) {
		cout << "玩家：" << player_name_ << " 收到了 玩家：" << talker->player_name_ << " 发送的信息：" << content << endl;
	}

private:
	int player_id_ = -1;
	int family_id_ = -1;
	string player_name_;
};