#include "MonsterFactory.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    MonsterFactory fac;
    unique_ptr<Monster> udd_mon = fac.CreateMonster("udd");
    unique_ptr<Monster> elm_mon = fac.CreateMonster("elm");
    unique_ptr<Monster> mec_mon = fac.CreateMonster("mec");
    return 0;
}