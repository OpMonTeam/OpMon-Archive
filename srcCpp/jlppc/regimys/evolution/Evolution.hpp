
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
using namespace std;
#include "../objects/Espece.hpp"
#include "../objects/Pokemon.hpp"

class Evolution: public RegimysObject {
public:
	Evolution(int evo);
	virtual bool checkEvolve(Pokemon toCheck) = 0;
	Espece getEvolution();
	void checkEvo();
	Class<Evolution> *classe = new Class<Evolution>("Evolution", 4698135);
protected:
	Espece toEvolve;
	int evo;
};

#endif /* EVOLUTION_HPP */
