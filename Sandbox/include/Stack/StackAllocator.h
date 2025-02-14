#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "../MemoryAllocator.h"
#include "../MemoryUtils.h"

namespace mc {

    class StackAllocator : public MemoryAllocator {
        private:
            // Allocation Tools
            void* m_buffer = nullptr;
            void* m_head = nullptr;

        private:
            void deleteBuffer();

        public:
            StackAllocator(MemoryTracker* mem_tracker);
            ~StackAllocator();

            // Startup/Shutdown
            void init(uint64_t size, MemFlags flags = (MemFlags)-1) override;
            void shutdown() override;

            // Allocation
            void* allocate(size_t size, size_t alignment, MemFlags flag = MemFlags::ALLOC_LEFT) override;
            void deallocate(MemMarker marker) override;

            MemMarker getMarker();
    };

}

#endif // STACK_ALLOCATOR_H
