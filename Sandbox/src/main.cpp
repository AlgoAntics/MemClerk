#include <iostream>

#include "../include/Stack/StackAllocator.h"

int main() {
    std::cout << "Hello World Test" << std::endl;

    mc::MemoryTracker myTracker;
    mc::StackAllocator myStack(&myTracker);
    myStack.init(100);
    int* myInt = myStack.alloc<int>(69420);
    mc::MemMarker mark = myStack.getMarker();
    int* myInt2 = myStack.alloc<int>(333);

    std::cout << *myInt << ", " << *myInt2 << std::endl;

    myStack.deallocate(mark);
    std::cout << "Deleting int2..." << std::endl;

    std::cout << "\nMarked Deleted But Still Here:" << std::endl;
    std::cout << *myInt << ", " << *myInt2 << std::endl; // Deleted Mem

    int* myInt3 = myStack.alloc<int>(2000);
    std::cout << *myInt3 << std::endl;

    std::cout << "\nAllocated new memory, replaced int2" << std::endl;
    std::cout << *myInt << ", " << *myInt2 << std::endl;

    return 0;
}
