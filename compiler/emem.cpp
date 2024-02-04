#define ECTER_COMPILER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "emem.h"

#define MAX_ALLOC_SIZE 1000000

static MemoryPool pool;

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
    if(ptr == &pool.data[pool.next_free_index - 1]) {
        pool.next_free_index = (uint32_t)((uint8_t*)ptr - pool.data);
    }
}

void getAddress(void* ptr) {
    return &ptr;
}

void reall(void* ptr) {

}