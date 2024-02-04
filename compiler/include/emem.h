#ifndef EMEM_H
#define EMEM_H

#define ECTER_COMPILER

#include <iostream>
#include <cstdlib>

#define MAX_ALLOC_SIZE 1000000

void* alloc(size_t size);
void memfree(void* ptr);
void getAddress(void* ptr);
void reall(void* ptr);

#endif