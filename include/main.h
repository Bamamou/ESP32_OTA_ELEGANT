// /******************************************************************************
//  * main.h
//  * Header for the main file
//  *****************************************************************************/
 #ifndef __MAIN_H__
 #define __MAIN_H__

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "driver/gpio.h"
#include <Arduino.h>
#include "ESPmDNS.h"
#include "AsyncElegantOTA.h"
//#include "Global_Constants.h"
#include "Global_Variables.h"
#include "ESPAsyncWebServer.h"
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <AsyncTCP.h>
#endif

 #endif