/*
Turn.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#include "Turn.hpp"

#include "OpString.hpp"

namespace OpMon {
    namespace Elements {
        void newTurnAction(TurnAction *toNew) {
            toNew->hpLost = 0;
            toNew->dialog = Utils::OpString();
            toNew->type = TurnActionType::NOTHING;
            toNew->statCoef = 0;
        }

        void newTurnData(TurnData *toNew) {
            toNew->opmon = nullptr;
            toNew->moveUsed = nullptr;
            toNew->type = TurnType::MOVE;
            toNew->itemUsed = nullptr;
        }

        TurnAction createTurnDialogAction(Utils::OpString dialog) {
            TurnAction ta;
            newTurnAction(&ta);
            ta.type = TurnActionType::DIALOG;
            ta.dialog = dialog;
            return ta;
        }

    } // namespace Elements
} // namespace OpMon
