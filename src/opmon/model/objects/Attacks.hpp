/*
  Attacks.hpp
  Author : Cyrion
  Contributors : BAKFR, Navet56
  File under GNU GPL v3.0 license
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include "Attack.hpp"
#include "OpMon.hpp"
#include <cmath>
#include <iostream>

/** Macro replacing an attack class declaration. I created it by pure laziness. */
#define DEFINE_BATTLE_EFFECT_CLASS(name)                                                     \
    class name : public AttackEffect {                                                       \
      public:                                                                                \
        int apply(Attack &attack, OpMon &attacker, OpMon &defender, Turn &atkTurn) override; \
    }

/** Used in the .cpp in newAtk */
#define IF_ATK(NAME, RESULT) \
    if(name == #NAME) {      \
        return new RESULT;   \
    }

namespace OpMon {
    namespace Model {
        /**
       Namespace containing attacks' definitions
    */
        //->NoDoc
        namespace Attacks {

            /**
	 TODO : Put the attacks' names in english, put all the attacks' names in the rkeys files for translation. 
      */

            Attack *newAtk(std::string name);

            class ChangeStatEffect : public AttackEffect {
              public:
                enum Target { ATTACKER,
                              DEFENDER };
                ChangeStatEffect(Target target, Model::Stats stat, int coef);

                int apply(Attack &attack, OpMon &attacker, OpMon &defender, Turn &atkTurn) override;

              protected:
                Target target;
                Model::Stats stat;
                int coef;
            };
        } // namespace Attacks
    }     // namespace Model
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
