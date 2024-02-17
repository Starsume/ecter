#define ECTER_COMPILER

#include <vector>
#include "include\eoptions.h"

static Option createOption(const char* option) {
    Option opt((std::string)option);
    return opt;
}

bool validateOption(Option option, const char** validoptions) {
    for (int i = 0; i < option.option.length; ++i) {
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
