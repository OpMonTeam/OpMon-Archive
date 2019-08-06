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

        enum class TurnActionType {
            NOTHING,
            ATK_UPDATE_HBAR,
            ATK_USE_ITEM,
            ATK_STAT_MOD,
            ATK_OPMON_CBACK,
            ATK_OPMON_OUT,
            DIALOG,
            DEF_UPDATE_HBAR,
            DEF_USE_ITEM,
            DEF_STAT_MOD,
            DEF_OPMON_CBACK,
            DEF_OPMON_OUT,
            VICTORY,
            DEFEAT,
            RUN
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
