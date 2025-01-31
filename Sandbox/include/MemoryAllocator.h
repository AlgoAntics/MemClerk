#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include <cstdint>
#include "MemoryTracker.h"

namespace mc {

class MemoryAllocator {
    protected:
        MemoryTracker* p_tracker;

    public:
        MemoryAllocator(MemoryTracker* tracker) : p_tracker(tracker) {}
        virtual ~MemoryAllocator() = default;

        // Main Overrideable Allocate Method For Concrete Allocators
        virtual void* allocate(uint64_t size, int16_t flag = -1) = 0;
        virtual void deallocate(void* ptr) = 0;

        // Templated Allocate Method For Abstraction (Calls Concreate Allocate)
        template <typename T>
        T* allocate(int16_t flag = -1) {
            void* raw_data = allocate(sizeof(T), flag);
            return reinterpret_cast<T*>(raw_data);
        }
};

}

#endif // MEMORY_ALLOCATOR_H
