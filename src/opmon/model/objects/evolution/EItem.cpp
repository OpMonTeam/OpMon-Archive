/*
EItem.cpp
Author : Cyrion
File under GNU GPL v3.0
*/
#include "evolutions.hpp"
#pragma GCC diagnostic ignored "-Wunused-parameter"
namespace OpMon {
    namespace Model {

        namespace Evolutions {
            E_Item::E_Item(int evo, Item *forEvolve)
              : Evolution(evo)
              , forEvolve(forEvolve) {
            }
            /* DO NOT USE. It's useless.*/
            bool E_Item::checkEvolve(OpMon const &toCheck) const {
                return false;
            }

            bool E_Item::itemEvolve(Item *forEvolve) const {
                return this->forEvolve == forEvolve;
            }
        } // namespace Evolutions

    } // namespace Model
} // namespace OpMon
#pragma GCC diagnostic pop
