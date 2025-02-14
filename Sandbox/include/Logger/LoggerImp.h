#ifndef LOGGER_IMP_H
#define LOGGER_IMP_H

class LoggerImp {
    public:
        LoggerImp() {}
        virtual ~LoggerImp() {}

        virtual void info(const char* msg) = 0;
};

#endif // LOGGER_IMP_H
