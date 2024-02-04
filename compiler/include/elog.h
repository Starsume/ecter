#ifndef ELOG_H
#define ELOG_H

#define ECTER_COMPILER

#define DATA_SIZE_MAX 10000

void createLog(const char* path);
void log(const char* filename, char* message);

#endif