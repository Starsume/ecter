#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

typedef struct {
    int optionc = 0;
    char* options;
} Options;

Options createOption(char* option);
bool validateOption(Options option);

#endif