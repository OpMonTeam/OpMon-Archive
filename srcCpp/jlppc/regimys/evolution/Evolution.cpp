
#include "Evolution.hpp"

Evolution::Evolution(int evo) {
	this->evo = evo;
}

void Evolution::checkEvo(){
	toEvolve = Initializer::listePoke[evo];
}

Espece Evolution::getEvolution(){
	return toEvolve;
}

