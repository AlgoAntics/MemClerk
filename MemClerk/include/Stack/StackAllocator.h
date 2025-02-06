#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "../MemoryAllocator.h"

namespace mc {

    class StackAllocator : public MemoryAllocator {
        private:
            void* m_buffer = nullptr;
            void* m_head = nullptr;

            uint64_t m_size = 0;

        private:
            void deleteBuffer();

        public:
            StackAllocator(MemoryTracker* mem_tracker);
            ~StackAllocator();

            // Startup/Shutdown
            void init(uint64_t size) override;
            void shutdown() override;

            // Allocation
            void* allocate(size_t size, size_t alignment, int16_t flag = -1) override;
            void deallocate(void* ptr) override;

            void resizeBuffer(uint64_t size);
    };

}

#endif // STACK_ALLOCATOR_H
