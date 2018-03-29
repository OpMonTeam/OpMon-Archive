#include "Battle.hpp"
#include "../model/sysObjects/OpTeam.hpp"

namespace OpMon{
  namespace View{
    GameStatus Battle::operator()(Model::Turn* atkTurn){
      return GameStatus::CONTINUE;
    }

    GameStatus Battle::operator()(Model::Turn const& atk, Model::Turn const& def){
      return GameStatus::CONTINUE;
    }

    Battle::Battle(const Model::OpTeam* atkTeam, const Model::OpTeam* defTeam, std::string trainerClass, std::string background)
      : atkTeam(atkTeam), defTeam(defTeam){
    }
  }
}
