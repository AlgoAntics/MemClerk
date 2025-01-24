#include <iostream>

#include "../include/test.h"

int main() {
    std::cout << "Hello World Test" << std::endl;

    Test tester;
    std::cout << tester.get() << std::endl;

    return 0;
}
