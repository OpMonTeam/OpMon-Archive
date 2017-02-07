
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
#include "../objects/Pokemon.hpp"
#include "../../utils/Class.hpp"

using namespace std;

class Espece;

class Evolution{
public:
	virtual ~Evolution();
	Evolution(int evo);
	virtual bool checkEvolve(Pokemon const& toCheck) const = 0;
	Espece* getEvolution() const;
	void checkEvo();
	virtual Class<Evolution>* getClass(){return classe;}
	virtual bool itemEvolve(Item *tem){return false;}

protected:
	static Class<Evolution> *classe;
	Espece *toEvolve;
	int evo;
};

#endif /* EVOLUTION_HPP */
