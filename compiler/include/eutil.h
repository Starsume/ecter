#ifndef EUTIL_H
#define EUTIL_H

#define ECTER_COMPILER

#include <cstddef>

size_t length(const char *string) {
    const char *start = string;

    while (*string != '\0') {
        string++;
    }

    return static_cast<size_t>(string - start);
}

int getArchitecture() {
    if (sizeof(void*) == 8) {
        return 64;
    } else if (sizeof(void*) == 4)
    {
        return 32;
    }
}

#endif