#include "Lora_Module.h"

Lora_Module::Lora_Module() {
}

void Lora_Module::Init() {
 
  if (!modem.begin(EU868)) {
    while (1) {}
  } 
  delay(1000);      
  //modem.dutyCycle(DutyCycle);
  //modem.publicNetwork(PublicNetwork);
  //modem.dataRate(DataRate);
  //modem.setADR(ADR);
  if(debug>2){
    Serial.print("deviceEUI "); Serial.println(modem.deviceEUI());
  }
  if (OVER_THE_AIR_ACTIVATE) Lora_Module::Init_OTAA();
  else  Lora_Module::Init_ABP();
    
  modem.sleep();
}
void Lora_Module::Init_OTAA() {
  int connected = modem.joinOTAA(APP_EUI, APP_KEY);
  if (!connected) {
    Serial.println("Something went wrong; are you indoor? Move near a window and retry");
    while (1) {}
  }

  modem.minPollInterval(60);


}
void Lora_Module::Init_ABP() {
  int connected = modem.joinABP(DEVADDR, NWKSKEY, APPSKEY);
  if (!connected) {
    Serial.println("error:Joing failed");
    while (1) {}
  }
  modem.minPollInterval(60);
}
void Lora_Module::info_connect() {
  Serial.println("connection Lora:\n------------------------");
  Serial.print("Data Rate="); Serial.println(modem.getDataRate());
  Serial.print("ADR="); Serial.println(modem.getADR());
  if (OVER_THE_AIR_ACTIVATE) {
    Serial.println("----OTAA----");
    Serial.print("appEUI "); Serial.println(APP_EUI);
    Serial.print("appKey "); Serial.println(APP_KEY);
  }
  Serial.println("------------------------------------------");
  Serial.print("devAddr "); Serial.println(modem.getDevAddr());
  Serial.print("nwkSkey "); Serial.println(modem.getNwkSKey());
  Serial.print("appSkey "); Serial.println(modem.getAppSKey());
  Serial.println("------------------------------------------");

}



bool Lora_Module::send(uint8_t *buffer, int len) {
  int err;
  modem.beginPacket();
  modem.write(buffer, len);
  err = modem.endPacket(true);
  modem.sleep();
  if (err > 0) {

    if(debug>3)Serial.println("message correctly send !");
    return err;
  }
  else{
  if(debug>0)Serial.println("Error sending message :(");
  return err;
  }
}

bool Lora_Module::receive(uint8_t *data, double temp, int Size) {

  delay(temp);
  if (!modem.available()) {

    return 0;
  }
  int i = 0;
  while (modem.available()) {
    data[i++] = (uint16_t)modem.read();
  }
  return 1;
  modem.sleep();

}
