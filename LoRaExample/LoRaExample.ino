#include "Lora_Module.h"
#include "Conversion.h"
#include <ArduinoLowPower.h>
Lora_Module lora;
Conversion conv;
void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  lora.Init();
  lora.info_connect();
}
void loop()
{
  uint8_t buffer[3];
  buffer[0] = (uint8_t)0x02;
  buffer[1] = (uint8_t)0x03;
  buffer[2] = (uint8_t)0x07;
  lora.send(buffer, 3);
  delay(2000);
}
