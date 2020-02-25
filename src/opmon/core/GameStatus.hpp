/*!
 * \file GameStatus.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \copyright GNU GPL v3.0
 * \date 08/01/18
*/
#pragma once

namespace OpMon {
    /*!
     * \brief Enumeration defining the different commands returned to define the game status.
     */
    enum class GameStatus {
        CONTINUE, /*!< The program has to continue.*/
        STOP, /*!< The program has to stop.*/
        REBOOT, /*!< Same as STOP, but the program has to reboot.*/
        NEXT, /*!< The program has to get to the next state.*/
        PREVIOUS, /*!< The program has to get to the previous state.*/
        NEXT_NLS, /*!< The program has to get to the next state without loading screen.*/
        PREVIOUS_NLS, /*!< The program has to get to the previous state without loading screen.*/
        WIN_REBOOT /*!< The program has to reboot the window.*/
    };
}
