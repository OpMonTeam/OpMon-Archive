
#ifndef SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELAND_HPP_
#define SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELAND_HPP_


#include <iostream>
#include "Evolution.hpp"
#include "../../utils/Class.hpp"

using namespace std;

class E_Land: public Evolution {
public:
	E_Land(int evo, string lieu);
	bool checkEvolve (Pokemon const& toCheck) const {return false;}//Il faudra tester si l'endroit ou se trouve le dresseur est le bon.
	static Class<E_Land> *classe;
private:
	//Plan carteDuLieu;
};

#endif /* SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELAND_HPP_ */
