#define ECTER_COMPILER

#include <cstring>

size_t length(const char *string) {
    const char *start = string;

    while(*string != '\0') {
        string++;
    }
    
    return (size_t)(string - start);
}