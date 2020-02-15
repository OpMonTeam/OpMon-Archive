/*!
 * \file Attacks.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors Navet56
 * \copyright GNU GPL v3.0
 */
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include <cmath>
#include <iostream>
#include <queue>

#include "../../nlohmann/json.hpp"
#include "Attack.hpp"
#include "OpMon.hpp"
#include "src/opmon/objects/Enums.hpp"
#include "src/opmon/views/objects/Turn.hpp"

namespace OpMon {
class OpMon;

    /*!
     * \brief Contains the AttackEffects used in the game.
     */
    namespace Attacks {
        /*!
         * \brief A generic effet to change an OpMon's statistic.
         */
        class ChangeStatEffect : public AttackEffect {
        public:
            /*!
             * \brief Sets the target for the effect.
             */
            enum class Target : int { ATTACKER = 0,/*!< The attack user will receive the stat modification.*/
                                      DEFENDER = 1 /*!< The attacked OpMon will receive the stat modification.*/};
            /*!
             * \param target The targeted OpMon.
             * \param stat The stat to change.
             * \param coef The coefficient of the modification to apply.
             */
            ChangeStatEffect(Target target, Stats stat, int coef);
            /*!
             * \brief Initialises the object from a json object.
             * \param data The json object.
             */
            ChangeStatEffect(nlohmann::json const &data);
            /*!
             * \brief Applies the stat modification.
             */
            int apply(Attack &attack, OpMon &attacker, OpMon &defender, std::queue<Elements::TurnAction> &turnQueue) override;

        protected:
            Target target;/*!<\brief The targeted OpMon.*/
            Stats stat;/*!<\brief The stat to change.*/
            int coef;/*!< \brief The coefficient of the modifications to apply.*/
        };
    } // namespace Attacks
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
