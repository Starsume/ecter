#ifndef EERROR_H
#define EERROR_H

#define ECTER_COMPILER

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

Error createError(char name[], char cause[], Position pos);
ErrorType getErrorType(Error err);

#endif