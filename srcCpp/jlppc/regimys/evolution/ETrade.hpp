
#ifndef SRCCPP_JLPPC_REGIMYS_EVOLUTION_ETRADE_HPP_
#define SRCCPP_JLPPC_REGIMYS_EVOLUTION_ETRADE_HPP_

#include "Evolution.hpp"

class E_Trade: public Evolution {
public:
	E_Trade(int evo) : Evolution(evo){};
	bool checkEvolve(Pokemon const& toCheck) const {return true;}
	static Class<E_Trade> *classe;
};

#endif /* SRCCPP_JLPPC_REGIMYS_EVOLUTION_ETRADE_HPP_ */
