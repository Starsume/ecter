#define ECTER_COMPILER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "include\emem.h"
#include "include\eerror.h"
#include "include\estate.h"
#include "include\eoptions.h"
#include "include\ecterc.h"
#include "include\etoken.h"
#include "include\eas.h"
#include "include\egc.h"

/* Version Defintion */

#define ECTER_VERSION_MINOR 1
#define ECTER_VERSION_MAJOR 0
#define ECTER_VERSION_BUILD 7
#define ECTER_VERSION "Ecter " + std::to_string(ECTER_VERSION_MAJOR) + "." + std::to_string(ECTER_VERSION_MINOR) + "." + std::to_string(ECTER_VERSION_BUILD)

/* Namespaces used */

using namespace std;
using namespace eas;

/* Operating System defintion */

#if defined(__WIN32__) || defined(_WIN32)
    #define OS "Windows"
#elif defined(__linux__)
    #define OS "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
    #define OS "Mac OS"
#else
    #define OS "Unknown"
#endif

const CompilerInstance instance = CompilerInstance();

const SymbolTable table;

const char* ValidOptions[] = {
    "-h", "--help",
    "-o", "--object",
    "-s", "--assembly",
    "-d", "--debug",
    "-l", "--log",
    "-v", "--version"
};

void addEntries() {
    table.addEntry("mov");
    table.addEntry("add");
    table.addEntry("push");
    table.addEntry("jmp");
    table.addEntry("call");
    table.addEntry("hlt");
    table.addEntry("bits");
    table.addEntry("extern");
    table.addEntry("section");
    table.addEntry("global");
    table.addEntry("equ");
    table.addEntry("int");
    table.addEntry("syscall");
    table.addEntry("xor");
    table.addEntry("ret");
}

void stop() {
    exit(1);
}

void checkArguments(char* args[], int argc) {
    std::vector<Options> optionList(argc); 
    const char* opt;

    addEntries();

    for(int z = 0; z < argc; z++) {
        opt = args[z];
        optionList[z] = Options::createOption(opt); 
    }

    for(int x = 0; x < argc; x++) {
        validateOption(optionList[x], ValidOptions); 
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "Usage: " << "ecterc.exe" << " [options]" << "file..." << endl;
        return ERROR_CODE;
    }

    const string help_message = R"(Usage: ecterc.exe [options] file...
                                    Options:
                                        -c              Input file.
                                        -h, --help      Display Help.
                                        -o, --object    Compile to object .o files.
                                        -s, --assembly  Compile to assembly.
                                        -l, --log       Enable logging. Log files are stored in APPDATA.
                                        -v, --version   Display version.)";

    for (int i=1; i<argc ; ++i) {
        string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            cout << help_message << endl;
        } else if (arg == "-c") {
            const std::fstream input = file(argv[i+1]);
        } else if (arg == "-o" || arg == "--object") {
            // Process object option
        } else if (arg == "-s" || arg == "--assembly") {
            // Process assembly option
        } else if (arg == "-l" || arg == "--log") {
            // Process log option
        } else if (arg == "-v" || arg == "--version") {
            cout << ECTER_VERSION << ", running on " << OS << endl;
        } else {
            cout << "Invalid option: " << arg << endl;
            return 1;
        }
    }
}   