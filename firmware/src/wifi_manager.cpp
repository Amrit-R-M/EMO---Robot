// Include our header file (function declarations)
#include "wifi_manager.h"

// Include WiFi library for ESP32 WiFi functions
#include <WiFi.h>

// Connect to WiFi network
// Returns true if successful, false if failed
bool connectWiFi(const char* ssid, const char* password) {
  
  // Print status message to Serial Monitor
  Serial.print("Connecting to WiFi");
  
  // Start WiFi connection with given credentials
  WiFi.begin(ssid, password);
  
  // Counter for connection attempts
  int attempts = 0;
  
  // Try to connect for up to 10 seconds (20 attempts × 500ms)
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);  // Wait half a second
    Serial.print(".");  // Print progress dot
    attempts++;  // Increment counter
  }
  
  // Check if we successfully connected
  if (WiFi.status() == WL_CONNECTED) {
    // Success! Print confirmation
    Serial.println("\nConnected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    return true;
  }
  
  // Connection failed
  Serial.println("\nFailed!");
  return false;
}

// Check if WiFi is currently connected
// Returns true if connected, false if not
bool isWiFiConnected() {
  return WiFi.status() == WL_CONNECTED;
}

// Get the ESP32's IP address as a String
// Returns IP like "192.168.1.42"
String getIPAddress() {
  return WiFi.localIP().toString();
}