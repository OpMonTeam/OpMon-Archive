#include "evolutions.hpp"


namespace Evolutions {
E_Item::E_Item(int evo, Item *forEvolve) : Evolution(evo), forEvolve(forEvolve) {
}
/* NE PAS UTILISER, inutile.*/
bool E_Item::checkEvolve(OpMon const &toCheck) const {
    return false;
}

bool E_Item::itemEvolve(Item *forEvolve) const {
    return this->forEvolve == forEvolve;
}
}


