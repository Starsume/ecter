#ifndef EERROR_H
#define EERROR_H

#define ECTER_COMPILER
#include "\ecterc.h"
#include "\etoken.h"
#include <iostream>

/* Codes */
#define OK_CODE 0
#define ERROR_CODE 1

class Position {
    public:
        int line;
        int character;
};

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
    int errorc;
    Error* errors;
    CompilerInstance instance;
} ErrorHandler;

ErrorHandler createHandler();
Error createError(char name*, char cause*, Position pos);
ErrorType getErrorType(Error err);
Error* checkForErrors();
void reportError(Error err);

#endif