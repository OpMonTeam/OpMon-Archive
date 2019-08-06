/*
Turn.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#include "Turn.hpp"
#include "Attack.hpp"
#include "OpMon.hpp"

namespace OpMon {
    namespace Model {
        void newTurnAction(TurnAction *toNew) {
            toNew->hpLost = 0;
            toNew->dialog = std::vector<Utils::OpString>();
            toNew->type = TurnActionType::NOTHING;
            toNew->statCoef = 0;
        }

        void newTurnData(TurnData *toNew) {
            toNew->opmon = nullptr;
            toNew->attackUsed = nullptr;
            toNew->type = TurnType::ATTACK;
            toNew->itemUsed = nullptr;
        }

        TurnAction createTurnDialogAction(std::vector<Utils::OpString> dialog) {
            TurnAction ta;
            newTurnAction(&ta);
            ta.type = TurnActionType::DIALOG;
            ta.dialog = dialog;
            return ta;
        }

    } // namespace Model
} // namespace OpMon
