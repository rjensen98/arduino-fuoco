#ifndef AFTime_H
#define AFTime_H

#include <ArduinoFuocoAppSettings.h>

namespace ArduinoFuoco
{

  namespace Entity
  {

    class AFTime
    {
      public:
        AFTime();
        AFTime(const byte hour, const byte minute, const bool is_pm);
        byte getMinute() const;
        byte getHour() const;
        byte getHour24() const;  // hour in a 24-hour format
        bool isPm() const;
        void increment(); //TODO: think about implementing the ++ operator
        void decrement(); //TODO: think about implementing the -- operator
        String toString() const;

      private:
        byte _hour;
        byte _minute;
        bool _is_pm;
        void incrementMinute();
        void decrementMinute();
        void incrementHour();
        void decrementHour();
    };

  }

}

#endif // AFTime_H
