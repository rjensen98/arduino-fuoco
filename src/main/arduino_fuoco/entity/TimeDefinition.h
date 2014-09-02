#ifndef AF_TimeDefinition_h
#define AF_TimeDefinition_h

#include <ArduinoFuocoAppSettings.h>
#include <AFTime.h>
#include <HeatingInterval.h>

namespace ArduinoFuoco
{

  namespace Entity
  {

    class TimeDefinition
    {
    public:
      TimeDefinition();
      TimeDefinition(ArduinoFuoco::Enums::HeatingInterval::Enum interval, AFTime time);
      void setInterval(ArduinoFuoco::Enums::HeatingInterval::Enum interval);
      void setTime(AFTime time);

    private:
      ArduinoFuoco::Enums::HeatingInterval::Enum _interval;
      AFTime _time;
    };

  }

}

#endif // AF_TimeDefinition_h
