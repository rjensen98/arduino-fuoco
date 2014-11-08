#include "Menu.h"
#include "MenuController.h"
#include "MenuData.h"
#include "LCDButtonType.h"

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{

  namespace Entity
  {

    Menu::~Menu()
    {
    }

    Menu::Menu(String line1, String line2, AFMenuHandler handleUp, AFMenuHandler handleDown,
            AFMenuHandler handleLeft, AFMenuHandler handleRight, AFMenuHandler handleEnter)
        : _displayLine1(line1), _displayLine2(line2), _handleUp(handleUp), _handleDown(handleDown),
          _handleLeft(handleLeft), _handleRight(handleRight), _handleEnter(handleEnter)
    {
    }

    Menu::Menu(String line1, String line2, AFMenuHandler handleUp, AFMenuHandler handleDown,
            AFMenuHandler handleLeft, AFMenuHandler handleRight, AFMenuHandler handleEnter,
            AFCustomDisplayHandler customDisplay)
        : _displayLine1(line1), _displayLine2(line2), _handleUp(handleUp), _handleDown(handleDown),
          _handleLeft(handleLeft), _handleRight(handleRight), _handleEnter(handleEnter), _handleCustomDisplay(customDisplay)
    {
    }

    AFMenuHandler Menu::NullHandler()
    {
      AFMenuHandler returnMe = 0;
      return returnMe;
    }

    void Menu::renderDisplay(const MenuData &data)
    {
      #if (AF_DEBUG == 1)
        Serial.println("ArduinoFuoco::Entity::Menu::renderCustomDisplay - Rendering custom display for this menu");
      #endif
      if (_handleCustomDisplay)
      {
        _handleCustomDisplay(data, *this);
      }
    }

    String Menu::getDisplayLine1()
    {
      return _displayLine1;
    }

    String Menu::getDisplayLine2()
    {
      return _displayLine2;
    }

    void Menu::setDisplayLine1(String line1)
    {
      _displayLine1 = line1;
    }

    void Menu::setDisplayLine2(String line2)
    {
      _displayLine2 = line2;
    }

    int Menu::handleButtonPress(const LCDButtonType::Enum &button, MenuData &data)
    {
      switch (button)
      {
        case LCDButtonType::RIGHT:
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - Button RIGHT");
          #endif
          if (_handleRight)
          {
            return _handleRight(data);
          }
          else
          {
            #if (AF_DEBUG == 1)
              Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - No handler defined for this button.");
            #endif
            return -1;
          }
        }
        case LCDButtonType::LEFT:
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - Button LEFT");
          #endif
          if (_handleLeft)
          {
            return _handleLeft(data);
          }
          else
          {
            #if (AF_DEBUG == 1)
              Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - No handler defined for this button.");
            #endif
            return -1;
          }
        }
        case LCDButtonType::UP:
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - Button UP");
          #endif
          if (_handleUp)
          {
            return _handleUp(data);
          }
          else
          {
            #if (AF_DEBUG == 1)
              Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - No handler defined for this button.");
            #endif
            return -1;
          }
        }
        case LCDButtonType::DOWN:
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - Button DOWN");
          #endif
          if (_handleDown)
          {
            return _handleDown(data);
          }
          else
          {
            #if (AF_DEBUG == 1)
              Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - No handler defined for this button.");
            #endif
            return -1;
          }
        }
        case LCDButtonType::SELECT:
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - Button SELECT");
          #endif
          if (_handleEnter)
          {
            return _handleEnter(data);
          }
          else
          {
            #if (AF_DEBUG == 1)
              Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - No handler defined for this button.");
            #endif
            return -1;
          }
        }
        default:
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Menu::handleButtonPress - An unknown or no button was pressed.");
          #endif
          return -1;
        }
      }/* --(end switch )-- */
    }

  }

}

