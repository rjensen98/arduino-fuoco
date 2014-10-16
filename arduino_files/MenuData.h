#ifndef MenuData_h
#define MenuData_h

#include <ArduinoFuocoAppSettings.h>
#include <Zone.h>

using namespace ArduinoFuoco::Entity;

namespace ArduinoFuoco
{

  namespace Entity
  {

    class MenuData
    {
      public:
        MenuData(Zone** zones, byte* zoneCount);

      private:
        byte _currentMenuId;
        byte _currentZoneId;
        byte* _zoneCount;
        Zone** _zones;
    };

  }

}

#endif // MenuData_h
