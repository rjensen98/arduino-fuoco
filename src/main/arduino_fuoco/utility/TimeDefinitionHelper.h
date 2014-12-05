#ifndef TimeDefinitionHelper_h
#define TimeDefinitionHelper_h

#include <ArduinoFuocoAppSettings.h>
#include <HeatingInterval.h>
#include <Time.h>
#include <TimeDefinition.h>

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{

  namespace Utility
  {

    class TimeDefinitionHelper
    {
      public:
        static HeatingInterval::Enum getCurrentHeatingInterval(const TimeDefinition* definitions);
    };

  }

}

#endif // TimeDefinitionHelper_h
