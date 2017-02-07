
#ifndef SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELOVE_HPP_
#define SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELOVE_HPP_

#include "Evolution.hpp"

class E_Love: public Evolution {
public:
	E_Love(int evo) : Evolution(evo){}
	bool checkEvolve(Pokemon const& toCheck) const {return (toCheck.getStatLove() > 100);}
	static const int evolID = 4;
private:

};

#endif /* SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELOVE_HPP_ */
