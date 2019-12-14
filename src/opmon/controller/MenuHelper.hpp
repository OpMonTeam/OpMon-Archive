/*!
 * \file HelperMenu.hpp
 * \author Bobor-dev
 * \copyright GNU GPL v3.0
*/
#ifndef MENUHELPER_HPP
#define MENUHELPER_HPP 1

namespace OpMon {
    namespace Controller {
        namespace Helper {

            /**
             * \brief Moves the cursor to select another menu entry.
             * \param direction `true` moves the cursor down; `false` moves it up.
             * \todo Use Utils::CycleCounter
             */
            void moveArrow(bool direction, int &curPosI, int limitMax = 4);
        } // namespace Helper
    }     // namespace Controller
} // namespace OpMon

#endif // MENUHELPER_HPP
