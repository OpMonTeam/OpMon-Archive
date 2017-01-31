
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
using namespace std;
#include "../objects/Espece.hpp"
#include "../objects/Pokemon.hpp"

class Evolution: public RegimysObject {
public:
	Evolution(int evo);
	virtual bool checkEvolve(Pokemon const& toCheck) = 0;
	Espece getEvolution();
	void checkEvo();

protected:
	Espece toEvolve;
	int evo;
};

#endif /* EVOLUTION_HPP */
