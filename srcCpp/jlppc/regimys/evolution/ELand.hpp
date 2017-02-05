
#ifndef SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELAND_HPP_
#define SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELAND_HPP_

#include "Evolution.hpp"
#include <iostream>
#include "../../utils/Class.hpp"
#include "Evolution.hpp"
using namespace std;

class E_Land: public Evolution {
public:
	E_Land(int evo, string lieu);
	bool checkEvolve (Pokemon const& toCheck) const {return false;}//Il faudra tester si l'endroit ou se trouve le dresseur est le bon.
	static Class<E_Land> *classe = new Class<E_Land>("E_Land", 0xEEEEE);
private:
	//Plan carteDuLieu;
};

#endif /* SRCCPP_JLPPC_REGIMYS_EVOLUTION_ELAND_HPP_ */
