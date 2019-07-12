#ifndef WIFI_MODULE_H
#define WIFI_MODULE_H

#include <Arduino.h>
#include "WiFi101.h"
#include "config.h"

class Wifi_Module {
  public:
    Wifi_Module();
    bool wifiConnected();
    void printMacAddress();
    void listNetworks();
    void printEncryptionType(int thisType);
    void wifiConnect(String ssid, String pass, bool debug);
    bool sendData(double *Buffer, int Size=1, bool debug=true);
};

#endif //WIFI_MODULE_H
