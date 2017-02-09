
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include <iostream>
#include "../objects/Pokemon.hpp"
using namespace std;

class Equipe{
public:
	Equipe(string nom);
	Equipe(){};
	string getNom() const {return nom;}
	Pokemon* getEquipe()  {return equipe;}
	void heal();
	bool addPokemon(Pokemon toAdd);
	void removePoke(int number);
	Pokemon operator[](int id) const;
	bool isKo() const ;
	int getSize() const ;
	//Opérateurs non pratique, mais je les met quand meme
	void operator+=(Pokemon const& pkmn){addPokemon(pkmn);}
	void operator-=(int id){removePoke(id);}
	static Pokemon PNULL;

private:

	int nbreOfPoke = 6;
	Pokemon equipe[6] = {PNULL, PNULL, PNULL, PNULL, PNULL, PNULL};
	string nom;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
