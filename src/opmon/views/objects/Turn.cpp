/*
Turn.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#include "Turn.hpp"
#include "../../objects/Attack.hpp"
#include "../../objects/OpMon.hpp"

namespace OpMon {
    namespace Model {
        void newTurnAction(TurnAction *toNew) {
            toNew->hpLost = 0;
            toNew->dialog = Utils::OpString();
            toNew->type = TurnActionType::NOTHING;
            toNew->statCoef = 0;
        }

        void newTurnData(TurnData *toNew) {
            toNew->opmon = nullptr;
            toNew->attackUsed = nullptr;
            toNew->type = TurnType::ATTACK;
            toNew->itemUsed = nullptr;
        }

        TurnAction createTurnDialogAction(Utils::OpString dialog) {
            TurnAction ta;
            newTurnAction(&ta);
            ta.type = TurnActionType::DIALOG;
            ta.dialog = dialog;
            return ta;
        }

    } // namespace Model
} // namespace OpMon
