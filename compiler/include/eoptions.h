#ifndef EOPTIONS_H
#define EOPTIONS_H

#define ECTER_COMPILER

#include <vector>
#include <iostream>
#include <string>

class Option {
    public:
        std::string option;
        int optionc;

        Option() : option(""), optionc(0) {}

        Option(std::string x) {
            option = x;
        }

        static Option createOption(const char* option);
};

bool validateOption(Option opt, const char** validoptions);

#endif
