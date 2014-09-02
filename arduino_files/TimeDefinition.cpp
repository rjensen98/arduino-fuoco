#include "TimeDefinition.h"
#include <AFTime.h>
#include <HeatingInterval.h>

namespace ArduinoFuoco
{

  namespace Entity
  {

    TimeDefinition::TimeDefinition()
        : _interval(ArduinoFuoco::Enums::HeatingInterval::WKDAY_WAKE), _time(AFTime(8, 0, false))
    {
    }

    TimeDefinition::TimeDefinition(ArduinoFuoco::Enums::HeatingInterval::Enum interval, AFTime time)
        : _interval(interval), _time(time)
    {
    }

    void TimeDefinition::setInterval(ArduinoFuoco::Enums::HeatingInterval::Enum interval)
    {
      _interval = interval;
    }

    void TimeDefinition::setTime(AFTime time)
    {
      _time = time;
    }

  }

}

