#include <Arduino.h>
#include <Keypad.h>
#include <HID-Project.h>

#include <Led.cpp>
#include <State.cpp>
#include <StateManager.cpp>
#include <MutedState.cpp>
#include <UnmutedState.cpp>

int C1 = 2;
int C2 = 3;
int C3 = 4;
int R1 = 5;

const byte ROWS = 1;
const byte COLS = 3;

char keys[ROWS][COLS] = { {'s', 'u', 'm'} };
byte rowPins[ROWS] = {R1};
byte colPins[COLS] = {C3, C2, C1};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

StateManager stateMng = StateManager(&Phone);

Led led = Led(A3);

MutedState muted = MutedState(&led);
UnmutedState unmuted = UnmutedState(&led);

void listener(char key) {
  if(key == 's') {
    if(kpd.isPressed(key)) {
      stateMng.pressed();
    } else {
      stateMng.released();
    }
  }
};

void setup(){
  Serial.begin(9600);
  Phone.begin();
  
  led.begin();

  stateMng.setState(&muted);
  
  kpd.setHoldTime(1000 * 60 * 60);

  kpd.addEventListener(listener);
}

void loop(){
  char key = kpd.getKey();

  if (key) {
    if(key == 'm'){ 
      stateMng.setState(&muted);
    }

    if(key == 'u'){ 
      stateMng.setState(&unmuted);
    }
  }
}



