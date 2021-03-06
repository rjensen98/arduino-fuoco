#include "HeatController.h"
#include "Arduino.h"
#include "Circulator.h"
#include "CirculatorType.h"
#include <stdexcept>
#include "Time.h"
#include "Zone.h"
#include "ZoneListHelper.h"
#include "ZoneSetting.h"

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;
using namespace ArduinoFuoco::Utility;

namespace ArduinoFuoco
{
  namespace Controllers
  {

    HeatController::HeatController(const byte numZones)
        : _maxZones(numZones), _zoneCount(0), _circulatorCount(0), _zonesRunning(0)
    {
      _zones = new Zone*[numZones];
      _circulators = new Circulator*[ArduinoFuoco::AppSettings::MAX_CIRCULATORS];
      setTime(0, 0, 0, 1, ArduinoFuoco::AppSettings::SET_TIME_START_MONTH, ArduinoFuoco::AppSettings::SET_TIME_START_YEAR);  // setTime(hr,min,sec,day,month,yr);
      setup();
    }

    HeatController::~HeatController()
    {
      delete[] _zones;
      delete[] _circulators;
    }

    void HeatController::setup()
    {
      // Reset all the zones
      for (int i = 0; i < _zoneCount; i++)
      {
        _zones[i]->setup();
      }

      // Reset all the circulators
      for (int i = 0; i < _circulatorCount; i++)
      {
        _circulators[i]->setup();
      }

      // Wait just a bit for some "cool-off" (relays, pumps, etc.)
      delay(5000);
    }

    void HeatController::addZone(Zone &zone)
    {
      if ((_zoneCount + 1) <= _maxZones)
      {
        _zones[_zoneCount] = &zone;
        _zoneCount++;
      }
      else
      {
        #if (AF_DEBUG == 1)
          Serial.println("ArduinoFuoco::Controllers::HeatController::addZone - There is no room for more zones in this controller.");
        #endif
      }
    }

    void HeatController::addCirculator(Circulator &circ)
    {
      if ((_circulatorCount + 1) <= ArduinoFuoco::AppSettings::MAX_CIRCULATORS)
      {
        _circulators[_circulatorCount] = &circ;
        _circulatorCount++;
      }
      else
      {
        #if (AF_DEBUG == 1)
          Serial.println("ArduinoFuoco::Controllers::HeatController::addCirculator - There is no room for more circulators in this controller.");
        #endif
      }
    }

    void HeatController::heatHouse()
    {
      for (int i = 0; i < _zoneCount; i++)
      {
        Zone* zone = _zones[i];
        ZoneSetting* setting = zone->getCurrentZoneSetting();
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

    Zone* HeatController::getZone(const byte &zoneId)
    {
      return ZoneListHelper::getZone(_zones, _zoneCount, zoneId);
    }

    Zone** HeatController::getZones()
    {
      return _zones;
    }

    byte HeatController::getZoneCount() const
    {
      return _zoneCount;
    }

    byte* HeatController::getZoneCountRef()
    {
      return &_zoneCount;
    }

    Circulator* HeatController::getCirculator(const CirculatorType::Enum &circType)
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

    void HeatController::runCirculator(Circulator* circ)
    {
      if (circ)
      {
        #if (AF_DEBUG == 1)
          Serial.print("ArduinoFuoco::Controllers::HeatController::runCirculator - Running circulator; _zonesRunning = ");
          Serial.println(_zonesRunning, DEC);
        #endif
        circ->run(_zonesRunning == 0);
      }
      #if (AF_DEBUG == 1)
        else
        {
          Serial.println("ArduinoFuoco::Controllers::HeatController::runCirculator - Reference to circulator object not found!");
        }
      #endif
    }

    void HeatController::runPrimaryCirculator()
    {
      #if (AF_DEBUG == 1)
        Serial.println("ArduinoFuoco::Controllers::HeatController::runPrimaryCirculator - Finding primary circulator...");
      #endif
      runCirculator(getCirculator(CirculatorType::PRIMARY));
    }

    void HeatController::runBoilerCirculator()
    {
      #if (AF_DEBUG == 1)
        Serial.println("ArduinoFuoco::Controllers::HeatController::runPrimaryCirculator - Finding boiler circulator...");
      #endif
      runCirculator(getCirculator(CirculatorType::BOILER));
    }

  }
}
