#include <HeatingInterval.h>
#include "ZoneSetting.h"

RadiantHeat::Entity::ZoneSetting::ZoneSetting()
{
  _heatingInterval = RadiantHeat::Enums::HeatingInterval::WKDAY_WAKE;
  _temperature = 0;
}

RadiantHeat::Entity::ZoneSetting::ZoneSetting(const RadiantHeat::Enums::HeatingInterval::Enum &interval, const byte &temperature)
    : _heatingInterval(interval), _temperature(temperature)
{
}

byte RadiantHeat::Entity::ZoneSetting::getSetTemperature()
{
  return _temperature;
}

void RadiantHeat::Entity::ZoneSetting::setSetTemperature(const byte temperature)
{
  _temperature = temperature;
}

RadiantHeat::Enums::HeatingInterval::Enum RadiantHeat::Entity::ZoneSetting::getInterval()
{
  return _heatingInterval;
}

void RadiantHeat::Entity::ZoneSetting::setInterval(const RadiantHeat::Enums::HeatingInterval::Enum interval)
{
  _heatingInterval = interval;
}
