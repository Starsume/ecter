#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

#include "include\eoptions.h"

const char* options;

Options createOption(char* option) {
    Options opt;
    opt->options = option;
    opt->optionc = (int)sizeof(option);
    return opt;
}

bool validateOption(Options option) {
    for (int i = 0; i < option.optionc; i++) {
        bool valid = false;
        for (int j = 0; j < sizeof(ValidOptions) / sizeof(ValidOptions[0]); j++) {
            if (strcmp(option.options[i], ValidOptions[j]) == 0) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            return false;
        }
    }
    return true;
}

#endif