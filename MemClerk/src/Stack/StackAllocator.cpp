#include "../../include/Stack/StackAllocator.h"

#include <cstdio>
#include <cstring>

namespace mc {

    StackAllocator::StackAllocator(MemoryTracker* mem_tracker) 
        : MemoryAllocator(mem_tracker) {}
    
    StackAllocator::~StackAllocator() {
        this->shutdown();
    }

    // Init Separate to Allow User to Update Alloc Function
    void StackAllocator::init(size_t size) {
        m_buffer = this->m_Alloc(size);
        m_head = m_buffer;

        m_size = size;
    }

    void StackAllocator::shutdown() {
        this->deleteBuffer();
    }

    void* StackAllocator::allocate(size_t size, size_t alignment, int16_t flag) {
        // TODO: Align the memory lol
        void* data = static_cast<char*>(m_head) + size;
        return data;
    }

    void StackAllocator::deallocate(void* ptr) {
        // Error Checking (Mostly)
        if (ptr < m_buffer || ptr > (char*)m_buffer + m_size) {
            printf("Invalid Marker: Marker Is Out Of Buffer Range");
            return;
        }

        m_head = ptr;
    }

    void StackAllocator::resizeBuffer(size_t size) {
        // This is weird, what if I want to just extend the memory not fully
        // replace it?
        void* new_mem = this->m_Alloc(size);
        memcpy(new_mem, m_buffer, m_size);

        this->m_DeAlloc(m_buffer);
        m_buffer = new_mem;
        m_size = size;
    }

    void StackAllocator::deleteBuffer() {
        if (m_buffer != nullptr) {
            this->m_DeAlloc(m_buffer);

            m_buffer = nullptr;
            m_head = nullptr;
        }
    }

}
