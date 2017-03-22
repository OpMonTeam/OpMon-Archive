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
    extern Plan *actuel;
}
}

#endif // OVERWORLD_HPP
