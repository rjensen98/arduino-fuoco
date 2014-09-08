#ifndef ArduinoFuocoAppSettings_h
#define ArduinoFuocoAppSettings_h

// Declare a 'byte' datatype to be used throughout this library
typedef unsigned char byte;

// Define application constants
const byte HYSTERESIS = 0;
const byte MAX_CIRCULATORS = 2;  // only allowing 2 for now; have an idea to add a Circ ref to Zone to allow multiple primaries
const byte BOILER_SHUTOFF_TEMP = 120;  // temperature (^F) at which to turn the boiler circulator off


// Set debug mode: 1 = on; 0 = off
#define AF_DEBUG 0


// if in debug mode, include Arduino.h for Serial output & printing
#if (AF_DEBUG == 1)
  #include "Arduino.h"
#endif

#endif
