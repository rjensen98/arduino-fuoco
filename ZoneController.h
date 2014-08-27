#ifndef ZoneController_h
#define ZoneController_h

#include <RadiantHeatAppSettings.h>
#include <Zone.h>

using namespace RadiantHeat::Entity;

namespace RadiantHeat
{
  namespace Controllers
  {
    class ZoneController
    {
      public:
        ZoneController(const byte numZones);
        ~ZoneController();
        void addZone(Zone &zone);
        void heatHouse();
    //  TimeDefinitions[]
    //    TimePeriod; TimeOfDay;

      private:
        byte _maxZones;
        byte _zoneCount;
        Zone* _zones;
    };
  }
}

#endif
