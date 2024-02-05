#include <iostream>
#include "Singleton.h"

int main() {
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();

    std::cout << "s1µØÖ·: " << s1 << std::endl;
    std::cout << "s2µØÖ·: " << s2 << std::endl;
    return 0;
}