
#include "ETradeItem.hpp"

bool E_TradeItem::checkEvolve(Pokemon const& toCheck){
	if(forEvolve == NULL){
		return false;
	}
	Item *held = toCheck.itemHeld();
	return held == (forEvolve);
}
