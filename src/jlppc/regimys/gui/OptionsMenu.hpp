#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include <iostream>
#include "MainFrame.hpp"
#include "MainMenu.hpp"
#include <SDL/SDL_all.h>

namespace MainFrame{
namespace MainMenu{
namespace OptionsMenu{



    int optionsMenu();
    void initVars();
    void verifVars();
    void deleteVars();
    int boucle();

}
}
}

#endif // OPTIONSMENU_HPP
