#pragma once
#include "M_Undead.h"
#include "M_Mechanic.h"
#include "M_Element.h"
#include <string>
#include <memory>

using namespace std;

class MonsterFactory {
public:
    //将创建对象这个过程，放到怪物工厂的CreateMonster内来做。
    unique_ptr<Monster> CreateMonster(string type) {
        unique_ptr<Monster> monster = nullptr;
        if (type == "udd") {
            monster.reset(new M_Undead(1000, 0, 100));
        }
        if (type == "elm") {
            monster.reset(new M_Element(300, 500, 80));
        }
        if (type == "mec") {
            monster.reset(new M_Mechanic(2000, 200, 90));
        }

        return monster;
    }
};