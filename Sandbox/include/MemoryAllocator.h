#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include <cstdint>
#include <cstdlib>
#include <functional>
#include <new>

#include "MemoryTracker.h"

namespace mc {

class MemoryAllocator {
    protected:
        MemoryTracker* p_tracker;

        std::function<void*(size_t)> m_Alloc;
        std::function<void(void*)> m_DeAlloc;

    public:
        void setAllocFunc(std::function<void*(size_t)> alloc_func);
        void setDeAllocFunc(std::function<void(void*)> dealloc_func);

    public:
        MemoryAllocator(MemoryTracker* tracker);
        virtual ~MemoryAllocator() = default;

        // StartUp/ShutDown 
        virtual void init(uint64_t size) = 0;
        virtual void shutdown() = 0;

        // Main Overrideable Allocate Method For Concrete Allocators
        virtual void* allocate(size_t size, size_t alignment, int16_t flag = -1) = 0;
        virtual void deallocate(void* ptr) = 0;

        // Templated Allocate Method For Abstraction (Calls Concreate Allocate)
        template <typename T>
        T* allocPrim(int16_t flag = -1) {
            void* raw_data = allocate(sizeof(T), alignof(T), flag);
            return reinterpret_cast<T*>(raw_data);
        }

        template <typename T, typename... Args>
        T* alloc(uint16_t flag = -1, Args&&... args) {
            void* raw_data = allocate(sizeof(T), alignof(T), flag);
            return new (raw_data) T(std::forward<Args>(args)...);
        }
};

}

#endif // MEMORY_ALLOCATOR_H
