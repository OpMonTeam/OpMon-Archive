/*
  Attacks.cpp
  Author : Cyrielle
  Contributors : BAKFR, Navet56, JonnyPtn
  File under GNU GPL v3.0 license
*/
#include "Attacks.hpp"
#include "../../utils/misc.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"
namespace OpMon {

    namespace Attacks {

        using namespace Utils;

        ChangeStatEffect::ChangeStatEffect(Target target, Stats stat, int coef)
            : target(target)
            , stat(stat)
            , coef(coef) {}

        ChangeStatEffect::ChangeStatEffect(nlohmann::json const &data)
            : target(data.at("target"))
            , stat(data.at("stat"))
            , coef(data.at("coef")) {
        }

        int ChangeStatEffect::apply(Attack &, OpMon &attacker, OpMon &defender, std::queue<Elements::TurnAction> &turnQueue) {
            std::map<Stats, int (OpMon::*)(int)> stat_to_method = {
                {Stats::ACC, &OpMon::changeACC},
                {Stats::ATK, &OpMon::changeATK},
                {Stats::ATKSPE, &OpMon::changeATKSPE},
                {Stats::DEF, &OpMon::changeDEF},
                {Stats::DEFSPE, &OpMon::changeDEFSPE},
                {Stats::EVA, &OpMon::changeEVA},
                {Stats::SPE, &OpMon::changeSPE},
            };
            auto change_method = stat_to_method[stat];

            // TODO : Add dialog if stat is at its min/max

            Elements::TurnAction statMod;
            newTurnAction(&statMod);

            if(target == Target::ATTACKER) {
                (attacker.*change_method)(coef); // diff_value = attacker.changeXXX(coef)
                statMod.type = Elements::TurnActionType::ATK_STAT_MOD;
            } else {
                (defender.*change_method)(coef); // diff_value = defender.changeXXX(coef)
                statMod.type = Elements::TurnActionType::DEF_STAT_MOD;
            }
            statMod.statCoef = coef;
            statMod.statMod = stat;
            turnQueue.push(statMod);

            return 0;
        }

    } // namespace Attacks

} // namespace OpMon
#pragma GCC diagnostic pop
