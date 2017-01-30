
#include "ETradeItem.hpp"

bool E_TradeItem::checkEvolve(Pokemon toCheck){
	if(forEvolve == NULL){
		return false;
	}
	return toCheck.itemHeld() == (forEvolve);
}
