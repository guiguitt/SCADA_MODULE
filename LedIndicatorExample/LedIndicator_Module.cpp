#include "LedIndicator_Module.h"

LedIndicator_Module::LedIndicator_Module(){
  pinMode(LED_ON, OUTPUT);
  pinMode(LED_WIFI, OUTPUT);
  pinMode(LED_FAIL, OUTPUT);
}
void LedIndicator_Module::ON(bool statue) {
  digitalWrite(LED_ON, statue);
}
void LedIndicator_Module::ON() {
  if(on==true){
    digitalWrite(LED_ON, LOW);
    on=false;
  }
  else{
    digitalWrite(LED_ON, HIGH);
    on=true; 
  }
}
void LedIndicator_Module::WIFI(bool statue) {
  digitalWrite(LED_WIFI, statue);

}
void LedIndicator_Module::WIFI() {
  if(wifi==true){
    digitalWrite(LED_WIFI, LOW);
    wifi=false;
  }
  else{
    digitalWrite(LED_WIFI, HIGH);
    wifi=true; 
  }
}
void LedIndicator_Module::FAIL() {
  if(fail==true){
    digitalWrite(LED_FAIL, LOW);
    fail=false;
  }
  else{
    digitalWrite(LED_FAIL, HIGH);
    fail=true; 
  }
}
void LedIndicator_Module::FAIL(bool statue) {
  digitalWrite(LED_FAIL, statue);

}
