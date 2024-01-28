#define ECTER_COMPILER

#include "eerror.h"

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