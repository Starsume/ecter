#ifndef ESTATE_H
#define ESTATE_H

#define ECTER_COMPILER

#include "include\estate.h"

std::string State::getState() const {
    return current_state;
}

void setState(const std::string state) {
    current_state = state;
}

#endif