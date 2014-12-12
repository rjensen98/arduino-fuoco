#include "MenuInitializer.h"
#include "Menu.h"
#include "MenuData.h"
#include "MenuController.h"
#include "StringHelper.h"
#include "Time.h"
#include "Zone.h"

using namespace ArduinoFuoco::Controllers;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Utility;

namespace ArduinoFuoco
{

  namespace Utility
  {

    namespace MenuHandlers
    {

      void initMenuData(MenuData &data)
      {
        data.setCurrentNumber(0);
        data.setCurrentBool(false);
      }

      byte homeUp(MenuData &data) { return 4; }
      byte homeDown(MenuData &data) { return 1; }
      byte currentUp(MenuData &data) { return 0; }
      byte currentDown(MenuData &data) { return 2; }
      byte currentEnter(MenuData &data) {
        data.setCurrentNumber(elapsedSecsToday(now()));
        return 16;
      }
      byte currentStatusBuilderLeft(MenuData &data) { return 1; }
      void currentStatusBuilderDisplay(const MenuData &data, Menu &menu) {
        // Loop through the different zones at N-second intervals showing temps and running status

        /**************************************************************************************************************************
        *  There's a potential bug here if viewing status near midnight and the day rolls over; I can live with that.
        *  Alternative would be to store long (time_t) seconds-since-1970 in MenuData and use that. Too much overhead for now.
        *
        *  (Time elapsed since entering this menu) / (N-second interval) = numberOfIntervals;
        *  numberOfIntervals % (Number of zones) = zoneToDisplayForNSeconds
        **************************************************************************************************************************/
        byte zoneNumber = (elapsedSecsToday(now()) - data.getCurrentNumber()) /
            ArduinoFuoco::AppSettings::TIMED_DISPLAY_SCROLL_INTERVAL % *data.getZoneCount();

        Zone* currentZone = data.getZones()[zoneNumber];
        String zoneStatus = "Off";
        if (currentZone->isOn()) { zoneStatus = "On"; }
        menu.setDisplayLine1(String("Status - Zone " + StringHelper::itoa(currentZone->getNumber())));
        menu.setDisplayLine2(String("Temp: " + StringHelper::itoa(currentZone->getCurrentTemperature()) +
            "; " + zoneStatus));
      }


      byte zoneSetupUp(MenuData &data) { return 1; }
      byte zoneSetupDown(MenuData &data) { return 3; }
      byte dateUp(MenuData &data) { return 2; }
      byte dateDown(MenuData &data) { return 4; }
      byte dateEnter(MenuData &data) { return 5; }
      byte advancedUp(MenuData &data) { return 3; }
      byte advancedDown(MenuData &data) { return 0; }
      byte advancedEnter(MenuData &data) { return 17; }

      // Advanced - Hysteresis: Menu = 17; Builder = 18
      byte advHysteresisEnter(MenuData &data) {
        data.setCurrentNumber(ArduinoFuoco::AppSettings::HYSTERESIS);
        return 18;
      }
      byte advHysteresisBuilderUp(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current <= 10) { data.setCurrentNumber(current++); }
        return 18;
      }
      byte advHysteresisBuilderDown(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current >= 0) { data.setCurrentNumber(current--); }
        return 18;
      }
      byte advHysteresisBuilderEnter(MenuData &data) {
//        ArduinoFuoco::AppSettings::HYSTERESIS = data.getCurrentNumber();  //TODO: figure out how to set a global variable (making it non-const is blowing up the builder)
        return 17;
      }
      void advHysteresisBuilderDisplay(const MenuData &data, Menu &menu) {
        menu.setDisplayLine1(String("Set Hysteresis"));
        menu.setDisplayLine2(StringHelper::itoa(data.getCurrentNumber()));
      }


      // Day of Week: Menu = 5; Builder = 15
      byte dtsDayOfWeekUp(MenuData &data) { return 7; }
      byte dtsDayOfWeekDown(MenuData &data) { return 6; }
      byte dtsDayOfWeekEnter(MenuData & data) {
        initMenuData(data);
        data.setCurrentNumber(weekday());
        return 15;
      }
      byte dtsDayOfWeekBuilderUp(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current == 7) { data.setCurrentNumber(1); }
        else { data.setCurrentNumber(current++); }
        return 15;
      }
      byte dtsDayOfWeekBuilderDown(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current == 1) { data.setCurrentNumber(7); }
        else { data.setCurrentNumber(current--); }
        return 15;
      }
      byte dtsDayOfWeekBuilderLeft(MenuData &data) { return 5; }
      void dtsDayOfWeekBuilderDisplay(const MenuData &data, Menu &menu) {
        String weekday = "";
        switch (data.getCurrentNumber()) {
          case 1:
            weekday = "Sun";
            break;
          case 2:
            weekday = "Mon";
            break;
          case 3:
            weekday = "Tues";
            break;
          case 4:
            weekday = "Wed";
            break;
          case 5:
            weekday = "Thurs";
            break;
          case 6:
            weekday = "Fri";
            break;
          case 7:
            weekday = "Sat";
            break;
        }
        menu.setDisplayLine1(String("Set Day of Week"));
        menu.setDisplayLine2(weekday);
      }
      byte dtsDayOfWeekBuilderEnter(MenuData &data) {
        setTime(hour(), minute(), 0, data.getCurrentNumber(), ArduinoFuoco::AppSettings::SET_TIME_START_MONTH, ArduinoFuoco::AppSettings::SET_TIME_START_YEAR);  // setTime(hr,min,sec,day,month,yr);
        return 5;
      }


      // Hour: Menu = 6; Builder = 11
      byte dtsHourUp(MenuData &data) { return 5; }
      byte dtsHourDown(MenuData &data) { return 8; }
      byte dtsHourEnter(MenuData &data) {
        initMenuData(data);
        data.setCurrentNumber(hour());
        return 11;
      }
      byte dtsHourBuilderUp(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current == 12) { data.setCurrentNumber(1); }
        else { data.setCurrentNumber(current++); }
        return 11;
      }
      byte dtsHourBuilderDown(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current == 1) { data.setCurrentNumber(12); }
        else { data.setCurrentNumber(current--); }
        return 11;
      }
      byte dtsHourBuilderLeft(MenuData &data) { return 6; }
      void dtsHourBuilderDisplay(const MenuData &data, Menu &menu) {
        menu.setDisplayLine1(String("Set Hour"));
        menu.setDisplayLine2(StringHelper::itoa(data.getCurrentNumber()));
      }
      byte dtsHourBuilderEnter(MenuData &data) {
        setTime(data.getCurrentNumber(), minute(), 0, weekday(), ArduinoFuoco::AppSettings::SET_TIME_START_MONTH, ArduinoFuoco::AppSettings::SET_TIME_START_YEAR);  // setTime(hr,min,sec,day,month,yr);
        return 6;
      }


      // AM/PM: Menu = 8; Builder = 12
      byte dtsAmPmUp(MenuData &data) { return 6; }
      byte dtsAmPmDown(MenuData &data) { return 7; }
      byte dtsAmPmEnter(MenuData &data) {
        initMenuData(data);
        data.setCurrentBool(data.getCurrentAFTime()->isPm());
        return 12;
      }
      byte dtsAmPmBuilderLeft(MenuData &data) { return 8; }
      byte dtsAmPmBuilderChange(MenuData &data) { data.setCurrentBool(!data.getCurrentBool()); return 12; }
      void dtsAmPmBuilderDisplay(const MenuData &data, Menu &menu) {
        menu.setDisplayLine1(String("Set AM / PM"));
        menu.setDisplayLine2(data.getCurrentBool() ? String("PM") : String("AM"));
      }
      byte dtsAmPmBuilderEnter(MenuData &data) {
        AFTime tmpTime(hour(), 0, data.getCurrentBool());
        setTime(tmpTime.getHour24(), minute(), 0, weekday(), ArduinoFuoco::AppSettings::SET_TIME_START_MONTH, ArduinoFuoco::AppSettings::SET_TIME_START_YEAR);  // setTime(hr,min,sec,day,month,yr);
        return 7;
      }


      // Minute: Menu = 7; Builder = 13
      byte dtsMinuteUp(MenuData &data) { return 8; }
      byte dtsMinuteDown(MenuData &data) { return 5; }
      byte dtsMinuteEnter(MenuData &data) {
        initMenuData(data);
        data.setCurrentNumber(minute());
        return 13;
      }
      byte dtsMinuteBuilderUp(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current == 59) { data.setCurrentNumber(0); }
        else { data.setCurrentNumber(current++); }
        return 13;
      }
      byte dtsMinuteBuilderDown(MenuData &data) {
        byte current = data.getCurrentNumber();
        if (current == 0) { data.setCurrentNumber(59); }
        else { data.setCurrentNumber(current--); }
        return 13;
      }
      byte dtsMinuteBuilderLeft(MenuData &data) { return 7; }
      void dtsMinuteBuilderDisplay(const MenuData &data, Menu &menu) {
        menu.setDisplayLine1(String("Set Minute"));
        menu.setDisplayLine2(StringHelper::itoa(data.getCurrentNumber()));
      }
      byte dtsMinuteBuilderEnter(MenuData &data) {
        setTime(hour(), data.getCurrentNumber(), 0, weekday(), ArduinoFuoco::AppSettings::SET_TIME_START_MONTH, ArduinoFuoco::AppSettings::SET_TIME_START_YEAR);  // setTime(hr,min,sec,day,month,yr);
        return 7;
      }


//  OPTED TO *NOT* DO THIS NOW; CAN'T DYNAMICALLY WIRE A PHYSICAL ACTUATOR TO THE BOARD BASED ON MENU SELECTION; THE ZONES
//  CONSTRUCTED IN THE IDE (menuData.zones**) WILL DETERMINE HOW THE MENU FUNCTIONS FOR NOW
//
//      // Zone Count: Menu = 9; Builder = 14
//      byte zsNumerOfZonesUp(MenuData &data) { return 10; }
//      byte zsNumerOfZonesDown(MenuData &data) { return 10; }
//      byte zsNumerOfZonesEnter(MenuData &data) { initMenuData(data); return 14; }
//      byte zsNumerOfZonesBuilderUp(MenuData &data) {
//        byte current = data.getCurrentNumber();
//        if (current < data.getMaxZoneCount()) { data.setCurrentNumber(current++); }
//        return 14;
//      }
//      byte zsNumerOfZonesBuilderDown(MenuData &data) {
//        byte current = data.getCurrentNumber();
//        if (current > 1) { data.setCurrentNumber(current--); }
//        return 14;
//      }
//      byte zsNumerOfZonesBuilderLeft(MenuData &data) { return 9; }
//      void zsNumerOfZonesBuilderDisplay(const MenuData &data, Menu &menu) {
//        menu.setDisplayLine1(String("# of Zones"));
//        menu.setDisplayLine2(StringHelper::itoa(data.getCurrentNumber()));
//      }
//      byte zsNumerOfZonesBuilderEnter(MenuData &data) { return 9; }  //TODO: figure out how to save this (do i need to delete existing zones if this decreases? add new if increased?)


      // Zone Settings: Menu = 10; Builder01 = 15
      byte zsZoneSettingsUp(MenuData &data) { return 10; }
      byte zsZoneSettingsDown(MenuData &data) { return 10; }
//      byte zsZoneSettingsEnter(MenuData &data) { return ####; }
    }

    MenuInitializer::MenuInitializer()
    {
    }

    MenuInitializer::~MenuInitializer()
    {
    }

    void MenuInitializer::setupMenus(MenuController &menuController)
    {
      AFMenuHandler nullHandler = Menu::NullHandler();

      // new Menu(str1, str2, up, down, left, right, enter, [optional]customDisplay)
      Menu* homeMenu = new Menu(String("Arduino Fuoco -"), String("Radiant Heating"), MenuHandlers::homeUp, MenuHandlers::homeDown, nullHandler, nullHandler, nullHandler);
      Menu* currentStatus = new Menu(String("Current Status"), String(""), MenuHandlers::currentUp, MenuHandlers::currentDown, nullHandler, nullHandler, MenuHandlers::currentEnter);
      Menu* currentStatusBuilder = new Menu(String("Current Status"), String(""), nullHandler, nullHandler, MenuHandlers::currentStatusBuilderLeft, nullHandler, nullHandler, MenuHandlers::currentStatusBuilderDisplay);
      Menu* zoneSetup = new Menu(String("Zone Setup"), String(""), MenuHandlers::zoneSetupUp, MenuHandlers::zoneSetupDown, nullHandler, nullHandler, nullHandler);
      Menu* dateTimeSetup = new Menu(String("Set Date & Time"), String(""), MenuHandlers::dateUp, MenuHandlers::dateDown, nullHandler, nullHandler, MenuHandlers::dateEnter);
      Menu* advanced = new Menu(String("Advanced"), String(""), MenuHandlers::advancedUp, MenuHandlers::advancedDown, nullHandler, nullHandler, MenuHandlers::advancedEnter);

      Menu* dtsDayOfWeek = new Menu(String("Day of the Week"), String(""), MenuHandlers::dtsDayOfWeekUp, MenuHandlers::dtsDayOfWeekDown, nullHandler, nullHandler, MenuHandlers::dtsDayOfWeekEnter);
      Menu* dtsDayOfWeekBuilder = new Menu(String("Day of the Week"), String(""), MenuHandlers::dtsDayOfWeekBuilderUp, MenuHandlers::dtsDayOfWeekBuilderDown, MenuHandlers::dtsDayOfWeekBuilderLeft, nullHandler, MenuHandlers::dtsDayOfWeekBuilderEnter, MenuHandlers::dtsDayOfWeekBuilderDisplay);
      Menu* dtsHour = new Menu(String("Set Hour"), String(""), MenuHandlers::dtsHourUp, MenuHandlers::dtsHourDown, nullHandler, nullHandler, MenuHandlers::dtsHourEnter);
      Menu* dtsHourBuilder = new Menu(String("Set Hour"), String(""), MenuHandlers::dtsHourBuilderUp, MenuHandlers::dtsHourBuilderDown, MenuHandlers::dtsHourBuilderLeft, nullHandler, MenuHandlers::dtsHourBuilderEnter, MenuHandlers::dtsHourBuilderDisplay);
      Menu* dtsMinute = new Menu(String("Set Minute"), String(""), MenuHandlers::dtsMinuteUp, MenuHandlers::dtsMinuteDown, nullHandler, nullHandler, MenuHandlers::dtsMinuteEnter);
      Menu* dtsMinuteBuilder = new Menu(String("Set Minute"), String(""), MenuHandlers::dtsMinuteBuilderUp, MenuHandlers::dtsMinuteBuilderDown, MenuHandlers::dtsMinuteBuilderLeft, nullHandler, MenuHandlers::dtsMinuteBuilderEnter, MenuHandlers::dtsMinuteBuilderDisplay);
      Menu* dtsAmPm = new Menu(String("Set AM / PM"), String(""), MenuHandlers::dtsAmPmUp, MenuHandlers::dtsAmPmDown, nullHandler, nullHandler, MenuHandlers::dtsAmPmEnter);
      Menu* dtsAmPmBuilder = new Menu(String("Set AM / PM"), String(""), MenuHandlers::dtsAmPmBuilderChange, MenuHandlers::dtsAmPmBuilderChange, MenuHandlers::dtsAmPmBuilderLeft, nullHandler, MenuHandlers::dtsAmPmBuilderEnter, MenuHandlers::dtsAmPmBuilderDisplay);

      Menu* zsNumerOfZones = new Menu(String("# of Zones"), String(""), nullHandler, nullHandler, nullHandler, nullHandler, nullHandler);
      Menu* zsNumerOfZonesBuilder = new Menu(String("# of Zones"), String(""), nullHandler, nullHandler, nullHandler, nullHandler, nullHandler);
      Menu* zsZoneSettings = new Menu(String("Zone Settings"), String(""), MenuHandlers::zsZoneSettingsUp, MenuHandlers::zsZoneSettingsDown, nullHandler, nullHandler, nullHandler);

      Menu* advHysteresis = new Menu(String("Hysteresis"), String(""), nullHandler, nullHandler, nullHandler, nullHandler, MenuHandlers::advHysteresisEnter);
      Menu* advHysteresisBuilder = new Menu(String("Hysteresis"), String(""), MenuHandlers::advHysteresisBuilderUp, MenuHandlers::advHysteresisBuilderDown, nullHandler, nullHandler, MenuHandlers::advHysteresisBuilderEnter, MenuHandlers::advHysteresisBuilderDisplay);

      menuController.addMenu(homeMenu);
      menuController.addMenu(currentStatus);
      menuController.addMenu(zoneSetup);
      menuController.addMenu(dateTimeSetup);
      menuController.addMenu(advanced);

      menuController.addMenu(dtsDayOfWeek);
      menuController.addMenu(dtsHour);
      menuController.addMenu(dtsMinute);
      menuController.addMenu(dtsAmPm);

      menuController.addMenu(zsNumerOfZones);
      menuController.addMenu(zsZoneSettings);

      menuController.addMenu(dtsHourBuilder);
      menuController.addMenu(dtsAmPmBuilder);
      menuController.addMenu(dtsMinuteBuilder);
      menuController.addMenu(zsNumerOfZonesBuilder);
      menuController.addMenu(dtsDayOfWeekBuilder);
      menuController.addMenu(currentStatusBuilder);

      menuController.addMenu(advHysteresis);
      menuController.addMenu(advHysteresisBuilder);
    }

  }

}

