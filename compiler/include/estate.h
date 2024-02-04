#ifndef ESTATE_H
#define ESTATE_H

#define ECTER_COMPILER

enum class States {
    Idle,
    Compiling,
    Assembling,
    Finished,
    Error
};

class State {
    public:
        State() {
            current_state = "Idle";
        }

        std::string getState() const;

        void setState(const std::string state);

        bool validateState(States state) {
            switch (state) {
                case States::Idle:
                case States::Compiling:
                case States::Assembling:
                case States::Finished:
                case States::Error:
                    return true;
                default:
                    return false;
            }
        }

    private:
        std::string current_state;
};

#endif