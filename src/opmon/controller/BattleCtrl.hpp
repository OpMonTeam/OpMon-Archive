#pragma once

#include "../model/objects/OpMon.hpp"
#include "../view/Battle.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "AGameScreen.hpp"

namespace OpMon{
  namespace Controller{

    class BattleCtrl : public AGameScreen {
    private:
      /*The player's current OpMon*/
      Model::OpMon* atk;
      /*The opposite trainer's current OpMon*/
      Model::OpMon* def;

      Model::OpTeam* playerTeam;
      Model::OpTeam* trainerTeam;
      
      View::Battle battle;

      View::Turn* atkTurn;
      View::Turn* defTurn;
      
    public:
      BattleCtrl(Model::OpTeam* one, Model::OpTeam *two);
      GameStatus checkEvent(sf::Event const &) override;
      GameStatus update() override;
      bool turn();
    };

  }
}
