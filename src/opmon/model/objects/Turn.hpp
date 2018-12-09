/*
Turn.hpp
Author : Cyrion
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

        struct Turn {
            OpMon *opmon;
            Attack *attackUsed;
            Item *itemUsed;
            TurnType type;
            bool runSuccessful;
            OpMon *newOpmon;
            int hpLost;
            std::vector<Utils::OpString> toPrintBefore;
            std::vector<Utils::OpString> toPrintAfter;
            std::map<Model::Stats, int> changedStatsAtk; //If number > 6 : Stat too high. If number < -6 : Stat too low
            std::map<Model::Stats, int> changedStatsDef; //If number > 6 : Stat too high. If number < -6 : Stat too low
            bool confusedHurt;
            bool attackMissed;
            bool attackFailed;
            bool atkEnd;
            bool OHKO;
            int attackHurt;
        };

        typedef struct Turn Turn;

        void newTurn(Turn *toNew);
    } // namespace Model
} // namespace OpMon
