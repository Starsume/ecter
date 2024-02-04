#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

#include <vector>
#include <string>

class Options {
    public:
        Options(std::vector<std::string> options, int optionc);

        int optionc;
        std::vector<std::string> options;

        Options createOption(const char* option);
};

bool validateOption(Options option);

#endif
