#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <utility>
#include "Notifier.h"
#include "Warrior.h"
#include "Mage.h"

using namespace std;

class TalkNotifier : public Notifier {
public:
	virtual void AddToList(shared_ptr<Fighter> player) {
		int family_id = player->GetFamilyId();
		if (family_id != -1) {
			// 该玩家已加入过家族
			auto iter = family_list_.find(family_id);
			if (iter != family_list_.end()) {
				// 该家族id在map中已存在
				iter->second.push_back(player);
			} else {
				// 该家族id在map中不存在
				list<shared_ptr<Fighter>> player_list;
				player_list.push_back(player);
				family_list_.insert(make_pair(family_id, player_list));
			}
		}
	}

	virtual void RemoveFromList(shared_ptr<Fighter> player) {
		int family_id = player->GetFamilyId();
		if (family_id != -1) {
			// 该player加入了某个家族
			auto iter = family_list_.find(family_id);
			if (iter != family_list_.end()) {
				// 该家族id在map中存在
				family_list_[family_id].remove(player);
			}
		}
	}

	virtual void Notify(shared_ptr<Fighter> talker, string content) {
		// 查询该talker的family id
		int family_id = talker->GetFamilyId();
		if (family_id != -1) {
			auto iter_map = family_list_.find(family_id);
			if (iter_map != family_list_.end()) {
				// 通知该talker的family内的所有成员
				for (auto iter_list = iter_map->second.begin(); iter_list != iter_map->second.end(); iter_list++) {
					(*iter_list)->NotifyWords(talker, content);
				}
			}
		}
	}

private:
	map<int, list<shared_ptr<Fighter>>> family_list_;
};