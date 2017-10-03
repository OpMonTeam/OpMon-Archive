#include "CT.hpp"

CT::CT(Class<Attack *> atk, int ctNumber, int ID) : Item(("CT" + ctNumber + atk.getName()), true, false, false, BagCat::CTS, ID),
    atk(atk) {
}

