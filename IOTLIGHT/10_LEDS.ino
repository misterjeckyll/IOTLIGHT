// COMPILER PREPROCESSING ---------------------------------------

enum command {OFF, THEATER, SPARKLE, SPARK, SPOT, FLAME};
static const char *stateStr[] = {"off","theater","sparkle","spark","spot","flame"};

// GLOBAL VARIABLES -----------------------------------------------
command state=OFF;//by default the first val of the state enum

long nextupdate = millis();//present time
int red = 226;
int green = 88;
int blue = 34;
int interval = 200;//miliseconds
int brightness = 5;// min 0 max 255

// SETUP ----------------------------------------------------------
void leds_setup(){
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// LOOP -----------------------------------------------------------
void leds_loop(){
  switch(state){
    case OFF:     setAll(0,0,0,0);break;
    case SPARKLE: sparkle(red,green,blue, interval, brightness);break;
    case SPARK:   spark(red, green, blue, interval, brightness);break;
    case SPOT:    spot(red, green, blue, interval, brightness);break;
    case THEATER: theater(red, green, blue, interval, brightness);break;
    //case FLAME:   flame(red, green, blue, brightness);break;
    default: state = OFF;
  }
}
