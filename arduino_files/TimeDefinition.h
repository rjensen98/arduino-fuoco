#ifndef AF_TimeDefinition_h
#define AF_TimeDefinition_h

#include <ArduinoFuocoAppSettings.h>
#include <AFTime.h>
#include <HeatingInterval.h>

using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{

  namespace Entity
  {

    class TimeDefinition
    {
      public:
        TimeDefinition();
        TimeDefinition(HeatingInterval::Enum interval, AFTime time);
        HeatingInterval::Enum getInterval() const;
        void setInterval(HeatingInterval::Enum interval);
        AFTime getTime() const;
        void setTime(const AFTime time);

      private:
        HeatingInterval::Enum _interval;
        AFTime _time;
    };

  }

}

#endif // AF_TimeDefinition_h
