#include <windows.h>
#include <memory>

#include "Monster.h"
#include "UndeadFactory.h"
#include "ElementFactory.h"
#include "MechanicFactory.h"

using namespace std;

shared_ptr<Monster> G_CreateMonster(shared_ptr<MonsterFactory> factory) {
	return factory->CreateMonster();
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	shared_ptr<MonsterFactory> factory = make_shared<UndeadFactory>();
	shared_ptr<Monster> monster = G_CreateMonster(factory);

	factory = make_shared<ElementFactory>();
	monster = G_CreateMonster(factory);

	factory = make_shared<MechanicFactory>();
	monster = G_CreateMonster(factory);

	return 0;
}