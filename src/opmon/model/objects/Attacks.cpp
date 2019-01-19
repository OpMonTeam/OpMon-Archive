/*
Attacks.cpp
Author : Cyrion
Contributors : BAKFR, Navet56, JonnyPtn
File under GNU GPL v3.0 license
*/
#include "Attacks.hpp"
#include "../../../utils/misc.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"
namespace OpMon {
    namespace Model {

        namespace Attacks {

            using namespace Utils;

            Attack *newAtk(std::string name) {
                IF_ATK(Mist, Attack("Mist", 0, Type::NEUTRAL, 100, false, true, -1, false, 20, 0, "Mist",
                                    nullptr, new ChangeStatEffect(ChangeStatEffect::DEFENDER, Stats::ACC, -1)))
                IF_ATK(Growl, Attack("Growl", 0, Type::NEUTRAL, 100, false, true, -1, false, 20, 0, "Growl", nullptr, new ChangeStatEffect(ChangeStatEffect::DEFENDER, Stats::ATK, -1)))
                IF_ATK(Tackle, Attack("Tackle", 50, Type::NEUTRAL, 100, false, false, 16, false, 35, 0, "Tackle"))
                return nullptr;
            }

            ChangeStatEffect::ChangeStatEffect(Target target, Model::Stats stat, int coef)
              : target(target)
              , stat(stat)
              , coef(coef) {}

            int ChangeStatEffect::apply(Attack &, OpMon &attacker, OpMon &defender, Turn &atkTurn) {
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

                if(target == Target::ATTACKER) {
                    int diff_value = (attacker.*change_method)(coef); // diff_value = attacker.changeXXX(coef)
                    atkTurn.changedStatsAtk.emplace(stat, diff_value);
                } else {
                    int diff_value = (defender.*change_method)(coef); // diff_value = defender.changeXXX(coef)
                    atkTurn.changedStatsDef.emplace(stat, diff_value);
                }
                return 0;
            }

        } // namespace Attacks

    } // namespace Model
} // namespace OpMon
#pragma GCC diagnostic pop
