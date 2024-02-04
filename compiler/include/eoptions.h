#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

#include <vector>

class Options {
    public:
        
        std::vector<std::string> options(optionc);
};

Options createOption(char* option);
bool validateOption(Options option);

#endif