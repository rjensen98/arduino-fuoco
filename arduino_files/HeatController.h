#ifndef HeatController_h
#define HeatController_h

#include <ArduinoFuocoAppSettings.h>
#include <TimeDefinition.h>
#include <Zone.h>

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{
  namespace Controllers
  {
    class HeatController
    {
      public:
        HeatController(const byte numZones);
        ~HeatController();
        void addZone(Zone &zone);
        void heatHouse();
        TimeDefinition* getTimeDefinitions();
    //    TimePeriod; TimeOfDay;

      private:
        byte _maxZones;
        byte _zoneCount;
        Zone** _zones;
        Zone* getZone(byte zoneId);
        HeatingInterval::Enum getCurrentInterval();
    };
  }
}

#endif
