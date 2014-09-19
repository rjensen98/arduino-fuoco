#include "MenuController.h"
#include "Arduino.h"
#include "HeatController.h"
#include "LCDButtonType.h"
#include "LiquidCrystal.h"
#include "Menu.h"
#include "MenuInitializer.h"

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;
using namespace ArduinoFuoco::Utility;

namespace ArduinoFuoco
{

  namespace Controllers
  {

    MenuController::MenuController(const byte maxMenuCount, HeatController* zoneInformation)
        : _currentMenuId(0), _maxMenuCount(maxMenuCount), _menuCount(0), _lcd(8, 9, 4, 5, 6, 7),
            _menuData(zoneInformation->getZones(), zoneInformation->getZoneCountRef())
    {
      _menus = new Menu*[maxMenuCount];
      setup();
    }

    MenuController::~MenuController()
    {
      // Deallocate the space taken by each menu
      for (int i = 0; i < _menuCount; i++)
      {
        delete _menus[i];
      }

      // Deallocate the space taken by the menu array
      delete[] _menus;
    }

    void MenuController::setup()
    {
      _lcd.begin(16, 2);
    }

    void MenuController::addMenu(Menu* menu)
    {
      addMenu(*menu);
    }

    void MenuController::addMenu(Menu &menu)
    {
      if ((_menuCount + 1) <= _maxMenuCount)
      {
        _menus[_menuCount] = &menu;
        _menuCount++;
      }
      else
      {
        #if (AF_DEBUG == 1)
          Serial.println("ArduinoFuoco::Controllers::MenuController::addMenu - There is no room for more menus in this controller.");
        #endif
      }
    }

    void MenuController::initializeMenus()
    {
      #if (AF_DEBUG == 1)
        Serial.println("ArduinoFuoco::Controllers::MenuController::initializeMenus - Setting up menus.");
      #endif
      MenuInitializer::setupMenus(*this);
    }

    void MenuController::handleButton()
    {
      _previousButton = _buttonPressed;
      _buttonPressed = readLCDButtons();
      if (_buttonPressed == LCDButtonType::NONE || _previousButton == _buttonPressed)
      {
        return;
      }

      Menu* menu = _menus[_currentMenuId];
      int newMenuId = menu->handleButtonPress(_buttonPressed, _menuData);
      if (newMenuId > -1)
      {
        _currentMenuId = newMenuId;
      }
      #if (AF_DEBUG == 1)
        else
        {
          Serial.println("ArduinoFuoco::Controllers::MenuController::handleButton - Problem handling button press. Not changing current menu.");
        }
      #endif
    }

    /********************************************
     * Based on debouncing code by peterstrobl
     *******************************************/
    LCDButtonType::Enum MenuController::readLCDButtons()
    {
      int adc_key_in = analogRead(0);      // read the value from the sensor
      delay(5); //switch debounce delay. Increase this delay if incorrect switch selections are returned.
      int k = (analogRead(0) - adc_key_in); //gives the button a slight range to allow for a little contact resistance noise
      if (5 < abs(k)) return LCDButtonType::NONE;  // double checks the keypress. If the two readings are not equal +/-k value after debounce delay, it tries again.

      #if (AF_DEBUG == 1)
        Serial.print("ArduinoFuoco::Controllers::MenuController::readLCDButtons - Current button reading = ");
        Serial.println(adc_key_in, DEC);
      #endif

      // my buttons when read are centered at these values: 0, 144, 329, 504, 741
      // we add approx 50 to those values and check to see if we are close
      if (adc_key_in > 1000) return LCDButtonType::NONE; // We make this the 1st option for speed reasons since it will be the most likely result
      if (adc_key_in < 50)   return LCDButtonType::RIGHT;
      if (adc_key_in < 195)  return LCDButtonType::UP;
      if (adc_key_in < 380)  return LCDButtonType::DOWN;
      if (adc_key_in < 555)  return LCDButtonType::LEFT;
      if (adc_key_in < 790)  return LCDButtonType::SELECT;
      return LCDButtonType::NONE;  // when all others fail, return this...
    }

    void MenuController::renderMenu()
    {
      _lcd.setCursor(0, 0);
      _lcd.print(_menus[_currentMenuId]->getDisplayLine1());
      _lcd.setCursor(0, 1);
      _lcd.print(_menus[_currentMenuId]->getDisplayLine2());
    }

  }

}

