#include "Ultrason_Module.h"
#define TRIG_PIN 3
#define ECHO_PIN 4

Ultrason_Module US(TRIG_PIN, ECHO_PIN, 50, 1050);
void setup() {
  //etalonnage(1044, 200 , 100, 0);
  Serial.begin(9600);
  while (!Serial) {}
}

void loop() {
  Serial.println(US.mesure(200, 50, 0));
  //Serial.println("mm");

}
