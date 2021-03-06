#include "AFTime.h"
#include <StringHelper.h>

using namespace ArduinoFuoco::Utility;

namespace ArduinoFuoco
{

  namespace Entity
  {

    AFTime::AFTime()
        : _hour(12), _minute(0), _is_pm(false)
    {
    }

    AFTime::AFTime(const byte hour, const byte minute, const bool is_pm)
        : _hour(hour), _minute(minute), _is_pm(is_pm)
    {
    }

    byte AFTime::getMinute() const
    {
      return _minute;
    }

    byte AFTime::getHour() const
    {
      return _hour;
    }

    byte AFTime::getHour24() const
    {
      if (_hour == 12)
      {
        if (_is_pm) { return 12; }
        else { return 0; }
      }
      else if (_is_pm)
      {
        return _hour + 12;
      }
      else
      {
        return _hour;
      }
    }

    bool AFTime::isPm() const
    {
      return _is_pm;
    }

    void AFTime::increment()
    {
      incrementMinute();
    }

    void AFTime::decrement()
    {
      decrementMinute();
    }

    String AFTime::toString() const
    {
      String strTime = "00:00 am";
      if (_is_pm) { strTime[6] = 'p'; }
      strTime[0] = StringHelper::itoa(_hour / 10)[0];
      strTime[1] = StringHelper::itoa(_hour % 10)[0];
      strTime[3] = StringHelper::itoa(_minute / 10)[0];
      strTime[4] = StringHelper::itoa(_minute % 10)[0];
      return strTime;
    }

    void AFTime::incrementMinute()
    {
      _minute += 15;
      if (_minute == 60)
      {
        incrementHour();
        _minute = 0;
      }
    }

    void AFTime::decrementMinute()
    {
      // byte is unsigned, so can't simply subtract 15 and check if it's negative
      if (_minute == 0)
      {
        decrementHour();
        _minute = 45;
      }
      else
      {
        _minute -= 15;
      }
    }

    void AFTime::incrementHour()
    {
      _hour++;
      if (_hour == 12)
      {
        _is_pm = !_is_pm;
      }
      if (_hour > 12)
      {
        _hour = 1;
      }
    }

    void AFTime::decrementHour()
    {
      _hour--;
      if (_hour == 11)
      {
        _is_pm = !_is_pm;
      }
      if (_hour < 1)
      {
        _hour = 12;
      }
    }

  }

}

