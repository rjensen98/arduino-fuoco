#include "HeatController.h"
#include "Circulator.h"
#include "CirculatorType.h"
#include <stdexcept>
#include "TimeDefinition.h"
#include "Zone.h"
#include "ZoneSetting.h"

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{
  namespace Controllers
  {

    HeatController::HeatController(const byte numZones)
        : _maxZones(numZones), _zoneCount(0), _circulatorCount(0), _zonesRunning(0)
    {
      _zones = new Zone*[numZones];
      _circulators = new Circulator*[ArduinoFuoco::AppSettings::MAX_CIRCULATORS];
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
        #if (AF_DEBUG == 1)
          Serial.println("ArduinoFuoco::Entity::HeatController::addZone - There is no room for more zones in this controller.");
        #endif
      }
    }

    void HeatController::addCirculator(Circulator &circ)
    {
      if ((_circulatorCount + 1) < ArduinoFuoco::AppSettings::MAX_CIRCULATORS)
      {
        _circulators[_circulatorCount] = &circ;
        _circulatorCount++;
      }
      else
      {
        #if (AF_DEBUG == 1)
          Serial.println("ArduinoFuoco::Entity::HeatController::addCirculator - There is no room for more circulators in this controller.");
        #endif
      }
    }

    void HeatController::heatHouse()
    {
      for (int i = 0; i < _zoneCount; i++)
      {
        Zone* zone = _zones[i];
        ZoneSetting* setting = zone->getZoneSetting(getCurrentInterval());
        if (!zone->isOn() && zone->getCurrentTemperature() < (setting->getSetTemperature() - ArduinoFuoco::AppSettings::HYSTERESIS)) {
          zone->turnOn();
          _zonesRunning++;
          runPrimaryCirculator();
        }
        else if (zone->isOn() && zone->getCurrentTemperature() > (setting->getSetTemperature() + ArduinoFuoco::AppSettings::HYSTERESIS)) {
          zone->turnOff();
          _zonesRunning--;
          runPrimaryCirculator();
        }

        runBoilerCirculator();
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

    void HeatController::runCirculator(Circulator* circ)
    {
      if (circ)
      {
        #if (AF_DEBUG == 1)
          Serial.print("ArduinoFuoco::Entity::HeatController::runCirculator - Running circulator; _zonesRunning = ");
          Serial.println(_zonesRunning, DEC);
        #endif
        circ->run(_zonesRunning == 0);
      }
      #if (AF_DEBUG == 1)
        else
        {
          Serial.println("ArduinoFuoco::Entity::HeatController::runCirculator - Reference to circulator object not found!");
        }
      #endif
    }

    void HeatController::runPrimaryCirculator()
    {
      #if (AF_DEBUG == 1)
        Serial.println("ArduinoFuoco::Entity::HeatController::runPrimaryCirculator - Finding primary circulator...");
      #endif
      runCirculator(getCirculator(CirculatorType::PRIMARY));
    }

    void HeatController::runBoilerCirculator()
    {
      #if (AF_DEBUG == 1)
        Serial.println("ArduinoFuoco::Entity::HeatController::runPrimaryCirculator - Finding boiler circulator...");
      #endif
      runCirculator(getCirculator(CirculatorType::BOILER));
    }

  }
}
