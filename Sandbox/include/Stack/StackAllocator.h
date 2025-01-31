#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "../MemoryAllocator.h"

namespace mc {

    class StackAllocator { //: public MemoryAllocator {
        private:

        public:
            StackAllocator() {}
            ~StackAllocator() {}

            int getX(); 
    };

}

#endif // STACK_ALLOCATOR_H
