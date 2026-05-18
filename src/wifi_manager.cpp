#include "wifi_manager.h" //Include the header file (Function Declaration)
#include <WiFi.h> // Wifi library for the ESP32 Functions 

bool connectWiFi(const char* ssid, const char* password) {  //connect to wifi network return true if succeddful false if failed 
  Serial.print("Connecting to WiFi"); //print status message to serial monitor 
  WiFi.begin(ssid, password);  // start wifi connection with given credentials 
  
  int attempts = 0; // Counter for given attempts 
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {   //Try to connect upto 10 seconds 
    delay(500);  // wait half a second 
    Serial.print(".");  //Print progress dot 
    attempts++;      // Increment counter 
  }
  
  if (WiFi.status() == WL_CONNECTED) { //Checking if we successfully connected it or not 
    Serial.println("\nConnected!");    
    Serial.print("IP: ");              // Success print confirmation
    Serial.println(WiFi.localIP());
    return true;
  }
  
  Serial.println("\nFailed!"); // Connection failed 
  return false;
}

// check if Wifi is connected return true if connected, false if not 
bool isWiFiConnected() {                  
  return WiFi.status() == WL_CONNECTED;
}

// Get the ESP32's IP addresses as a string
String getIPAddress() {                     
  return WiFi.localIP().toString();
}