#ifndef AFTime_H
#define AFTime_H

#include <ArduinoFuocoAppSettings.h>
#include <string>

namespace ArduinoFuoco
{

  namespace Entity
  {

    class AFTime
    {
      public:
        AFTime();
        AFTime(byte hour, byte minute, bool is_pm);
        byte getMinute();
        byte getHour();
        bool isPm();
        void increment(); //TODO: think about implementing the ++ operator
        void decrement(); //TODO: think about implementing the -- operator
        std::string toString();

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
