#include "Evolution.hpp"

namespace OpMon{
  namespace Model{

    Evolution::Evolution(int evo) : evo(evo) {
    }

    void Evolution::checkEvo() {
      //toEvolve = Initializer::listOp[evo];
    }

    Species *Evolution::getEvolution() const {
      return toEvolve;
    }

  }
}
