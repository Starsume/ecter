#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

#include "eoptions.h"

const char* options;

Options createOption(char* option) {
    Options opt;
    opt->options = option;
    opt->optionc = (int)sizeof(option);
    return opt;
}

bool validateOption(Options option) {
    
}

#endif