#include <iostream>
#include <string>
#include "UndeadBuilder.h"
#include "MechanicBuilder.h"
#include "ElementBuilder.h"
#include "MonsterDirector.h"
#include "Monster.h"
#include <memory>

using namespace std;

int main() {
	system("CHCP 65001");
	shared_ptr<MonsterBuilder> builder = make_shared<UndeadBuilder>();
	shared_ptr<MonsterDirector> director = make_shared<MonsterDirector>(builder);
	shared_ptr<Monster> monster = director->Construct("UT-UH-UL");

	return 0;
}