#include "CT.hpp"

CT::CT(std::string atk, int ctNumber, int ID) : Item(("CT" + ctNumber + atk), true, false, false, BagCat::CTS, ID),
    atk(atk) {
}

