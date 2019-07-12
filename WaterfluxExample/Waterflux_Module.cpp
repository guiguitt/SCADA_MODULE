/*
 *  InputCapture
 * 
 *  Functions for mesure of PWM
 *  Needs interruptions enabled
 * 
 *  Alexi Husson
 *  18/04/2019
 */


#include <Arduino.h>
#include "Waterflux_module.h"

int pin;
volatile unsigned long prev_time;
volatile double period;



void WF_Init(int p){
  pin = p;
  attachInterrupt(pin, WF_Rising, RISING);
}

double WF_GetFreq(){

  return 1/(period/1000000);
}

void WF_Rising() {  
  attachInterrupt(pin, WF_Rising2, RISING);
  prev_time = micros();
}

void WF_Rising2() {
  attachInterrupt(pin, WF_Rising, RISING);
  period = micros()-prev_time;
}
double WF_Debit(float coef){
	return WF_GetFreq()*coef;
}
