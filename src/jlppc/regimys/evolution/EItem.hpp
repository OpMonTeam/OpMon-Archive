
#ifndef EITEM_HPP
#define EITEM_HPP

#include "Evolution.hpp"

class E_Item: public Evolution {
public:
	E_Item(int evo, Item *forEvolve);
	bool checkEvolve(Pokemon  const& toCheck) const;
	bool itemEvolve(Item const* forEvolve) const;
	static const int evolID = 7;

protected:
	Item *forEvolve;
};

#endif /* EITEM_HPP */
