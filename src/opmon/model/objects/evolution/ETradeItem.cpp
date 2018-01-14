#include "evolutions.hpp"

namespace OpMon {
  namespace Model {

    namespace Evolutions {
      bool E_TradeItem::checkEvolve(OpMon const &toCheck) {
        if (forEvolve == nullptr) {
          return false;
        }
        Item *held = toCheck.itemHeld();
        return held == (forEvolve);
      }
    }

  }
}
