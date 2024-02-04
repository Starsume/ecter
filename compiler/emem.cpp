#define ECTER_COMPILER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "emem.h"

void meminit() {
    pool.next_free_index = 0;
}

void* alloc(size_t size) {
    if (size <= 0 || size > MAX_ALLOC_SIZE) {
        std::cerr << "Invalid size for allocation" << std::endl;
        return nullptr;
    }

    void* ptr = std::malloc(size);

    if (ptr == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
    }
}

void memfree(void* ptr) {
    if (ptr != nullptr) {
        free(ptr);
    } else {
        std::cerr << "Error: Attempt to free null pointer" << std::endl;
    }
}

template<typename T>
void getAddress(T* ptr) {
    return static_cast<void*>(ptr);
}

void* reall(void* ptr, size_t size) {
    if (size <= 0 || size > MAX_ALLOC_SIZE) {
        std::cerr << "Invalid size for reallocation" << std::endl;
        return nullptr;
    }

    void* new_ptr = std::realloc(ptr, size);

    if (new_ptr == nullptr) {
        std::cerr << "Memory reallocation failed" << std::endl;
    }

    return new_ptr;
}