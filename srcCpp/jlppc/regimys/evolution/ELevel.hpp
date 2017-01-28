
#ifndef ELEVEL_HPP
#define ELEVEL_HPP

#include "Evolution.hpp"

class E_Level: public Evolution {
public:
	E_Level(int evo, int level);
	bool checkEvolve(Pokemon toCheck);
private:
	int level;
};

#endif /* ELEVEL_HPP */
