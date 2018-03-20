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
#include "Enums.hpp"
#include <iostream>

namespace OpMon {
    namespace Model {

        class OpMon;
        /**
       Represent an OpMon attack
    */
        //->PureVirtual
        class Attack {
          public:
            virtual ~Attack() {}
            Attack(std::string name, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::string className);
            virtual int effectBefore(OpMon & /*atk*/, OpMon & /*def*/) { return 0; }
            virtual int effectAfter(OpMon & /*atk*/, OpMon & /*def*/) { return 0; }
            void healPP() {
                pp = ppMax;
            }
            Type getType() {
                return type;
            }
            /**atk attacks the def OpMon*/
            //->Final
            int attack(OpMon &atk, OpMon &def);
            virtual void ifFails(OpMon &, OpMon &) {}
            virtual std::string getClassName() {
                return className;
            }
            virtual std::string save();
            void setPP(int PP) {
                this->pp = PP;
            }
            void setPPMax(int PPMax) {
                this->ppMax = PPMax;
            }

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
            /**The critical hit rate is 1/criticalRate*/
            int criticalRate;
            bool neverFails;
            /**Variables used in effectBefore and effetAfter*/
            int hpLost = 0;
        };

    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
