/*
 * EItem.cpp
 *
 *  Created on: 28 janv. 2017
 *      Author: Jlppc (session)
 */

#include "EItem.hpp"

E_Item::E_Item(int evo, Item *forEvolve) : Evolution(evo){
	this->forEvolve = forEvolve;
}
/* NE PAS UTILISER, inutile.*/
bool E_Item::checkEvolve(Pokemon const& toCheck) const{
	return false;
}

bool E_Item::itemEvolve(Item const* forEvolve) const{
	return this->forEvolve == forEvolve;
}

