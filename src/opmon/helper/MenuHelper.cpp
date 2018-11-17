/*
MenuHelper.cpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#include "MenuHelper.hpp"

namespace OpMon {
    namespace Helper {
        void moveArrow(bool direction, int& curPosI, int limitMax) {
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
    } // namespace Controller
} // namespace OpMon
