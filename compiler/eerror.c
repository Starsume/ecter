#define ECTER_COMPILER

#include "eerror.h"
#include "ecterc.h"
#include "etoken.h"
#include <stdio.h>

Error createError(char n[], char c[], Position pos) {
    Error err = Error(n[], c[], pos);
    return err;
}

ErrorType getErrorType(Error err) {
    if (err->name == "SyntaxError") {
        return SyntaxError;
    }
    else if (err->name == "TypeError") {
        return TypeError;
    }
}

Error[] handleError(char* path[] = "", char* tokenlist[] = "", ErrorHandler handler) {
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