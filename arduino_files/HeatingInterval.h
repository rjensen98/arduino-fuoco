#ifndef HeatingInterval_h
#define HeatingInterval_h

namespace ArduinoFuoco
{
  namespace Enums
  {
    namespace HeatingInterval
    {
      enum Enum { WKDAY_WAKE = 0, WKDAY_AWAY, WKDAY_RETURN, WKDAY_SLEEP, WKEND_WAKE, WKEND_AWAY, WKEND_RETURN, WKEND_SLEEP, COUNT };

      const bool isWeekendInterval[] = { false, false, false, false, true, true, true, true, false };
    };
  }
}

#endif
