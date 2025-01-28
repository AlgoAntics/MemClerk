#include "../include/StackAllocator.h"

namespace mc {

    StackAllocator::StackAllocator(MemoryTracker* tracker)
        : MemoryAllocator(tracker) 
    {

    }

    StackAllocator::~StackAllocator() {

    }

    void* StackAllocator::allocate(uint64_t size, int16_t flag) {
        m_head = reinterpret_cast<char*>(m_head) + size; 
        return m_head;
    }

    void StackAllocator::resetToMarker(MemMarker flag) {
        m_head = flag;
    }

    MemMarker StackAllocator::getMarker() {
        return m_head;
    }

}
