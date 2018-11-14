/*
MainMenu.hpp
Author : Cyrion
Contributors : Navet56, BAKFR
File under GNU GPL v3.0 license
*/
#ifndef MENUHELPER_HPP
#define MENUHELPER_HPP

namespace OpMon {
    namespace Helper {

        static void moveArrow(bool direction, int& curPosI, int limitMax = 4) {
            if(direction) { //If direction is true, the cursor goes down.
                --curPosI;
                if(curPosI < 0) {
                    curPosI = limitMax - 1;
                }
            } else { //Obviously, if direction is false, the cursor goes up.
                ++curPosI;
                if(curPosI >= limitMax) {
                    curPosI = 0;
                }
            }
        }
    } // namespace View
} // namespace OpMon

#endif // MAINMENU_HPP
