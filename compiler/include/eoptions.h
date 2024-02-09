#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

#include <vector>
#include <string>

class Options {
    public:
        std::vector<std::string> options;
        int optionc;

        Options(std::vector<std::string> x, int y) {
            options = x;
            optionc = y;
        }

        static Options createOption(const char* option);
};

bool validateOption(Options option, const char** validoptions);

#endif
