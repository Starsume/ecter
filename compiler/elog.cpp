#define ECTER_COMPILER

#include <iostream>
#include <fstream>
#include <string>

#include "include\ecterc.h"

void createLog(const char* path) {
    std::ofstream logFile(path);
    if (!logFile.is_open()) {
        std::cerr << "Unable to create log file" << std::endl;
    }
}

void log(const std::string& filename, const std::string& message) {
    std::ofstream logFile(filename, std::ios_base::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    } else {
        std::cerr << "Error opening the log file." << std::endl;
    }
}

