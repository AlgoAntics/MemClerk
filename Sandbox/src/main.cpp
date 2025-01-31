#include <iostream>

#include "../include/Stack/StackAllocator.h"

int main() {
    std::cout << "Hello World Test" << std::endl;

    mc::StackAllocator tester;
    std::cout << tester.getX() << std::endl;

    return 0;
}
