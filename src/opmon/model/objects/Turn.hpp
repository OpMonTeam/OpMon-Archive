/*
Turn.hpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#pragma once

#include "../../../utils/OpString.hpp"
#include "Item.hpp"
#include <map>

namespace OpMon {
    namespace Model {

        class OpMon;
        class Attack;

        enum class TurnType {
            ATTACK,
            ITEM,
            RUN,
            CHANGE
        };

        enum class TurnActionType : unsigned int{
            NOTHING = 0,
            ATK_UPDATE_HBAR = 1,
            ATK_USE_ITEM = 2,
            ATK_STAT_MOD = 3,
            ATK_OPMON_CBACK = 4,
            ATK_OPMON_OUT = 5,
            DIALOG = 6,
            DEF_UPDATE_HBAR = 7,
            DEF_USE_ITEM = 8,
            DEF_STAT_MOD = 9,
            DEF_OPMON_CBACK = 10,
            DEF_OPMON_OUT = 11,
            VICTORY = 12,
            DEFEAT = 13,
            RUN = 14,
	    ATK_MOVE = 15,
	    DEF_MOVE = 16,
	    ANIMATION = 17,
	    OPANIM = 18, //Animates the current attack
	    NEXT = 19 //Indicate that this is now the next OpMon turn
        };

        struct TurnAction {
            int hpLost;
            std::vector<Utils::OpString> dialog;
            TurnActionType type;
            int statCoef;
            Stats statMod;
        };

        struct TurnData {
            Attack *attackUsed;
            OpMon *opmon;
            TurnType type;
            Item *itemUsed;
        };

        typedef struct TurnAction TurnAction;
        typedef struct TurnData TurnData;

        void newTurnAction(TurnAction *toNew);
        void newTurnData(TurnData *toNew);
        TurnAction createTurnDialogAction(std::vector<Utils::OpString> dialog);
    } // namespace Model
} // namespace OpMon
