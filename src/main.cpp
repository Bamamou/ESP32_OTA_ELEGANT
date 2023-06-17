 /*
  AsyncElegantOTA Demo Example - This example will work for both ESP8266 & ESP32 microcontrollers.
  -----
  Author: Ayush Sharma ( https://github.com/ayushsharma82 )
  
  Important Notice: Star the repository on Github if you like the library! :)
  Repository Link: https://github.com/ayushsharma82/AsyncElegantOTA
*/
// /******************************************************************************
//  * main.cpp
//  * C plus plus function for the main file
//  *****************************************************************************/

#include "Arduino.h"
#include "main.h"
AsyncWebServer server(80);


void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


  // Make it possible to access webserver at http://myEsp32Ota.local
  if (!MDNS.begin(hostname)) {
    Serial.println("Error setting up mDNS responder!");
  } else {
    Serial.printf("Access at http://%s.local/update\n", hostname); // I added the update to directly update 
                                                                  // but it can modified to first have access to the below 
  }

  // Show a link to OTA page at http://myEsp32.local
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String html = "<html><body>";
    html += "<a href=\"/ota\">Update Software</a>";
    html += "</body></html>";
   request->send(200, "text/plain", "Hi! and Welcom.");
  });

  AsyncElegantOTA.begin(&server);    // Start AsyncElegantOTA
  server.begin();
 // Serial.println("HTTP server started on myEPS32OTA");
}

void loop(void) 
{ 
}