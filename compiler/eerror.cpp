#define ECTER_COMPILER

#include "include\eerror.h"
#include "include\ecterc.h"
#include "include\etoken.h"
#include <cstring>

Error createError(const char n[], const char c[], Position pos) {
    Error err;
    strcpy(err.name, n);
    strcpy(err.cause, c);
    err.pos = pos;
    return err;
}

ErrorType getErrorType(Error err) {
    if (strcmp(err.name, "SyntaxError") == 0) {
        return SyntaxError;
    }
    else if (strcmp(err.name, "TypeError") == 0) {
        return TypeError;
    }
    return SyntaxError;
}

Error handleError(char* tokenlist[] = "", ErrorHandler handler) {
    if (path[] == "" || tokenlist[] == "") {
        return Error("", "", Position(0, 0));
    }
    else if (path[] != "" || tokenlist == "")
    {
        /* code */
    }
    else if (tokenlist[] != "" || path[] == "")
    {
        /* code */
    }
    
}