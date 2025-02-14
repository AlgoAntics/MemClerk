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
    void StackAllocator::init(size_t size, MemFlags flags) {
        m_buffer = this->m_Alloc(size);
        m_head = m_buffer;

        m_maxSize = size;
        m_size = 0;
    }

    void StackAllocator::shutdown() {
        this->deleteBuffer();
    }

    void* StackAllocator::allocate(size_t size, size_t alignment, MemFlags flag) {
        // Assert Memory Size
        if (m_size + size > m_maxSize) {
            printf("Out of Memory");
            std::abort();
        }

        // TODO: Align the memory lol
        void* data = m_head;
        m_head = static_cast<char*>(m_head) + size;

        return data; 
    }

    void StackAllocator::deallocate(MemMarker marker) {
        // Error Checking (Mostly)
        if (marker < m_buffer || marker > m_head) {
            printf("Invalid Marker: Marker Is Out Of Buffer Range");
            return;
        }

        m_size = (int)(static_cast<char*>(m_head) - static_cast<char*>(marker));
        m_head = marker;
    }

    MemMarker StackAllocator::getMarker() {
        return m_head;
    }

    void StackAllocator::deleteBuffer() {
        if (m_buffer != nullptr) {
            this->m_DeAlloc(m_buffer);

            m_buffer = nullptr;
            m_head = nullptr;
            m_size = 0;
            m_maxSize = 0;
        }
    }

}
