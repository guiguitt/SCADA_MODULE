#include "LedIndicator_Module.h"

LedIndicator_Module led;

void setup() {
led.ON(0);
led.WIFI(0);
led.FAIL(0);

}

void loop() {
  led.ON();
  delay(1000);
  led.WIFI();
  delay(1000);
  led.FAIL();
  delay(1000);

}
