/*
Evolution.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#include "Evolution.hpp"

namespace OpMon {
    namespace Model {

        Evolution::Evolution(int evo)
          : evo(evo) {
        }

        Species *Evolution::getEvolution() const {
            return toEvolve;
        }

    } // namespace Model
} // namespace OpMon
