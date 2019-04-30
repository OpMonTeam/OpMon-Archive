/*
Attack.hpp
Author : Cyriel
Contributors : BAKFR, Navet56
File under GNU GPL v3.0 license
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include "../../../utils/OpString.hpp"
#include "../../../utils/defines.hpp"
#include "../../../utils/misc.hpp"
#include "../../view/Elements.hpp"
#include "Enums.hpp"
#include "Turn.hpp"
#include <iostream>
#include <queue>

namespace OpMon {
    namespace Model {

        class OpMon;

        class AttackEffect {
          public:
            virtual int apply(Attack & /*attack*/, OpMon & /*attacker*/, OpMon & /*defender*/, std::queue<TurnAction> & /* turnQueue */) { return 0; }
            virtual ~AttackEffect() {}
        };

        struct AttackData {
            std::string nameKey;
            int power;
            Type type;
            int accuracy;
            bool special;
            bool status;
            int criticalRate;
            bool neverFails;
            int ppMax;
            int priority;
            AttackEffect *preEffect = nullptr;
            AttackEffect *postEffect = nullptr;
            AttackEffect *ifFails = nullptr;
	    std::queue<TurnActionType> animationOrder;
	    std::queue<View::Movement*> opMovements;
	    std::queue<std::string> animations;
	    
        };

        typedef struct AttackData AttackData;

        class Attack {
          public:
            virtual ~Attack();
            Attack(std::string nameKey, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::queue<TurnActionType> animationOrder, std::queue<View::Movement*> opMovements, std::queue<std::string> animations, AttackEffect *preEffect = nullptr, AttackEffect *postEffect = nullptr, AttackEffect *fails = nullptr);

            Attack(AttackData const &data);

            static Attack *newAtk(std::string name);
            static void initAttacks(std::string file);

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

            //"atk" attacks the "def" OpMon
            int attack(OpMon &atk, OpMon &def, std::queue<TurnAction> &turnQueue, bool attacker);

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

            sf::String getName() {
                return name.getString();
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
            Utils::OpString name;
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
            AttackEffect *failEffect;
            /**Variables used in preEffect and postEffect*/
            int hpLost = 0;
            int savedDefSpe = 0; // used by ChocPsy

	    std::queue<TurnActionType> animationOrder;
	    std::queue<View::Movement*> opMovements;
	    std::queue<std::string> animations;
	    
            static std::map<std::string, AttackData> attackList;
        };

    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
