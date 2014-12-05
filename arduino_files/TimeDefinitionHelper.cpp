#include "TimeDefinitionHelper.h"
#include <AFTime.h>
#include <HeatingInterval.h>
#include <Time.h>
#include <TimeDefinition.h>

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{

  namespace Utility
  {

    HeatingInterval::Enum TimeDefinitionHelper::getCurrentHeatingInterval(const TimeDefinition* definitions)
    {
      int currentHour = hour();
      int currentMinute = minute();
      int dayOfWeek = weekday();
      bool isWeekend = dayOfWeek == dowSunday || dayOfWeek == dowSaturday;
      int tmpHour = 0;
      int tmpMinute = 0;

      // Default the interval to (WKDAY|WKEND)_SLEEP; assuming SLEEP between midnight and _WAKE interval
      HeatingInterval::Enum heatingInterval = HeatingInterval::WKDAY_SLEEP;
      if (isWeekend)
      {
        heatingInterval = HeatingInterval::WKEND_SLEEP;
      }

      // Find the MAX time in the definitions that's LESS than the current time
      for (int i = 0; i < HeatingInterval::COUNT; i++)  // Definitions should have 1 entry for each HeatingInterval. No more!  No less!
      {
        // Only bother if it's a weekday and the current def's interval is weekday (or both are weekend)
        if (isWeekend == HeatingInterval::isWeekendInterval[definitions[i].getInterval()]) {
          int defHour24 = definitions[i].getTime().getHour24();
          int defMinute = definitions[i].getTime().getMinute();
          if (currentHour >= defHour24 && currentMinute >= defMinute &&
              (defHour24 > tmpHour || (defHour24 == tmpHour && defMinute >= tmpMinute)))
          {
            tmpHour = defHour24;
            tmpMinute = defMinute;
            heatingInterval = definitions[i].getInterval();
          }
        }
      }

      return heatingInterval;
    }

  }

}

