#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>

// Declare WiFi functions (no code here, just signatures)
bool connectWiFi(const char* ssid, const char* password);
bool isWiFiConnected();
String getIPAddress();

#endif