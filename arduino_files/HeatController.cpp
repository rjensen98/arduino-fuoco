#include "HeatController.h"
#include "Circulator.h"
#include <stdexcept>
#include "TimeDefinition.h"
#include "Zone.h"
#include "ZoneSetting.h"

using namespace ArduinoFuoco::Entity;

namespace ArduinoFuoco
{
  namespace Controllers
  {

    HeatController::HeatController(const byte numZones)
        : _maxZones(numZones), _zoneCount(0), _circulatorCount(0)
    {
      _zones = new Zone*[numZones];
      _circulators = new Circulator*[MAX_CIRCULATORS];
    }

    HeatController::~HeatController()
    {
      delete[] _zones;
      delete[] _circulators;
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

    void HeatController::addCirculator(Circulator &circ)
    {
      if ((_circulatorCount + 1) < MAX_CIRCULATORS)
      {
        _circulators[_circulatorCount] = &circ;
        _circulatorCount++;
      }
      else
      {
        throw std::out_of_range ("There is no room for more circulators in this controller.");
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
      Zone* z = 0;
      for (int i = 0; i < _zoneCount; i++)
      {
        if (_zones[i]->getNumber() == zoneId)
        {
          z = _zones[i];
          return z;
        }
      }
      return z;
    }

    Circulator* HeatController::getCirculator(CirculatorType::Enum circType)
    {
      Circulator* c = 0;
      for (int i = 0; i < _circulatorCount; i++)
      {
        if (_circulators[i]->getCirculatorType() == circType)
        {
          c = _circulators[i];
          return c;
        }
      }
      return c;
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
