#include <Zone.h>
#include "ZoneController.h"

RadiantHeat::Controllers::ZoneController::ZoneController(const byte numZones)
    : _maxZones(numZones), _zoneCount(0)
{
  _zones = new Zone[numZones];
}

RadiantHeat::Controllers::ZoneController::~ZoneController()
{
  delete[] _zones;
}

void RadiantHeat::Controllers::ZoneController::addZone(Zone &zone)
{
  if ((_zoneCount + 1) < _maxZones)
  {
    _zones[_zoneCount] = &zone;
    _zoneCount++;
  }
  else
  {
    throw std::out_of_range ("There is no room for more zones in this controller.");
  }
}

void RadiantHeat::Controllers::ZoneController::heatHouse()
{
/*
  for (Zone zone : zones) {
    Setting* setting = zone.getSetting(currentInterval);
	if (setting->getTemperature() < (zone.getTemperature() - HYSTERESIS)) {
	  zone.turnOn();
	}
	else if (setting->getTemperature() > (zone.getTemperature() + HYSTERESIS)) {
	  zone.turnOff();
	}
  }
*/
}
