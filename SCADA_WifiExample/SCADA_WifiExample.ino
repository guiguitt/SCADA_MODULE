#include "Wifi_Module.h"
#define DELAY 1
#define Size 4

Wifi_Module wifi;
void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  Serial.flush();
}

void loop() {
  double Buffer[Size]={4,3,2,1};
  int sent = wifi.sendData(Buffer,Size,true) ;
  delay(DELAY);
}
