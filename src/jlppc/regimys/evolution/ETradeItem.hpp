
#ifndef SRCCPP_JLPPC_REGIMYS_EVOLUTION_ETRADEITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_EVOLUTION_ETRADEITEM_HPP_

#include "Evolution.hpp"
#include "EItem.hpp"

class E_TradeItem: public E_Item {
public:
	E_TradeItem(int evo, Item *forEvolve, int ID) : E_Item(evo, forEvolve){};
	bool checkEvolve(Pokemon const& toCheck);
	static const int evolID = 1;
};

#endif /* SRCCPP_JLPPC_REGIMYS_EVOLUTION_ETRADEITEM_HPP_ */
