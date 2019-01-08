//----------------------------------------------------------
// RGB EFFECTS                             
//----------------------------------------------------------

unsigned long previousloop = millis();

int offset = 0;
void theater(int red, int green, int blue, int interval,int brightness){
  if(millis() >= nextupdate){
    setAll(0, 0, 0, 0);
    if(offset>=3)offset = 0;
    offset++;
    for(int led = 0; led < strip.numPixels(); led+=3)
      setcolor(led+offset, red, green, blue, brightness);
    strip.show();
    nextupdate = millis() + interval;
  }
}

void spot(int red, int green, int blue, int interval, int brightness){
  if(millis() >= nextupdate){
    for(int num = 0; num < 10; num++){
      setcolor(randled(), red, green, blue, brightness);
    }
    nextupdate = millis() + interval;
    strip.show();
  }
  setAll(0, 0, 0, 0);
  strip.show();
}

void spark(int red, int green, int blue, int interval, int brightness){
    if(millis() - previousloop >= interval){
      if(millis() <= nextupdate){
        setcolor(randled(),red, green, blue, brightness);
      }else{
        if(millis() <= nextupdate+10000){
          setcolor(randled(),0, 0, 0, brightness);
        }else{
          nextupdate = millis(); 
        }
      }
    strip.show();
    previousloop = millis();
  }
}

//FLAME EFFECT -----------------------------------
/*int present_delta[5];
int target_delta[5];

void flame(int red, int green, int blue, int brightness){
  if(millis() >= nextupdate){
    nextupdate = millis() + 100;
      for(int led = 0; led < 10; led++){
        if((target_delta[led]-present_delta[led])< 0){
          present_delta[led]-=1;
        }
        if(target_delta[led]-present_delta[led] > 0){
          present_delta[led]+=1;
        }else{
          target_delta[led] = random(0,150);
        }
      }
      for(int led = 0; led < strip.numPixels();led++){
        int newr = red -present_delta[led%5];
        int newg = green - present_delta[led%5];
        int newb = blue - present_delta[led%5];
        if(newg<0) newg=0;
        if(newr<0) newr=0;
        if(newb<0) newb=0;
        setcolor(led, newr, newg, newb, brightness);
      }
      strip.show(); 
  }
}*/
/*
void fadeInOut(int red, int green, int blue, int wait){
  float red, green, blue;
  for(float k = 0; k < 256; k++) { 
    red = round((k/256.0)*red);
    green = round((k/256.0)*green);
    blue = round((k/256.0)*blue);
    setAll(green, red, blue);
    strip.show();
  }
  for(float k = 255; k >=0; k=k-2) { 
    red = (k/256.0)*red;
    green = (k/256.0)*green;
    blue = (k/256.0)*blue;
    setAll(green, red, blue);
    strip.show();
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
void rainbow(uint8_t wait) {
  if(counter>=256) counter=0;
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel((i+counter) & 255));
  }
  strip.show();
  delay(wait);
}
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  if(counter>=256*5) counter=0;
  for(uint16_t i=0; i< strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + counter) & 255));
  }
  strip.show();
  delay(wait);
}
*/
void sparkle(int red, int green, int blue, int vitesse, int brightness){
  if(millis() >= nextupdate){
    for(int led = 0; led <strip.numPixels(); led++){
      int flicker = random(0,130);
      int newr = red-flicker;
      int newg = green-flicker;
      int newb = blue-flicker;
      if(newg<0) newg=0;
      if(newr<0) newr=0;
      if(newb<0) newb=0;
      setcolor(led, newr, newg, newb, brightness);
    }
    nextupdate = millis() + random(50,130+vitesse);
  }
  strip.show();
}

/*
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  if(counter>=10) counter=0;
  for (int q=0; q < 3; q++) {
    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
      strip.setPixelColor(i+q, c);    //turn every third pixel on
    }
    strip.show();

    delay(wait);

    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
      strip.setPixelColor(i+q, 0);        //turn every third pixel off
    }
  }
}
*/
/*
//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  if(counter>=256) counter=0;
  for (int q=0; q < 3; q++) {
    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
      strip.setPixelColor(i+q, Wheel( (i+counter) % 255));    //turn every third pixel on
    }
    strip.show();

    delay(wait);

    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
      strip.setPixelColor(i+q, 0);        //turn every third pixel off
    }
  }
}
*/

