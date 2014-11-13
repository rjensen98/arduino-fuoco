#include "ZoneSetting.h"
#include <HeatingInterval.h>

namespace ArduinoFuoco
{

  namespace Entity
  {

    ZoneSetting::ZoneSetting()
    {
      _heatingInterval = ArduinoFuoco::Enums::HeatingInterval::WKDAY_WAKE;
      _temperature = 0;
    }

    ZoneSetting::ZoneSetting(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval, const byte &temperature)
        : _heatingInterval(interval), _temperature(temperature)
    {
    }

    byte ZoneSetting::getSetTemperature() const
    {
      return _temperature;
    }

    void ZoneSetting::setSetTemperature(const byte &temperature)
    {
      _temperature = temperature;
    }

    ArduinoFuoco::Enums::HeatingInterval::Enum ZoneSetting::getInterval() const
    {
      return _heatingInterval;
    }

    void ZoneSetting::setInterval(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval)
    {
      _heatingInterval = interval;
    }

  }
}
