#ifndef CLOGGER_IMP_H
#define CLOGGER_IMP_H

#include "LoggerImp.h"

namespace mc {

class CLoggerImp : public LoggerImp {
    public:
        CLoggerImp();
        ~CLoggerImp();

        void info(const char* msg) override;
};

}

#endif // CLOGGER_IMP_H
