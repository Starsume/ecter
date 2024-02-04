#ifndef ESTATE_H
#define ESTATE_H

#define ECTER_COMPILER

std::string validStates[] = {"Compiling", "Idle"};

class State {
    public:
        State() {
            current_state = "Idle"
        }

        std::string getState() const {
            return current_state;
        }

        void setState(const std::string state) {
            current_state = state;
        }

    private:
        std::string current_state;
};

#endif