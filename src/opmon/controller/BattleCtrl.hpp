#pragma once

#include "../model/objects/Attack.hpp"
#include "../model/objects/Enums.hpp"
#include "../model/objects/OpMon.hpp"
#include "../model/objects/Species.hpp"
#include "../model/objects/Turn.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "../view/Battle.hpp"
#include "AGameScreen.hpp"
#include <vector>

namespace OpMon {
    namespace Controller {

        class BattleCtrl : public AGameScreen {
          private:
            /*The player's current OpMon*/
            Model::OpMon *atk;
            /*The opposite trainer's current OpMon*/
            Model::OpMon *def;

            Model::OpTeam *playerTeam;
            Model::OpTeam *trainerTeam;

            View::Battle view;

            Model::Turn atkTurn;
            Model::Turn defTurn;

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

            /* Used to calculate a turn */
            bool turn();
            /* Initialize a battle between two OpMons. The opId are for the OpMon's number in the team */
            void initBattle(int opId, int opId2);
            //TODO
            Model::Turn *turnIA(int level);

            //check if the opmon can attack
            bool canAttack(Model::OpMon *opmon, Model::Turn *opTurn);

          public:
            BattleCtrl(Model::OpTeam *one, Model::OpTeam *two);
            GameStatus checkEvent(sf::Event const &) override;
	  GameStatus update(sf::RenderTexture& frame) override;
        };

    } // namespace Controller
} // namespace OpMon
