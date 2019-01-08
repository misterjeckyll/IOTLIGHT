


uint16_t randled(){
  return (uint16_t)random(strip.numPixels());
}

void setcolor(int n, int red, int green, int blue, int brightness){
  strip.setPixelColor(n, (brightness*green/255) , (brightness*red/255), (brightness*blue/255));
}


void setAll(int red, int green, int blue, int brightness){
  for(int led=0; led<strip.numPixels(); led++) {
    setcolor(led, red, green, blue, brightness);
  }
  strip.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
