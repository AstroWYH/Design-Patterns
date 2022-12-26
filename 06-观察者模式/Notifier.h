#pragma once
#include <memory>
#include <string>

using namespace std;

class Fighter;
class Notifier {
public:
	virtual void AddToList(shared_ptr<Fighter> player) = 0;
	virtual void RemoveFromList(shared_ptr<Fighter> player) = 0;
	virtual void Notify(shared_ptr<Fighter> talker, string content) = 0;
	virtual ~Notifier() {}
};
