#include <Arduino.h>
#include "AnalogTempSensor.h"

/* Lm 35 */
AnalogTempSensor::AnalogTempSensor(int pin) {
    this->pin = pin;
    pinMode(pin,INPUT);
}

double AnalogTempSensor::getTemperature(){
  int value = analogRead(A2);
  
  /* value : 1023 = value_in_mV : 5000 */
  /* value_in_mV = 5000/1023 * value */
  
  int value_in_mV = 4.8876 * value; 

  /* value_in_C = value_in_mV / 10 (since we have 10 mV => 1 °C ) */

  double value_in_C = value_in_mV * 0.1;

  return value_in_C;
};
