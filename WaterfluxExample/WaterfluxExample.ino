#include "Waterflux_Module.h"
void setup() {
  Serial.begin(9600);
  while (!Serial) {}
 
  WF_Init(2);
}

void loop() {
  Serial.println(WF_Debit(1));

}
