#ifndef RadiantHeatAppSettings_h
#define RadiantHeatAppSettings_h

// Declare a 'byte' datatype to be used throughout this library
typedef unsigned char byte;


// Set debug mode: 1 = on; 0 = off
#define RH_DEBUG 1


// if in debug mode, include Arduino.h for Serial output & printing
#if (ARDUINO >= 100)
  #include "Arduino.h"
#endif

#endif
