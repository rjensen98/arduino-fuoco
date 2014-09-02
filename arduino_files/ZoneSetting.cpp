#include <HeatingInterval.h>
#include "ZoneSetting.h"

ArduinoFuoco::Entity::ZoneSetting::ZoneSetting()
{
  _heatingInterval = ArduinoFuoco::Enums::HeatingInterval::WKDAY_WAKE;
  _temperature = 0;
}

ArduinoFuoco::Entity::ZoneSetting::ZoneSetting(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval, const byte &temperature)
    : _heatingInterval(interval), _temperature(temperature)
{
}

byte ArduinoFuoco::Entity::ZoneSetting::getSetTemperature()
{
  return _temperature;
}

void ArduinoFuoco::Entity::ZoneSetting::setSetTemperature(const byte temperature)
{
  _temperature = temperature;
}

ArduinoFuoco::Enums::HeatingInterval::Enum ArduinoFuoco::Entity::ZoneSetting::getInterval()
{
  return _heatingInterval;
}

void ArduinoFuoco::Entity::ZoneSetting::setInterval(const ArduinoFuoco::Enums::HeatingInterval::Enum interval)
{
  _heatingInterval = interval;
}
