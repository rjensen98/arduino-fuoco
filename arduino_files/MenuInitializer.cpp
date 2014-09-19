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
      byte advancedUp(MenuData &data) { return 3; }
      byte advancedDown(MenuData &data) { return 0; }
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

      Menu* homeMenu = new Menu(String("Arduino Fuoco -"), String("Radiant Heating"), MenuHandlers::homeUp, MenuHandlers::homeDown, nullHandler, nullHandler, nullHandler);
      Menu* currentStatus = new Menu(String("Current Status"), String(""), MenuHandlers::currentUp, MenuHandlers::currentDown, nullHandler, nullHandler, nullHandler);
      Menu* zoneSetup = new Menu(String("Zone Setup"), String(""), MenuHandlers::zoneSetupUp, MenuHandlers::zoneSetupDown, nullHandler, nullHandler, nullHandler);
      Menu* dateTimeSetup = new Menu(String("Set Date & Time"), String(""), MenuHandlers::dateUp, MenuHandlers::dateDown, nullHandler, nullHandler, nullHandler);
      Menu* advanced = new Menu(String("Advanced"), String(""), MenuHandlers::advancedUp, MenuHandlers::advancedDown, nullHandler, nullHandler, nullHandler);

      menuController.addMenu(homeMenu);
      menuController.addMenu(currentStatus);
      menuController.addMenu(zoneSetup);
      menuController.addMenu(dateTimeSetup);
      menuController.addMenu(advanced);
//      Menu zoneSetup = new Menu(String("Zone Setup"), String(""), nullHandler, nullHandler, nullHandler, nullHandler, nullHandler);
    }

  }

}

