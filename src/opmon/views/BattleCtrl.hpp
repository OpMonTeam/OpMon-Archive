/*!
 * \file BattleCtrl.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
*/
#pragma once

#include "../objects/Attack.hpp"
#include "../objects/Enums.hpp"
#include "../objects/OpMon.hpp"
#include "../objects/Species.hpp"
#include "objects/Turn.hpp"
#include "BattleData.hpp"
#include "objects/Events.hpp"
#include "../objects/OpTeam.hpp"
#include "Battle.hpp"
#include "base/AGameScreen.hpp"
#include <vector>

namespace OpMon {
    namespace Controller {

        /*!
         * \brief Manages a battle.
         *
         * A battle is called in Overworld by a TrainerEvent. This controller is then created to manage the battle. When a battle is over, TurnActionType::VICTORY or TurnActionType::DEFEAT is sent to the view, which then sends GameStatus::PREVIOUS to the Gameloop, returning in the Overworld.
         *
         * Each turn is calculated by turn(), and then the data is stored in a queue of TurnAction objects to transmit the information to the view, which will then do the corresponding animations.
         */
        class BattleCtrl : public AGameScreen {
          private:
            Model::BattleData data;

            Model::OpTeam *playerTeam;
            Model::OpTeam *trainerTeam;

            /*!
             * \brief The player's current OpMon.
             */
            Model::OpMon *atk;
            /*!
             * \brief The opposite trainer's current OpMon.
             */
            Model::OpMon *def;

            View::Battle view;

            /*!
             * \brief The queue of actions done in the turn.
             * \details These actions are then transmitted to the view (Battle) to animate the screen.
             */
            std::queue<Model::TurnAction> actionsQueue;

            /*!
             * \brief The data of the player's turn.
             */
            Model::TurnData atkTurn;
            /*!
             * \brief The data of the opponent's turn.
             */
            Model::TurnData defTurn;
            /*!
             * \brief `true` if the player's OpMon attacks first, `false` otherwise.
             */
            bool atkFirst;

            //These variables are used to restore the OpMon's stats after the battle
            /*!
             * \brief The stats of the currently fighting OpMons before entering the battle.
             * \details These stats are used to reset the stats the battle.
             */
            int oldStats[2][5];
            /*!
             * \brief The types of the currently fighting OpMons before entering the battle.
             * \details These types are used to reset the types after the battle.
             */
            Model::Type oldTypes[2][2];
            /*!
             * \brief The species of the currently fighting OpMons before entering the battle.
             * \details These species are used to reset the species after the battle.
             */
            const Model::Species *oldSpecies[2];
            /*!
             * \brief The attacks of the currently fighting OpMons before entering the battle.
             * \details These attacks are used to reset the attacks after the battle.
             */
            std::vector<Model::Attack *> oldAttacks[2];

            /*!
             * \brief `true` if the battle is in the turns phase.
             * \details This variable is used to communicate with Battle. Battle has its own version of the variable, Battle::turnLaunched, allowing it to detect when this variable changes, and then starts the battle. When the turns phase is over, Battle changes the value of turnActivated to `false` (thanks to a pointer sent in Battle::operator()()), and then detects the update when the method is called again.
             */
            bool turnActivated = false;

            /** Counters and triggers for the fight*/
            /*!
             * \brief If `true`, the player's OpMon has to do the same move in the next turn.
             */
            bool sameAtk = false;
            /*!
             * \brief If `true`, the opponent's OpMon has to do the same move in the next turn.
             */
            bool sameDef = false;

            /*!
             * \brief Calculates one turn.
             *
             * This method calculates first who attacks first, and then calculates the different actions and their consequences by calling the Attack::attack methods of the moves. This method takes in parameter a reference to the TurnAction queue, so the moves can fill it.
             */
            bool turn();
            /*!
             * \brief Initialize a battle between two OpMons.
             * \param opId The first sent OpMon order in the player's team.
             * \param opId2 The first sent OpMon order in the opponent's team.
             */
            void initBattle(int opId, int opId2);

            /*!
             * \warning WIP
             * \brief Makes the IA choosing the actions of the opponent.
             * \details This methods currently chooses the first attack.
             * \param level The level of intelligence for the IA
             */
            Model::TurnData *turnIA(int level);

            /*!
             * \brief Checks if the OpMon can attack.
             * \param opmon The OpMon to check.
             * \param opTurn The data of this turn.
             */
            bool canAttack(Model::OpMon *opmon, Model::TurnData *opTurn);
            /*!
             * \brief Checks if the battle is over.
             * \returns `true` if the battle is over, `false` otherwise.
             * \details This method also adds a TurnActionType::VICTORY or TurnActionType::DEFEAT to the BattleCtrl::actionsQueue if the battle is over.
             */
            bool checkBattleEnd();

            /*!
             * \brief The opposite trainer.
             */
            Model::Events::TrainerEvent *trainer;

            /*!
             * \brief A shortcut to a TurnActionType::NEXT
             */
            Model::TurnAction next;

          public:
            virtual ~BattleCtrl() = default;
            /*!
             * \brief Initialises a battle with two OpTeam.
             * \param one The player's team.
             * \param two The opponent's team.
             * \param uidata The UiData object.
             * \param player The Player object.
             */
            BattleCtrl(Model::OpTeam *one, Model::OpTeam *two, Model::UiData *uidata, Model::Player *player);
            /*!
             * \brief Initialises a battle between the player and a trainer.
             * \param one The player's team.
             * \param two The opposite trainer.
             * \param uidata The UiData object.
             * \param player The Player object.
             */
            BattleCtrl(Model::OpTeam *one, Model::Events::TrainerEvent *two, Model::UiData *uidata, Model::Player *player);
            GameStatus checkEvent(sf::Event const &) override;
            GameStatus update(sf::RenderTexture &frame) override;

            virtual void suspend() override;
            virtual void resume() override;
        };

    } // namespace Controller
} // namespace OpMon
