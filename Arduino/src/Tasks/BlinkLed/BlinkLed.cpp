#include "BlinkLed.h"

BlinkLed::BlinkLed(Light* led){
  this->led = led;    
}
  
void BlinkLed::init(int period){
  Task::init(period);
  led->switchOff();
  state = OFF;    
}
  
void BlinkLed::tick(){
  switch (state){
    case OFF:
      led->switchOn();
      state = ON; 
      break;
    case ON:
      led->switchOff();
      state = OFF;
      break;
  }
}
