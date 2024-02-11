#define ECTER_COMPILER

#include <vector>
#include "include\eoptions.h"

static Options createOption(const char* option) {
    std::vector<std::string> optionsVector;
    std::string optionStr(option);
    optionsVector.push_back(optionStr);
    return Options(optionsVector, optionStr.size());
}

bool validateOption(Options option, const char** validoptions) {
    for (int i = 0; i < option.optionc; ++i) {
        bool found = false;
        for (int j = 0; validoptions[j] != nullptr; ++j) {
            if (option.options[i] == validoptions[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
