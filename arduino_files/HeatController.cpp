#include "HeatController.h"
#include <stdexcept>
#include "TimeDefinition.h"
#include "Zone.h"
#include "ZoneSetting.h"

namespace ArduinoFuoco
{
  namespace Controllers
  {

    HeatController::HeatController(const byte numZones)
        : _maxZones(numZones), _zoneCount(0)
    {
      _zones = new Zone*[numZones];
    }

    HeatController::~HeatController()
    {
      delete[] _zones;
    }

    void HeatController::addZone(Zone &zone)
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

    void HeatController::heatHouse()
    {
      for (int i = 0; i < _zoneCount; i++)
      {
        Zone* zone = _zones[i];
        ZoneSetting* setting = zone->getZoneSetting(getCurrentInterval());
      if (setting->getSetTemperature() < (zone->getCurrentTemperature() - HYSTERESIS)) {
        zone->turnOn();
      }
      else if (setting->getSetTemperature() > (zone->getCurrentTemperature() + HYSTERESIS)) {
        zone->turnOff();
      }
      }
    }

    Zone* HeatController::getZone(byte zoneId)
    {
      for (int i = 0; i < _zoneCount; i++)
      {
        if (_zones[i]->getNumber() == zoneId)
        {
          return _zones[i];
        }
      }
    }

    TimeDefinition* HeatController::getTimeDefinitions()
    {
      //TODO: implement this!!!
      TimeDefinition* junk = 0;
      return junk;
    }

    HeatingInterval::Enum HeatController::getCurrentInterval()
    {
      //TODO: implement this!!!
      return HeatingInterval::WKDAY_WAKE;
    }

  }
}
