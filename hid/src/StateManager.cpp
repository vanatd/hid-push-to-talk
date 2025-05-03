#include <Arduino.h>
#include <HID-Project.h>
#include <State.cpp>

class StateManager
{
    Phone_* callControll_;
    State* state_;
public:
    StateManager(Phone_* callControll){
        callControll_ = callControll;
        state_ = nullptr;
    }
    void pressed() {
        state_->pressed(callControll_);
    };
    void released() {;
        state_->released(callControll_);
    };
    
    void setState(State* state) {
        state_ = state;
        callControll_->releaseAll();
        state->released(callControll_);
    }
};
