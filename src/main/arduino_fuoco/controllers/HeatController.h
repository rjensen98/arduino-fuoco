#ifndef HeatController_h
#define HeatController_h

#include <ArduinoFuocoAppSettings.h>
#include <Circulator.h>
#include <CirculatorType.h>
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
        void addCirculator(Circulator &zone);
        void heatHouse();
        TimeDefinition* getTimeDefinitions();
    //    TimePeriod; TimeOfDay;

      private:
        byte _maxZones;
        byte _zoneCount;
        Zone** _zones;
        Zone* getZone(byte zoneId);
        byte _circulatorCount;
        Circulator** _circulators;
        Circulator* getCirculator(CirculatorType::Enum circType);

        HeatingInterval::Enum getCurrentInterval();
    };
  }
}

#endif
