#ifndef EUTIL_H
#define EUTIL_H

#define ECTER_COMPILER

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>

size_t length(const char *string) {
    const char *start = string;

    while (*string != '\0') {
        string++;
    }

    return static_cast<size_t>(string - start);
}

int getArchitecture() {
    const std::string& filePath = "%localappdata%/ecter/settings.ini";
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::getline(file, getArchitecture);
        file.close();
    } else {
        int defaultArch = sizeof(void*) == 4 ? 32 : 64;
        std::cerr << "Ecter: warning: unable to open file " << filePath << ", assuming target architecture is " << defaultArch << "-bit" << std::endl;
    }
}

#endif