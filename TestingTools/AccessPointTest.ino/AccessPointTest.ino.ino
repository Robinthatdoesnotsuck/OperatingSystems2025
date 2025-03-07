#include <WiFi.h>

const char* ssid     = "ESP32-Class-Access-Point";
const char* password = "super_secure";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
