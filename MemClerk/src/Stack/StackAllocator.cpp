#include "../../include/Stack/StackAllocator.h"

#include <cstdio>

namespace mc {

    StackAllocator::StackAllocator(uint64_t size, MemoryTracker* mem_tracker) 
        : m_size(size), MemoryAllocator(mem_tracker) {

        m_buffer = malloc(size);
        m_head = m_buffer;
    }
    
    StackAllocator::~StackAllocator() {
        this->deleteBuffer();
    }

    void* StackAllocator::allocate(size_t size, size_t alignment, int16_t flag) {
        return nullptr;
    }

    void StackAllocator::deallocate(void* ptr) {
        // Error Checking (Mostly)
        if (ptr < m_buffer || ptr > (char*)m_buffer + m_size) {
            printf("Invalid Marker: Marker Is Out Of Buffer Range");
            return;
        }

        m_head = ptr;
    }

    void StackAllocator::resizeBuffer(uint64_t size) {
     
    }

    void StackAllocator::deleteBuffer() {
        if (m_buffer != nullptr) {
            free(m_buffer);

            m_buffer = nullptr;
            m_head = nullptr;
        }
    }

}
