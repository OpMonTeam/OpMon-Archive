/*
  ELevel.cpp
  Author : Cyrielle
  File under GNU GPL v3.0
*/
#include "evolutions.hpp"
#include "src/opmon/model/Evolution.hpp"
#include "src/opmon/model/OpMon.hpp"

namespace OpMon {
    namespace Evolutions {
        E_Level::E_Level(int evo, int level): Evolution(evo) {
            this->level = level;
        }

        bool E_Level::checkEvolve(OpMon const &toCheck) const {
            return (toCheck.getLevel() >= level);
        }
    } // namespace Evolutions

} // namespace OpMon
