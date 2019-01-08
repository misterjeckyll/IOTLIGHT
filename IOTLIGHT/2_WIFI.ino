void wifi_setup(){
  WiFiManager wifiManager;
  //wifiManager.resetSettings();
  wifiManager.setTimeout(400);
  wifiManager.autoConnect("AutoConnectAP");
}

void OTA_setup() {
  ArduinoOTA.setHostname("IOTLIGHT");
  //ArduinoOTA.setPassword('admin');

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";
  });
  ArduinoOTA.onEnd([]() {});
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {});  
  ArduinoOTA.onError([](ota_error_t error) {});
  ArduinoOTA.begin(); 
}

void OTA_loop(){
  ArduinoOTA.handle();
}

