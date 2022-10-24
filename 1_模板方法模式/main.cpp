#include "Warrior.h"
#include "Mage.h"
#include <memory>

using namespace std;

int main() {
    // 多态，父类指针指向子类对象。
    unique_ptr<Fighter> fighter(new Warrior());
    fighter->Burn();

    // .reset(这里不能放make_unique)。
    fighter.reset(new Mage());
    fighter->Burn();
    return 0;
}