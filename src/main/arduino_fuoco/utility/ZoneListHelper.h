#ifndef ZoneListHelper_h
#define ZoneListHelper_h

#include <Zone.h>

using namespace ArduinoFuoco::Entity;

namespace ArduinoFuoco
{

  namespace Utility
  {

    class ZoneListHelper
    {
      public:
        static Zone* getZone(Zone** &zones, const byte &zoneCount, const byte &zoneId);
    };

  }

}

#endif // ZoneListHelper_h
