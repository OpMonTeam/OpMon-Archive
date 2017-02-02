
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include <iostream>
#include "../../includeAll.hxx"
using namespace std;

class Equipe : public RegimysObject {
public:
	static const Class<Equipe> *classe = new Class<Equipe>("Equipe", 7324695);
	Equipe(string nom, Pokemon pokemons[]);
	string getNom() const {return nom;}
	Pokemon* getEquipe() const {return &equipe;}
	void heal();
	bool addPokemon(Pokemon toAdd);
	void removePoke(int number);
	Pokemon operator[](int id);
	bool isKo() const ;
	int getSize() const ;
	//Opérateurs non pratique, mais je les met quand meme;
	void operator+=(Pokemon const& pkmn){addPokemon(pkmn);}
	void operator-=(int id){removePoke(id);}
	static Pokemon PNULL = Pokemon();

private:

	int nbreOfPoke;
	Pokemon equipe[] = {PNULL, PNULL, PNULL, PNULL, PNULL, PNULL};
	string nom;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
