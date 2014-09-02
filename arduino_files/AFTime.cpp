#include <string>
#include "AFTime.h"

namespace ArduinoFuoco
{

  namespace Entity
  {

    AFTime::AFTime()
        : _hour(12), _minute(0), _is_pm(false)
    {
    }

    AFTime::AFTime(byte hour, byte minute, bool is_pm)
        : _hour(hour), _minute(minute), _is_pm(is_pm)
    {
    }

    void AFTime::increment()
    {
      incrementMinute();
    }

    void AFTime::decrement()
    {
      decrementMinute();
    }

    std::string AFTime::toString()
    {
      std::string strTime = "00:00 am";
      if (_is_pm) { strTime[6] = 'p'; }
      strTime[0] = _hour / 10;
      strTime[1] = _hour % 10;
      strTime[3] = _minute / 10;
      strTime[4] = _minute % 10;
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
      if (_hour > 12)
      {
        _is_pm = !_is_pm;
        _hour = 1;
      }
    }

    void AFTime::decrementHour()
    {
      _hour--;
      if (_hour < 1)
      {
        _is_pm = !_is_pm;
        _hour = 12;
      }
    }

  }

}

