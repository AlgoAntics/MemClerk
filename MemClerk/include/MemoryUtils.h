#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

namespace mc {

    typedef void* MemMarker;
    
    enum class MemFlags {
        ALLOC_LEFT=1,
        ALLOC_RIGHT=2
    };

}

#endif // MEMORY_UTILS_H
