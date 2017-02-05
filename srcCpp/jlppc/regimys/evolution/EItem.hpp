
#ifndef EITEM_HPP
#define EITEM_HPP

#include "Evolution.hpp"

class E_Item: public Evolution {
public:
	E_Item(int evo, Item forEvolve);
	bool checkEvolve(Pokemon  const& toCheck) const;
	bool itemEvolve(Item const& forEvolve) const;
	static Class<E_Item> *classe = new Class<E_Item>("E_Item", 3644954);

private:
	Item forEvolve;
};

#endif /* EITEM_HPP */
