#include <iostream>

#include "test.h"

int main() {
    std::cout << "Hello World" << std::endl;

    Test tester;
    std::cout << tester.get() << std::endl;
    return 0;
}
