#pragma once

#include "Arduino.h"
#include "HID-Project.h"
#include <Led.cpp>

class State
{
public:
    const PhoneKeycode MUTE_CODE = HID_PHONE_MUTE;
    const PhoneKeycode UNMUTE_CODE = HID_PHONE_HOOK_SWITCH;
    const Led* led_;

    State(Led* led){
        led_ = led;
    };

    virtual void pressed(Phone_* callControll);
    virtual void released(Phone_* callControll);
};
