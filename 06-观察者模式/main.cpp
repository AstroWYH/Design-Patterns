#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <utility>
#include "TalkNotifier.h"
#include "Warrior.h"
#include "Mage.h"

int main() {
	// 创建玩家
	shared_ptr<Fighter> p1 = make_shared<Warrior>(10, "张三");
	p1->SetFamilyId(100);

	shared_ptr<Fighter> p2 = make_shared<Warrior>(20, "李四");
	p2->SetFamilyId(100);

	shared_ptr<Fighter> p3 = make_shared<Mage>(30, "王五");
	p3->SetFamilyId(100);

	shared_ptr<Fighter> p4 = make_shared<Mage>(50, "赵六");
	p4->SetFamilyId(200);

	// 创建通知器
	shared_ptr<Notifier> notify = make_shared<TalkNotifier>();

	// 将玩家添加到家族列表中，这样才能收到家族聊天消息
	notify->AddToList(p1);
	notify->AddToList(p2);
	notify->AddToList(p3);
	notify->AddToList(p4);

	// 某玩家聊天，相同家族的人都能收到消息
	p1->SayWords(notify, "我是张三，请大家立即前往沼泽地！");

	cout<< "王五不再想收到家族群聊天信息" << endl;
	notify->RemoveFromList(p3);

	p2->SayWords(notify, "我是李四，请大家听从组长调遣，前往沼泽地！");
}

// 玩家：张三 收到了 玩家：张三 发送的信息：我是张三，请大家立即前往沼泽地！
// 玩家：李四 收到了 玩家：张三 发送的信息：我是张三，请大家立即前往沼泽地！
// 玩家：王五 收到了 玩家：张三 发送的信息：我是张三，请大家立即前往沼泽地！
// 王五不再想收到家族群聊天信息
// 玩家：张三 收到了 玩家：李四 发送的信息：我是李四，请大家听从组长调遣，前往沼泽地！
// 玩家：李四 收到了 玩家：李四 发送的信息：我是李四，请大家听从组长调遣，前往沼泽地！