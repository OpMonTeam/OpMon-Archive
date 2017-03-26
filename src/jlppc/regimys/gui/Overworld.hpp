#ifndef OVERWORLD_HPP
#define OVERWORLD_HPP
#include "MainFrame.hpp"

namespace MainFrame{
namespace Overworld{
    void initVars();
    void verifVars();
    void overworld();
    void deleteVars();
    int boucle();
    void up();
    void down();
    void left();
    void right();
    extern Plan *actuel;
    extern SDL_Texture *spritePP[4];
    extern SDL_Texture *marchePP[4];
    extern SDL_Rect ppPos;
    extern SDL_Rect mapPos;
}
}

#endif // OVERWORLD_HPP
