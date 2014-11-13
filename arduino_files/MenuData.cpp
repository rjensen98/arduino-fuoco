#include "MenuData.h"
#include "AFTime.h"

namespace ArduinoFuoco
{

  namespace Entity
  {

    MenuData::MenuData(Zone** zones, byte* zoneCount)
        : _zones(zones), _zoneCount(zoneCount), _currentMenuId(0), _currentZoneId(0),
        _currentTime(AFTime())
    {
    }

    MenuData::~MenuData()
    {
    }

    void MenuData::setCurrentMenuId(byte menuId)
    {
      _currentMenuId = menuId;
    }

    byte MenuData::getCurrentMenuId() const
    {
      return _currentMenuId;
    }

    void MenuData::setCurrentZoneId(byte zoneId)
    {
      _currentZoneId = zoneId;
    }

    byte MenuData::getCurrentZoneId() const
    {
      return _currentZoneId;
    }

    void MenuData::setCurrentAFTime(const AFTime &time)
    {
      _currentTime = AFTime(time.getHour(), time.getMinute(), time.isPm());
    }

    AFTime* MenuData::getCurrentAFTime()
    {
      return &_currentTime;
    }

  }

}

