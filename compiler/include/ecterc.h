#ifndef ECTERC_H
#define ECTERC_H

#define ECTER_COMPILER

#include "include\estate.h"
#include <ctime>

class CompilerInstance {
    public:
        CompilerInstance() {
            t = time(NULL);
            tm = localtime(&t);
        }

        time_t t;
        struct tm *tm;
};

void stop(std::string& reason);

#endif