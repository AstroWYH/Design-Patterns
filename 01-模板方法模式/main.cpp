#include "Warrior.h"
#include "Mage.h"
#include <memory>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    unique_ptr<Fighter> fighter(new Warrior());
    fighter->Burn();
    // .reset(这里不能放make_unique)。
    fighter.reset(new Mage());
    fighter->Burn();
    return 0;
}