#include "Ultrason_Module.h"

Ultrason_Module::Ultrason_Module(int trigger, int echo) {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  _trigger = trigger;
  _echo = echo;

}
Ultrason_Module::Ultrason_Module(int trigger, int echo, int minRange, int maxRange) {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  _trigger = trigger;
  _echo = echo;
  _minRange = minRange;
  _maxRange = maxRange;
}
unsigned int Ultrason_Module::echoInms()
{
  digitalWrite(_trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigger, LOW);
  // Why don't I just use? "return pulseIn(_echo, HIGH);"
  // Arduino Primo doesn't have access to pulseIn.
  while (digitalRead(_echo) == LOW);

  int pulseStart = micros();

  while (digitalRead(_echo) == HIGH);

  return micros() - pulseStart;
}
float Ultrason_Module::distance() {
  return (Ultrason_Module::echoInms() / 2) * Speed;
}
float Ultrason_Module::mesure(int nbre, int timing, bool debug) {
  float dis = 0;
  for (int i = 0; i < nbre; i++) {
    dis += Ultrason_Module::distance() ;
    delay(timing);
  }
  return dis / nbre;
}
float Ultrason_Module::etalonnage(float distance, int nbre, int timing, bool debug) {
  float X = 0;
  for (int i = 0; i < nbre; i++) {
    double duration = Ultrason_Module::echoInms();
    X += distance * (2 / duration);
    delay(timing);
  }
  Speed = X / nbre;
  return Speed ;
}
