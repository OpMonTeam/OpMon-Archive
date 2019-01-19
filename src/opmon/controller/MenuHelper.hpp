/*
HelperMenu.hpp
Author : Cyrion / Bobor-dev
File under GNU GPL v3.0 license
*/
#ifndef MENUHELPER_HPP
#define MENUHELPER_HPP 1

namespace OpMon {
    namespace Controller {
      namespace Helper{

        /**
         * Moves the cursor to select another menu entry.
         * @param `true` moves the cursor up; `false` moves it down.
         */
        void moveArrow(bool direction, int& curPosI, int limitMax = 4);
      } // namespace Controller
    } // namespace View
} // namespace OpMon

#endif // MENUHELPER_HPP
