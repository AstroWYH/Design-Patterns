#pragma once
#include "M_Undead.h"
#include "M_Mechanic.h"
#include "M_Element.h"
#include <string>
#include <memory>

using namespace std;

//简单工厂模式，只有这一个怪物工厂，没有具体每种怪物专门的工厂。
class MonsterFactory {
public:
    //将创建对象这个过程，放到怪物工厂的CreateMonster内来做。
    //return的是Monster这个父类。
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