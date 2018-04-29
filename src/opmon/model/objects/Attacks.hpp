/*
  Attacks.hpp
  Author : Jlppc
  File under GPL-3.0 license
  http://opmon-game.ga
  Contains the attacks classes definitions
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include "Attack.hpp"
#include "OpMon.hpp"
#include <cmath>
#include <iostream>

/** Macro replacing an attack class declaration. I created it by pure laziness. */
#define DEFINE_BATTLE_EFFECT_CLASS(name)																										\
  class name : public AttackEffect {																												\
	  public:																																									\
      int apply(Attack &attack, OpMon &attacker, OpMon &defender, Turn& atkTurn) override;	\
  }

#define IF_ATK(NAME, RESULT)	\
  if(name == #NAME) {          \
    return new RESULT;        \
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
				enum Target { ATTACKER, DEFENDER };
				ChangeStatEffect(Target target, Model::Stats stat, int coef);

				int apply(Attack &attack, OpMon &attacker, OpMon &defender, Turn& atkTurn) override;

			protected:
				Target target;
				Model::Stats stat;
				int coef;
			};


			DEFINE_BATTLE_EFFECT_CLASS(AbimeBeforeEffect);
			DEFINE_BATTLE_EFFECT_CLASS(AcideAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(AiguisageAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(BelierAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(BalayageBeforeEffect);
			DEFINE_BATTLE_EFFECT_CLASS(BerceuseAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(BlizzardAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(BueeNoireAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(BullesDoAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(CageEclairAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(CascadeAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(ChocMentalAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(ChocPsyBeforeEffect);
			DEFINE_BATTLE_EFFECT_CLASS(ChocPsyAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(ComboGriffeAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(ConversionAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(CoupdBouleAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(CoudKraneBeforeEffect);
			DEFINE_BATTLE_EFFECT_CLASS(CoupeVentBeforeEffect);
			DEFINE_BATTLE_EFFECT_CLASS(CrocDeMortAfterEffect);

			/*
			DEFINE_BATTLE_EFFECT_CLASS(CrocFatalBeforeEffect);
			DEFINE_BATTLE_EFFECT_CLASS(CrocFeuAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DamoclesAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DanseFleurAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DanseLamesAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DeflagrationAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DestructionAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DetritusAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DevoreveBeforeEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DevoreveAfterEffect);
			DEFINE_BATTLE_EFFECT_CLASS(DoubleDardAfterEffect);
			*/
    }
  }
}

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
