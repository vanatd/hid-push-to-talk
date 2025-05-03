
#include <Arduino.h>
#include <HID-Project.h>
#include <State.cpp>

class MutedState: public State
{
public:
    using State::State;
    
    void pressed(Phone_* callControll){
        callControll->press(UNMUTE_CODE);

        led_->on();
    };
    void released(Phone_* callControll){
        callControll->press(MUTE_CODE);

        led_->off();
    };
};
