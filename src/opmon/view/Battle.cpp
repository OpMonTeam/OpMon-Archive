#include "Battle.hpp"

namespace OpMon{
  namespace View{
    GameStatus Battle::operator()(Model::Turn* atkTurn){
      return GameStatus::CONTINUE;
    }

    GameStatus Battle::operator()(Model::Turn const& atk, Model::Turn const& def){
      return GameStatus::CONTINUE;
    }
  }
}
