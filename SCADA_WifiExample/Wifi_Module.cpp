#include "Wifi_Module.h"

Wifi_Module::Wifi_Module() {

}


bool Wifi_Module::wifiConnected() {
  return WiFi.status() == WL_CONNECTED;
}

void Wifi_Module::printMacAddress() {
  // the MAC address of your Wifi shield
  byte mac[6];

  // print your MAC address:
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);
}

void Wifi_Module::listNetworks() {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1)
  {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    printEncryptionType(WiFi.encryptionType(thisNet));
    Serial.flush();
  }
}

void Wifi_Module::printEncryptionType(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.println("WEP");
      break;
    case ENC_TYPE_TKIP:
      Serial.println("WPA");
      break;
    case ENC_TYPE_CCMP:
      Serial.println("WPA2");
      break;
    case ENC_TYPE_NONE:
      Serial.println("None");
      break;
    case ENC_TYPE_AUTO:
      Serial.println("Auto");
      break;
  }
}

void Wifi_Module::wifiConnect(String ssid, String pass, bool debug) {
  if ( WiFi.status() != WL_CONNECTED) {
    while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
      digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
      if (debug)listNetworks();
      // unsuccessful, retry in 4 seconds
      if (debug)Serial.print("failed ... ");
      digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
      delay(4000);
      if (debug)Serial.println("retrying ... ");
    }
    if (debug)Serial.println("connected to Wifi network");
  }
}

bool Wifi_Module::sendData(double *Buffer, int Size, bool debug) {
  WiFiClient client;
  if (!wifiConnected()) {
    if (debug)Serial.println("WIFI connect...");
    wifiConnect(WIFI_SSID, WIFI_PASSWORD, debug);
  }
  if (debug)Serial.println("\nStarting connection to server...");
  //-------------------------------------
  String str = "GET /" + String(SCADA_TOKEN);
  for (int i = 0; i < Size; i++) {
    str += "/" + String(Buffer[i]);
  }
  //-------------------------------------


  if (client.connect(SCADA_SERVER, SCADA_PORT)) {
    if (debug)Serial.println("connected to server");
    //-------------------------------------
    client.println(str);
    client.println("Host: ");
    client.println("Connection: close");
    client.println();
    //-------------------------------------
    if (debug)Serial.println("Data " + str + " sended");

    client.stop();
    return true;
  }
  else {
    if (debug)Serial.println("connection failed");
    WiFi.end();
    if (debug)Serial.println("reboot system");
    NVIC_SystemReset();
    return false;
  }
}
