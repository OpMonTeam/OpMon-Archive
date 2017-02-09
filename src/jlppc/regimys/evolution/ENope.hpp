
#ifndef SRCCPP_JLPPC_REGIMYS_EVOLUTION_ENOPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_EVOLUTION_ENOPE_HPP_

#include "Evolution.hpp"

class E_Nope {
public:
	E_Nope();
	bool checkEvolve(Pokemon const& toCheck) const;
	static const int evolID = 3;
};

#endif /* SRCCPP_JLPPC_REGIMYS_EVOLUTION_ENOPE_HPP_ */
