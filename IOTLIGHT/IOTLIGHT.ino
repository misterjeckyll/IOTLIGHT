/** 25/12/2018
 *  MADE BY WILLIAM PANTRY
 * 
 * IOT LIGHTS
 * A fun project using wemos D1 mini + Neopixel strip (40 led per meter black 2mA/leds)
 * 
 * !warning! Neopixel strips are very curent consuming ! 
 *  you can shot your microcontoller or neopixel strip if you're no careful:
 * - Neopixels alimentation and microcontroller alimentation
 *    -> do not directly power Neopixels from the VIN or 5v PIN of your microconroler
 *    -> or 
 * - 2A 5v alim ae the best in this situation 
 * - protect your microcontroler from false contacts
 * 
 */
// LIBRARIES -----------------------------------------------------
#include <WiFiManager.h> //<- cool stuff
#include <ArduinoOTA.h> // <- wicked
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Adafruit_NeoPixel.h> // <- flashy

// PARAMETERS ----------------------------------------------------
#define PIN D4 //neopixel data pin
#define NBLED 290

// GLOBAL VARIABLES -----------------------------------------------
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NBLED, PIN, NEO_RGB + NEO_KHZ800);

// INITIAL SETUP -------------------------------------------------
void setup(void){
  Serial.begin(115200);
  wifi_setup();
  OTA_setup();
  server_setup();
  leds_setup();
}

// MAIN LOOP -----------------------------------------------------
void loop(void){
  OTA_loop();
  server_loop();
  leds_loop();
}

