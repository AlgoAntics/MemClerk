#include "../../include/Logger/CLoggerImp.h"

#include <cstdio>

namespace mc {

    CLoggerImp::CLoggerImp() {}
    CLoggerImp::~CLoggerImp() {}

    void CLoggerImp::info(const char* msg) {
        printf("%s", msg);
    }

}
