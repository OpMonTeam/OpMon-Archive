
#ifndef ELEVEL_HPP
#define ELEVEL_HPP

#include "Evolution.hpp"

class E_Level: public Evolution {
public:
	E_Level(int evo, int level);
	bool checkEvolve(Pokemon const& toCheck) const;
	static const int evolID = 5;
private:
	int level;
};

#endif /* ELEVEL_HPP */
