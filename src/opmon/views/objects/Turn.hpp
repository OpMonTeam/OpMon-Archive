/*!
 * \file Turn.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 * \todo Put this in one namespace.
 * \todo Move this in view ?
*/
#pragma once

#include <map>

#include "../../objects/Item.hpp"

namespace OpMon {

    class OpMon;
    class Attack;
class Item;

    namespace Elements {

        /*!
         * \brief Enumerates the different types of turns.
         */
        enum class TurnType {
            ATTACK,/*!< The OpMon attacks the opponent.*/
            ITEM, /*!< The OpMon uses an item.*/
            RUN, /*!< The OpMon tries to run.*/
            CHANGE /*!< The opponent changes OpMon.*/
        };

        /*!
         * \enum TurnActionType
         * \brief Enumerates the different actions done in a turn.
         */
        enum class TurnActionType : unsigned int {
            NOTHING = 0,/*!< Nothing is done.*/
            ATK_UPDATE_HBAR = 1,/*!< Updates the health bar of player's OpMon.*/
            ATK_USE_ITEM = 2,/*!< The player's OpMon uses an item.*/
            ATK_STAT_MOD = 3,/*!< The player's OpMon has a modification of stats.*/
            ATK_OPMON_CBACK = 4, /*!< The player's OpMon quits the battle.*/
            ATK_OPMON_OUT = 5, /*!< The player's OpMon is sent to the battle.*/
            DIALOG = 6,/*!< There is a dialog.*/
            DEF_UPDATE_HBAR = 7,/*!< Updates the health bar of the opponent's OpMon.*/
            DEF_USE_ITEM = 8,/*!< The opponent's OpMon uses an item.*/
            DEF_STAT_MOD = 9,/*!< The opponent's OpMon has a modification of stats.*/
            DEF_OPMON_CBACK = 10,/*!< The opponent's OpMon quits the battle.*/
            DEF_OPMON_OUT = 11,/*!< The opponent's OpMon is sent to the battle.*/
            VICTORY = 12,/*!< The player wins the battle.*/
            DEFEAT = 13,/*!< The player looses the battle.*/
            RUN = 14,/*!< The player runs from the battle.*/
            ATK_MOVE = 15,/*!< The player's OpMon uses a move.*/
            DEF_MOVE = 16,/*!< The opponent's OpMon uses a move.*/
            ANIMATION = 17,/*!< A general animation has to be played.*/
            OPANIM = 18, /*!< An OpMon animation has to be played.*/
            NEXT = 19    /*!< This is now the turn of the next OpMon.*/
        };

        /*!
         * \brief Contains data needed to show an action in a turn in a View::Battle.
         * \details TurnAction is like a command sent to View::Battle : according to what's inside, View::Battle will act differently. TurnAction::type is like the command itself, and the other variables the arguments. You do not have to use every variable, some are useless according to the type of action you choose.
         */
        struct TurnAction {
            int hpLost;/*!< \brief The HP lost by the OpMon.*/
            Utils::OpString dialog;/*!< \brief The dialog to be printed.*/
            TurnActionType type; /*!< \brief The type of the turn action.*/
            int statCoef; /*!< \brief The coefficient of modification of the modified stat.*/
            Stats statMod; /*!< \brief The modified stat.*/
        };

        /*!
         * \brief Contains data needed to show a turn in View::Battle.
         */
        struct TurnData {
            Attack *attackUsed;
            OpMon *opmon;
            TurnType type;
            Item *itemUsed;
        };

        typedef struct TurnAction TurnAction;
        typedef struct TurnData TurnData;

        /*!
         * \brief Initialises a TurnAction with default values.
         * \warning If the parameter is not a new TurnData, it will be reset.
         * \param toNew A pointer to the TurnAction to fill with default values.
         */
        void newTurnAction(TurnAction *toNew);
        /*!
         * \brief Initialises a TurnData with default vaules.
         * \warning If the parameter is not a new TurnData, it will be reset.
         * \param toNew A pointer to the TurnAction to fill with default values.
         */
        void newTurnData(TurnData *toNew);
        /*!
         * \brief Shortcut to create TurnActions to show dialogs.
         * \param dialog The dialog to show.
         * \returns The TurnAction printing the dialog in Battle::View.
         */
        TurnAction createTurnDialogAction(Utils::OpString dialog);
    } // namespace Elements
} // namespace OpMon
