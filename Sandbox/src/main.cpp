#include <iostream>

#include "../include/Stack/StackAllocator.h"

int main() {
    std::cout << "Hello World Test" << std::endl;

    mc::MemoryTracker myTracker;
    mc::StackAllocator myStack(&myTracker);
    myStack.init(100);
    int* myInt = myStack.alloc<int>(5);

    std::cout << *myInt << std::endl;

    return 0;
}
