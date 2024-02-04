#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

#include <vector>
#include "include\eoptions.h"

Options createOption(const char* option) {
    Options opt;
    opt.options.push_back(option);
    opt.optionc = 1; 
    return opt;
}

bool validateOption(Options option) {
    std::vector<std::string> ValidOptions = {"option1", "option2", "option3"}; // Replace with your actual list of valid options

    for (const auto& opt : option.options) {
        bool valid = false;
        for (const auto& validOpt : ValidOptions) {
            if (opt == validOpt) {
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