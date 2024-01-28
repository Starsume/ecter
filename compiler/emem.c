#define ECTER_COMPILER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "emem.h"

static MemoryPool pool;

void meminit() {
    pool.next_free_index = 0;
}

void* alloc(void* ptr) {
    if (pool.next_free_index + size = > POOL_SIZE) {
        printf("Memory pool is full!\n");
        return NULL;
    }

    void* ptr = &pool.data[pool.next_free_index];
    pool.next_free_index += size;
    return ptr;
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