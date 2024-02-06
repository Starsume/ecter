#ifndef EERROR_H
#define EERROR_H

#define ECTER_COMPILER
#include "ecterc.h"
#include "etoken.h"
#include <iostream>

/* Codes */
#define OK_CODE 0
#define ERROR_CODE 1

class Position {
    public:
        int line;
        int character;
};

enum ErrorType {
    SyntaxError,
    TypeError,
};

class Error {
    public:
        char* name;
        char* cause;
        Position pos;
};

class ErrorHandler {
    public:
        int errorc;
        Error* errors;
        CompilerInstance instance;

        ErrorHandler();

        ~ErrorHandler();

        void initialize();
        Error createError(const char* name, const char* cause, Position pos);
        ErrorType getErrorType(Error err);
        Error* checkForErrors();
        void reportError(Error err);
};

#endif