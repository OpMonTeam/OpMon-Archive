/*
BattleCtrl.hpp
Author : Cyriel
File under GNU GPL v3.0 license
*/
#pragma once

#include "../model/objects/Attack.hpp"
#include "../model/objects/Enums.hpp"
#include "../model/objects/OpMon.hpp"
#include "../model/objects/Species.hpp"
#include "../model/objects/Turn.hpp"
#include "../model/storage/BattleData.hpp"
#include "../model/sysObjects/Events.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "../view/Battle.hpp"
#include "AGameScreen.hpp"
#include <vector>

namespace OpMon {
    namespace Controller {

        class BattleCtrl : public AGameScreen {
          private:
            Model::BattleData data;

            Model::OpTeam *playerTeam;
            Model::OpTeam *trainerTeam;

            /*The player's current OpMon*/
            Model::OpMon *atk;
            /*The opposite trainer's current OpMon*/
            Model::OpMon *def;

            View::Battle view;

            std::queue<Model::TurnAction> actionsQueue;

            Model::TurnData atkTurn;
            Model::TurnData defTurn;

            //These variables are used to restore the OpMon's stats after the battle
            int oldStats[2][5];
            Model::Type oldTypes[2][2];
            const Model::Species *oldSpecies[2];
            std::vector<Model::Attack *> oldAttacks[2];

            int trainerOpCount = 0;

            bool turnActivated = false;

            /** Counters and triggers for the fight*/
            bool sameAtk = false;
            bool sameDef = false;
            bool captured = false;

            /* Used to calculate one turn (Who attacks first, and then the attacks and so) */
            bool turn();
            /* Initialize a battle between two OpMons. The opId are for the OpMon's number in the team */
            void initBattle(int opId, int opId2);

            Model::TurnData *turnIA(int level);

            //Checks if the opmon can attack
            bool canAttack(Model::OpMon *opmon, Model::TurnData *opTurn);
            bool checkBattleEnd();

            Model::Events::TrainerEvent *trainer;

          public:
            virtual ~BattleCtrl() = default;
            BattleCtrl(Model::OpTeam *one, Model::OpTeam *two, Model::UiData *uidata, Model::Player *player);
            BattleCtrl(Model::OpTeam *one, Model::Events::TrainerEvent *two, Model::UiData *uidata, Model::Player *player);
            GameStatus checkEvent(sf::Event const &) override;
            GameStatus update(sf::RenderWindow &frame) override;

            virtual void suspend();
            virtual void resume();
        };

    } // namespace Controller
} // namespace OpMon
