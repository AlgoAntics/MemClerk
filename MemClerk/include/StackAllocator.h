#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "MemoryAllocator.h"

namespace mc {

class StackAllocator : public MemoryAllocator {
    private:
        void* m_buffer;
        void* m_head;
    
    public:
        StackAllocator(MemoryTracker* tracker);
        ~StackAllocator();

        void* allocate(uint64_t size, int16_t flag = -1) override;

        void resetToMarker(MemMarker flag);
        MemMarker getMarker();
};

}

#endif // STACK_ALLOCATOR_H
