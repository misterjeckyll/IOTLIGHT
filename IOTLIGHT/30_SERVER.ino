// GLOBAL VARIABLES -----------------------------------------------
ESP8266WebServer server(80);

void server_setup(){
  server.begin();
  Serial.println("HTTP server started");
  handlehttp();
}

void server_loop(){
  server.handleClient();
}

void handlehttp(){
  server.on("/", sendcontent);
  server.on("/state", [](){
    String request = server.arg("s");
    for(int i=0;i<6;i++){
      if(request == stateStr[i])state = (command)i;
    }
    sendcontent();
    });
  server.on("/theater",   [](){state=THEATER; sendcontent();});
  server.on("/sparkle",   [](){state=SPARKLE; sendcontent();});
  server.on("/spark",     [](){state=SPARK;   sendcontent();});
  server.on("/spot",      [](){state=SPOT;    sendcontent();});
  server.on("/flame",     [](){state=FLAME;   sendcontent();});
  server.on("/off",       [](){state=OFF;     sendcontent();});
  
  server.on("/interval",  [](){ interval = server.arg("i").toInt();});
  server.on("/brightness", [](){brightness = server.arg("b").toInt();});

  server.on("/couleur", []() {
    if (server.hasArg("r")) red = server.arg("r").toInt();
    if (server.hasArg("g")) green = server.arg("g").toInt();
    if (server.hasArg("b")) blue = server.arg("b").toInt();
    sendcontent();
  });
  server.onNotFound(handleNotFound);
}

void handleNotFound(){
  digitalWrite(LED_BUILTIN, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(LED_BUILTIN, 0);
}

