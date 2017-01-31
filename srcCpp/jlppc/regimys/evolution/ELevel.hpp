
#ifndef ELEVEL_HPP
#define ELEVEL_HPP

#include "Evolution.hpp"

class E_Level: public Evolution {
public:
	E_Level(int evo, int level);
	bool checkEvolve(Pokemon const& toCheck) const;
	static const Class<E_Level> classe = new Class<E_Level>("E_Level", 7964684);
private:
	int level;
};

#endif /* ELEVEL_HPP */
