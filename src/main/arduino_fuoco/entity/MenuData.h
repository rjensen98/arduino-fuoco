#ifndef MenuData_h
#define MenuData_h

#include <ArduinoFuocoAppSettings.h>
#include <AFTime.h>
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
        ~MenuData();
        void setCurrentMenuId(byte menuId);
        byte getCurrentMenuId() const;
        void setCurrentZoneId(byte zoneId);
        byte getCurrentZoneId() const;
        void setCurrentAFTime(const AFTime &time);
        AFTime* getCurrentAFTime();

      private:
        byte _currentMenuId;
        byte _currentZoneId;
        byte* _zoneCount;
        Zone** _zones;
        AFTime _currentTime;  // not necessarily Time.now; just a holder for a particular time at hand for the given menu context
    };

  }

}

#endif // MenuData_h
