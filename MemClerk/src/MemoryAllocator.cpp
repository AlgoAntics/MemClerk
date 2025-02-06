#include "../include/MemoryAllocator.h"

namespace mc {

    MemoryAllocator::MemoryAllocator(MemoryTracker* mem_tracker)
        : p_tracker(mem_tracker), m_Alloc(malloc), m_DeAlloc(free) {}

    void MemoryAllocator::setAllocFunc(std::function<void*(size_t)> alloc_func) {
        // TODO: Error Checking/Validation?
        this->m_Alloc = alloc_func;
    }

    void MemoryAllocator::setDeAllocFunc(std::function<void(void*)> dealloc_func) {
        // TODO: Error Checking/Validation?
        this->m_DeAlloc = dealloc_func;
    }

}
