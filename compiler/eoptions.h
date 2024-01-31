#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

const char[] ValidOptions = {
    "-h", "--help",
    "-o", "--object",
    "-s", "--assembly",
    "-d", "--debug",
    "--version"
};

typedef struct {
    int optionc = 0;
    char* options;
} Options;

Options createOption();
bool validateOption(Options option);

#endif