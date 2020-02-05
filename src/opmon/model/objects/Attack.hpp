/*!
 * \file Attack.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors Navet56
 * \copyright GNU GPL v3.0
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

        /*!
         * \class AttackEffect Attack.hpp "opmon/model/objects/Attack.hpp"
         * This class is virtual and one has to be created for each attack effect.
         */
        class AttackEffect {
          public:
            /*!
              \brief Applies the effect.
             */
            virtual int apply(Attack & /*attack*/, OpMon & /*attacker*/, OpMon & /*defender*/, std::queue<TurnAction> & /* turnQueue */) { return 0; }
            virtual ~AttackEffect() {}
        };

        /*!
         * \struct AttackData
         * \brief Contains all the necessary data to create an Attack.
         * \details This structure is used in the class Attack to link all the variables needed to the constructor in one variable. It represents the attack in an abstract way, while Attack represents an attack owned by an OpMon.
         */
        struct AttackData {
            std::string nameKey; /*!< \brief The key (see Utils::StringKeys) used to get the attack name in the right language.*/
            int power; /*!< \brief  The power of the attack.*/
            Type type; /*!< \brief  The type of the attack.*/
            int accuracy;/*!< \brief  The accuracy of the attack*/
            bool special; /*!< \brief  If `true`, the attack is a special attack (uses the special stats). Else, the attack is a physical attack (uses the basic stats).*/
            bool status; /*!< \brief  If `true`, the attack does not harm directly the opposite OpMon.*/
            int criticalRate; /*!< \brief  The critical rate of the attack. It represents the denominator (one chance out of the value of the variable)*/
            bool neverFails; /*!< \brief  If `true`, the attack can't fail.*/
            int ppMax; /*!< \brief The maximum base PP (Power points) of the attack.*/
            int priority; /*!< \brief The level of priority of the attack.*/
            AttackEffect *preEffect = nullptr; /*!< \brief The attack effect applied before the calculation of the damages.*/
            AttackEffect *postEffect = nullptr; /*!< \brief The attack effect applied after the calculation of the damages.*/
            AttackEffect *ifFails = nullptr; /*!< \brief The attack effect applied if the attack fails.*/
            std::vector<TurnActionType> animationOrder; /*!< \brief The order in which the animations will occur.*/
            std::queue<View::Transformation> opAnimsAtk; /*!< \brief The animations linked to the attacking OpMon's sprite.*/
            std::queue<View::Transformation> opAnimsDef; /*!< \brief The animations linked to the attacked OpMon's sprite.*/
            std::queue<std::string> animations; /*!< \brief The animations played on the whole screen.*/
        };

        typedef struct AttackData AttackData;

        /*!
         * \class Attack
         * \brief Describes an attack.
         * \details This class describes an attack owned by an OpMon, and not just an attack in general (AttackData is used for this, the attacks are stored in Attack::attackList).
         * \todo Change the name to "move" to stick better with the original game.
         */
        class Attack {
          public:
            virtual ~Attack();
            /*!
             * \brief Creates an attack with all the needed data.
             * \note To see the details of the parameters, see AttackData.
             */
            Attack(std::string nameKey, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::vector<TurnActionType> animationOrder, std::queue<View::Transformation> opAnimsAtk, std::queue<View::Transformation> opAnimsDef, std::queue<std::string> animations, AttackEffect *preEffect = nullptr, AttackEffect *postEffect = nullptr, AttackEffect *fails = nullptr);

            /*!
             * \brief Creates and attack with all the data stored in the AttackData structure.
             */
            Attack(AttackData const &data);

            /*!
             * \brief Returns a pointer to a new Attack object created by using the parameter to access an AttackData object stored in Attack::attackList.
             * \param name Key used to identify the wanted attack in Attack::attackList.
             */
            static Attack *newAtk(std::string name);
            /*!
             * \brief Initialises the attacks and stores them in Attack::attackList.
             * \param file The file containing the data to load (Json format).
             */
            static void initAttacks(std::string file);

            /*!
             * \brief Resets the current PP number to the maximum.
             */
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

            /*!
             * \brief Causes a OpMon to attack another one.
             * \param atk A reference to the OpMon using the attack.
             * \param def A reference to the opposite OpMon.
             * \param turnQueue A reference to the action queue of the turn.
             * \param attacker If `true`, the OpMon attacking is the player's one (The one on the front of the screen.). Used to determine which health bar update.
             */
            int attack(OpMon &atk, OpMon &def, std::queue<TurnAction> &turnQueue, bool attacker);

            /*!
             * \warning Work in progress.
             * \brief Will be used to save the AttacK.
             */
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
                return name;
            }

            std::queue<View::Transformation> getOpAnimsAtk() const {
                return opAnimsAtk;
            }

            std::queue<View::Transformation> getOpAnimsDef() const {
                return opAnimsDef;
            }

            std::queue<std::string> getAnimations() const {
                return animations;
            }

            // methods used by pre and post Effects


            void setPower(int power) { this->power = power; }
            int getAccuracy() { return this->accuracy; }
            void setAccuracy(int accuracy) { this->accuracy = accuracy; }
            int getPart() { return part; }
            void setPart(int part) { this->part = part; }
            int getHpLost() { return this->hpLost; }

          protected:
            Utils::OpString nameKey;/*!<\brief The key (see Utils::StringKeys) used to get the attack name in the right language.*/
            sf::String name; /*!<\brief The attack name in the current language.*/
            int power; /*!< \brief The power of the attack.*/
            Type type; /*!< \brief The type of the attack.*/
            int accuracy;/*!< \brief The accuracy of the attack*/
            bool special; /*!< \brief If `true`, the attack is a special attack (uses the special stats). Else, the attack is a physical attack (uses the basic stats).*/
            bool status; /*!< \brief If `true`, the attack does not harm directly the opposite OpMon.*/
            int criticalRate; /*!< \brief The critical rate of the attack. It represents the denominator (one chance out of the value of the variable)*/
            bool neverFails; /*!< \brief If `true`, the attack can't fail.*/
            int pp;/*!<\brief The current pp of the attack.*/
            int ppMax; /*!< \brief The maximum base PP (Power points) of the attack.*/
            int priority; /*!< \brief The level of priority of the attack.*/
            AttackEffect *preEffect; /*!< \brief The attack effect applied before the calculation of the damages.*/
            AttackEffect *postEffect; /*!< \brief The attack effect applied after the calculation of the damages.*/
            AttackEffect *failEffect; /*!< \brief The attack effect applied if the attack fails.*/
            std::vector<TurnActionType> animationOrder; /*!< \brief The order in which the animations will occur.*/
            std::queue<View::Transformation> opAnimsAtk; /*!< \brief The animations linked to the attacking OpMon's sprite.*/
            std::queue<View::Transformation> opAnimsDef; /*!< \brief The animations linked to the attacked OpMon's sprite.*/
            std::queue<std::string> animations; /*!< \brief The animations played on the whole screen.*/

            /*!
             * \brief The number of HP lost by the opposite OpMon.
             */
            int hpLost = 0;
            /*!
             * \brief Used for attacks in multiple turns.
             */
            int part = 0;

            /*!
             * \brief Map containing the data of all the available attacks in the game.
             */
            static std::map<std::string, AttackData> attackList;

            /*!
             * \brief Generates the other version of the OpMon animations.
             * \details The OpMon animations are created to be used with the player's OpMon. This method generates opposite OpMon versions by creating a symmetry from the origin.
             */
            std::queue<View::Transformation> generateDefAnims(std::queue<View::Transformation> opAnims);
        };

    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
