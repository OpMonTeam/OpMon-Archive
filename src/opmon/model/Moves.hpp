/*!
 * \file Moves.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors Navet56
 * \copyright GNU GPL v3.0
 */
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include "../../nlohmann/json.hpp"
#include "Move.hpp"

namespace OpMon {
    class OpMon;

    /*!
     * \brief Contains the MoveEffects used in the game.
     */
    namespace Moves {
        /*!
         * \brief A generic effet to change an OpMon's statistic.
         */
        class ChangeStatEffect : public MoveEffect {
          public:
            /*!
             * \brief Sets the target for the effect.
             */
            enum class Target : int {
                MOVEER =
                    0, /*!< The move user will receive the stat modification.*/
                DEFENDER = 1 /*!< The attacked OpMon will receive the stat
                                modification.*/
            };
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
            int apply(Move &move, OpMon &attacker, OpMon &defender,
                      std::queue<Elements::TurnAction> &turnQueue) override;

          protected:
            Target target; /*!<\brief The targeted OpMon.*/
            Stats stat;    /*!<\brief The stat to change.*/
            int coef; /*!< \brief The coefficient of the modifications to apply.*/
        };
    } // namespace Moves
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
