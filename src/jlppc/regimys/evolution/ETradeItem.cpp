
#include "evolutions.hpp"


namespace Evolutions {
	bool E_TradeItem::checkEvolve(OpMon const &toCheck) {
		if (forEvolve == NULL) {
			return false;
		}
		Item *held = toCheck.itemHeld();
		return held == (forEvolve);
	}
}

