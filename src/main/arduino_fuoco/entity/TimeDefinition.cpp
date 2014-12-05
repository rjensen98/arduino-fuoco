#include "TimeDefinition.h"
#include <AFTime.h>
#include <HeatingInterval.h>

using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{

  namespace Entity
  {

    TimeDefinition::TimeDefinition()
        : _interval(HeatingInterval::WKDAY_WAKE), _time(AFTime(8, 0, false))
    {
    }

    TimeDefinition::TimeDefinition(HeatingInterval::Enum interval, AFTime time)
        : _interval(interval), _time(time)
    {
    }

    HeatingInterval::Enum TimeDefinition::getInterval() const
    {
      return _interval;
    }

    void TimeDefinition::setInterval(HeatingInterval::Enum interval)
    {
      _interval = interval;
    }

    AFTime TimeDefinition::getTime() const
    {
      return _time;
    }

    void TimeDefinition::setTime(AFTime time)
    {
      _time = time;
    }

  }

}

