/*
Attack.hpp
Author : Jlppc
File under GPL-3.0 license
http://opmon-game.ga
Contains Attack class definition
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include "../../../utils/misc.hpp"
#include "../../view/Battle.hpp"
#include "Enums.hpp"
#include "Turn.hpp"
#include <iostream>

namespace OpMon {
    namespace Model {

        class OpMon;
        /**
       Represents an OpMon attack
	*/

        class AttackEffect {
          public:
            virtual int apply(Attack & /*attack*/, OpMon & /*attacker*/, OpMon & /*defender*/, Turn & /* atkTurn */) { return 0; }
	  virtual ~AttackEffect(){}
        };

        class Attack {
          public:
            virtual ~Attack();
            Attack(std::string name, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::string className, AttackEffect *preEffect = NULL, AttackEffect *postEffect = NULL);

            void healPP() {
                pp = ppMax;
            }

            Type getType() {
                return type;
            }

            int getPP() {
                return pp;
            }

            int getPPMax() {
                return ppMax;
            }

            /**atk attacks the def OpMon*/
            //->Final
            int attack(OpMon &atk, OpMon &def, Turn &atkTurn);
            void ifFails(OpMon &, OpMon &, Turn & /*atkTurn*/) {}

            std::string getClassName() {
                return className;
            }

            std::string save();

            void setPP(int PP) {
                this->pp = PP;
            }

            void setPPMax(int PPMax) {
                this->ppMax = PPMax;
            }

            int getPriority() {
                return this->priority;
            }

            std::string getName() {
                return name;
            }

            // methods used by pre and post Effects
            void setPower(int power) { this->power = power; }
            int getAccuracy() { return this->accuracy; }
            void setAccuracy(int accuracy) { this->accuracy = accuracy; }
            int getPart() { return part; }
            void setPart(int part) { this->part = part; }
            int getHpLost() { return this->hpLost; }
            int getSavedDefSpe() { return this->savedDefSpe; }
            void setSavedDefSpe(int defSpe) { this->savedDefSpe = defSpe; }

          protected:
            std::string className;
            std::string name;
            int power;
            int priority;
            int accuracy;
            Type type;
            bool special;
            bool status;
            int part = 0;
            int pp;
            int ppMax;
            /** The critical hit rate is 1/criticalRate */
            int criticalRate;
            bool neverFails;

            AttackEffect *preEffect;
            AttackEffect *postEffect;
            /**Variables used in preEffect and postEffect*/
            int hpLost = 0;
            int savedDefSpe = 0; // used by ChocPsy
        };

    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
