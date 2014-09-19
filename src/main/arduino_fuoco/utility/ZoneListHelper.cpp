#include "ZoneListHelper.h"
#include "Zone.h"

using namespace ArduinoFuoco::Entity;

namespace ArduinoFuoco
{

  namespace Utility
  {

    Zone* ZoneListHelper::getZone(Zone** &zones, const byte &zoneCount, const byte &zoneId)
    {
      Zone* z = 0;
      for (int i = 0; i < zoneCount; i++)
      {
        if (zones[i]->getNumber() == zoneId)
        {
          z = zones[i];
          return z;
        }
      }
      return z;
    }

  }

}

