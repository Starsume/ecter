#define ECTER_COMPILER

#include <iostream>
#include <fstream>
#include <string>

#include "include\emem.h"
#include "include\eoptions.h"
#include "include\ecterc.h"
#include "include\etoken.h"

/* Version Defintion */

#define ECTER_VERSION_MINOR 1
#define ECTER_VERSION_MAJOR 0
#define ECTER_VERSION_BUILD 7
#define ECTER_VERSION "Ecter " + std::to_string(ECTER_VERSION_MAJOR) + "." + std::to_string(ECTER_VERSION_MINOR) + "." + std::to_string(ECTER_VERSION_BUILD)

/* Operating System defintion */

#ifdef _WIN32
    #define OS Windows
#elif __linux__
    #define OS Linux
#elif __unix__
    #define OS MAC
#endif

const CompilerInstance instance = CompilerInstance();

const char* ValidOptions[] = {
    "-h", "--help",
    "-o", "--object",
    "-s", "--assembly",
    "-d", "--debug",
    "-l", "--log",
    "-v", "--version"
};

void stop(std::string& reason) {

    exit(1);
}

void checkArguments(char* args[]) {
    Options* optionist;
    int optionsize = sizeof(optionist);

    for(int z=0;z<optionsize;z++) {
        optionist[z] = createOption(args[z]);
    }

    int size = sizeof(args[]);

    for(int x=0;x<size;x++) {
        validateOption(optionist[x]);
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 6) {
        checkArguments(argv[]);
    }
}   