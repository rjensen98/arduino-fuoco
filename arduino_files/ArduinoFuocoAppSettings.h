#ifndef ArduinoFuocoAppSettings_h
#define ArduinoFuocoAppSettings_h

#ifndef Arduino_h
  // Declare "custom" datatypes (from Arduino) to be used throughout this library
  #include "WString.h"
  typedef unsigned char byte;
#endif


// Define application constants
namespace ArduinoFuoco
{
  namespace AppSettings
  {
    /***********************************************
    **  Temperature-related constants
    ***********************************************/
    const byte HYSTERESIS = 0;
    const byte BOILER_SHUTOFF_TEMP = 120;  // temperature (^F) at which to turn the boiler circulator off

    /***********************************************
    **  Time-related constants
    ***********************************************/
    // Constants for initializing Time using the setTime() method
    const byte SET_TIME_START_MONTH = 6;  // June 2014 starts on a Sunday; it helps with weekday() == 1 == Sunday == day()
    const int SET_TIME_START_YEAR = 2014;  // June 2014 (see above)

    // Constant for any menu displays that should scroll / alternate after a given interval
    const byte TIMED_DISPLAY_SCROLL_INTERVAL = 5;

    /***********************************************
    **  Miscellaneous constants
    ***********************************************/
    const byte MAX_CIRCULATORS = 2;  // only allowing 2 for now; have an idea to add a Circ ref to Zone to allow multiple primaries
  }
}

// Set debug mode: 1 = on; 0 = off
#define AF_DEBUG 0


// if in debug mode, include Arduino.h for Serial output & printing
#if (AF_DEBUG == 1)
  #include "Arduino.h"
#endif

#endif
