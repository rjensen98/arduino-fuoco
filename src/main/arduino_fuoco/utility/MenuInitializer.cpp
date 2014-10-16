#include "MenuInitializer.h"
#include "Menu.h"
#include "MenuData.h"
#include "MenuController.h"

using namespace ArduinoFuoco::Controllers;
using namespace ArduinoFuoco::Entity;

namespace ArduinoFuoco
{

  namespace Utility
  {

    namespace MenuHandlers
    {
      byte homeUp(MenuData &data) { return 4; }
      byte homeDown(MenuData &data) { return 1; }
      byte currentUp(MenuData &data) { return 0; }
      byte currentDown(MenuData &data) { return 2; }
      byte zoneSetupUp(MenuData &data) { return 1; }
      byte zoneSetupDown(MenuData &data) { return 3; }
      byte dateUp(MenuData &data) { return 2; }
      byte dateDown(MenuData &data) { return 4; }
      byte dateEnter(MenuData &data) { return 5; }
      byte advancedUp(MenuData &data) { return 3; }
      byte advancedDown(MenuData &data) { return 0; }

      byte dtsDayOfWeekUp(MenuData &data) { return 8; }
      byte dtsDayOfWeekDown(MenuData &data) { return 6; }
//      byte dtsDayOfWeekEnter(MenuData & data) { return ####; }
      byte dtsHourUp(MenuData &data) { return 5; }
      byte dtsHourDown(MenuData &data) { return 7; }
//      byte dtsHourEnter(MenuData &data) { return ####; }
      byte dtsAmPmUp(MenuData &data) { return 6; }
      byte dtsAmPmDown(MenuData &data) { return 8; }
//      byte dtsAmPmEnter(MenuData &data) { return ####; }
      byte dtsMinuteUp(MenuData &data) { return 7; }
      byte dtsMinuteDown(MenuData &data) { return 5; }
//      byte dtsMinuteEnter(MenuData &data) { return ####; }

      byte zsNumerOfZonesUp(MenuData &data) { return 10; }
      byte zsNumerOfZonesDown(MenuData &data) { return 10; }
//      byte zsNumerOfZonesEnter(MenuData &data) { return ####; }
      byte zsZoneSettingsUp(MenuData &data) { return 9; }
      byte zsZoneSettingsDown(MenuData &data) { return 9; }
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

      // new Menu(str1, str2, up, down, left, right, enter)
      Menu* homeMenu = new Menu(String("Arduino Fuoco -"), String("Radiant Heating"), MenuHandlers::homeUp, MenuHandlers::homeDown, nullHandler, nullHandler, nullHandler);
      Menu* currentStatus = new Menu(String("Current Status"), String(""), MenuHandlers::currentUp, MenuHandlers::currentDown, nullHandler, nullHandler, nullHandler);
      Menu* zoneSetup = new Menu(String("Zone Setup"), String(""), MenuHandlers::zoneSetupUp, MenuHandlers::zoneSetupDown, nullHandler, nullHandler, nullHandler);
      Menu* dateTimeSetup = new Menu(String("Set Date & Time"), String(""), MenuHandlers::dateUp, MenuHandlers::dateDown, nullHandler, nullHandler, MenuHandlers::dateEnter);
      Menu* advanced = new Menu(String("Advanced"), String(""), MenuHandlers::advancedUp, MenuHandlers::advancedDown, nullHandler, nullHandler, nullHandler);

      Menu* dtsDayOfWeek = new Menu(String("Day of the Week"), String(""), MenuHandlers::dtsDayOfWeekUp, MenuHandlers::dtsDayOfWeekDown, nullHandler, nullHandler, nullHandler);
      Menu* dtsHour = new Menu(String("Set Hour"), String(""), MenuHandlers::dtsHourUp, MenuHandlers::dtsHourDown, nullHandler, nullHandler, nullHandler);
      Menu* dtsAmPm = new Menu(String("Set AM / PM"), String(""), MenuHandlers::dtsAmPmUp, MenuHandlers::dtsAmPmDown, nullHandler, nullHandler, nullHandler);
      Menu* dtsMinute = new Menu(String("Set Minute"), String(""), MenuHandlers::dtsMinuteUp, MenuHandlers::dtsMinuteDown, nullHandler, nullHandler, nullHandler);

      Menu* zsNumerOfZones = new Menu(String("# of Zones"), String(""), MenuHandlers::zsNumerOfZonesUp, MenuHandlers::zsNumerOfZonesDown, nullHandler, nullHandler, nullHandler);
      Menu* zsZoneSettings = new Menu(String("Zone Settings"), String(""), MenuHandlers::zsZoneSettingsUp, MenuHandlers::zsZoneSettingsDown, nullHandler, nullHandler, nullHandler);

      menuController.addMenu(homeMenu);
      menuController.addMenu(currentStatus);
      menuController.addMenu(zoneSetup);
      menuController.addMenu(dateTimeSetup);
      menuController.addMenu(advanced);

      menuController.addMenu(dtsDayOfWeek);
      menuController.addMenu(dtsHour);
      menuController.addMenu(dtsAmPm);
      menuController.addMenu(dtsMinute);

      menuController.addMenu(zsNumerOfZones);
      menuController.addMenu(zsZoneSettings);
    }

  }

}

