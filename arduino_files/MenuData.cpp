#include "MenuData.h"

namespace ArduinoFuoco
{

  namespace Entity
  {

    MenuData::MenuData(Zone** zones, byte* zoneCount)
        : _zones(zones), _zoneCount(zoneCount)
    {
    }

  }

}

