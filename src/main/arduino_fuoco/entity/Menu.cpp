#include "Menu.h"

namespace ArduinoFuoco
{

  namespace Entity
  {

    Menu::Menu()
    {
    }

    Menu::~Menu()
    {
    }

    Menu::Menu(String line1, String line2, AFMenuHandler handleUp, AFMenuHandler handleDown,
            AFMenuHandler handleLeft, AFMenuHandler handleRight, AFMenuHandler handleEnter)
        : _displayLine1(line1), _displayLine2(line2), _handleUp(handleUp), _handleDown(handleDown),
          _handleLeft(handleLeft), _handleRight(handleRight), _handleEnter(handleEnter)
    {
    }

    AFMenuHandler Menu::NullHandler()
    {
      AFMenuHandler returnMe = 0;
      return returnMe;
    }

    void Menu::setDisplayLine1(String line1)
    {
      _displayLine1 = line1;
    }

    void Menu::setDisplayLine2(String line2)
    {
      _displayLine2 = line2;
    }

  }

}

