#ifndef EERROR_H
#define EERROR_H

#define ECTER_COMPILER
#include "ecterc.h"
#include "etoken.h"
#include <stdio.h>

typedef struct {
    int line;
    int character;
} Position;

typedef struct {
    char* name[];
    char* cause[];
    Position pos;
} Error;

typedef enum ErrorType {
    SyntaxError,
    TypeError,
};

typedef struct {
    CompilerInstance instance;
} ErrorHandler;

Error createError(char name[], char cause[], Position pos);
ErrorType getErrorType(Error err);
Error[] handleError(char* path[] = "", char* tokenlist[] = "", ErrorHandler handler);
void reportError(Error err);

#endif