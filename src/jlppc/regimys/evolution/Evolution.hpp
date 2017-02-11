
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
#include "../objects/Pokemon.hpp"
#include "../../utils/Class.hpp"

using namespace std;

class Espece;

class Evolution{
public:
	virtual ~Evolution(){}
	Evolution(int evo);
	virtual bool checkEvolve(Pokemon const& toCheck) const = 0;
	Espece* getEvolution() const;
	void checkEvo();
	virtual int getEvolID() const{return evolID;}
	virtual bool itemEvolve(Item *tem) const{return false;}


protected:
    static const int evolID = 0;
	Espece *toEvolve;
	int evo;
};

#endif /* EVOLUTION_HPP */
