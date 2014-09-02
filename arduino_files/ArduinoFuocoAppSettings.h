#ifndef ArduinoFuocoAppSettings_h
#define ArduinoFuocoAppSettings_h

// Declare a 'byte' datatype to be used throughout this library
typedef unsigned char byte;

// Define application constants
const int HYSTERESIS = 0;


// Set debug mode: 1 = on; 0 = off
#define AF_DEBUG 1


// if in debug mode, include Arduino.h for Serial output & printing
#if (ARDUINO >= 100)
  #include "Arduino.h"
#endif

#endif
