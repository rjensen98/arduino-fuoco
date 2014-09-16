#include "MenuInitializer.h"
#include "Menu.h"
#include "MenuController.h"

using namespace ArduinoFuoco::Controllers;
using namespace ArduinoFuoco::Entity;

namespace ArduinoFuoco
{

  namespace Utility
  {

    namespace MenuHandlers
    {
      byte homeUp() { return 4; }
      byte homeDown() { return 1; }
      byte currentUp() { return 0; }
      byte currentDown() { return 2; }
      byte zoneSetupUp() { return 1; }
      byte zoneSetupDown() { return 3; }
      byte dateUp() { return 2; }
      byte dateDown() { return 4; }
      byte advancedUp() { return 3; }
      byte advancedDown() { return 0; }
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

