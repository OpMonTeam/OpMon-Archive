#include "CT.hpp"

namespace OpMon {
    namespace Model {

        CT::CT(std::string atk, int ctNumber, int ID)
          : Item(("CT" + ctNumber + atk), true, false, false, BagCat::HMS, ID)
          , atk(atk) {
        }

    } // namespace Model
} // namespace OpMon
