#ifndef ECTER_H
#define ECTER_H

#define ECTER_COMPILER
#include <time.h>

typedef struct {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
} CompilerInstance;

#endif