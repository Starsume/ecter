#ifndef EMEM_H
#define EMEM_H

#define ECTER_COMPILER

#include <stdlib.h>
#include <stdint.h>

#define POOL_SIZE 10000

typedef struct {
    uint8_t data[POOL_SIZE];
    uint32_t next_free_index;
} MemoryPool;

void meminit();
void* alloc(size_t size);
void memfree(void* ptr);
void getAddress(void* ptr);
void reall(void* ptr);

#endif