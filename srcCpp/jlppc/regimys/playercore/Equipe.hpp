
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include <iostream>
#include "../start/main.hpp";
#include "../objects/Pokemon.hpp"
#include "../enums/Enums.hpp"
using namespace std;

class Equipe : public RegimysObject {
public:
	static Class<Equipe> *classe = new Class<Equipe>("Equipe", 7324695);
	Equipe(string nom, Pokemon pokemons[]);
	string getNom(){return nom;}
	Pokemon* getEquipe(){return &equipe;}
	void heal();
	bool addPokemon(Pokemon toAdd);
	void removePoke(int number);
	Pokemon operator[](int id);
	bool isKo();
	int getSize();
	//Opérateurs non pratique, mais je les met quand meme;
	Equipe operator+=(Pokemon pkmn){addPokemon(pkmn);return *this;}
	Equipe operator-=(int id){removePoke(id);return *this;}

private:
	int nbreOfPoke;
	Pokemon equipe[] = {NULL,NULL,NULL,NULL,NULL,NULL};
	string nom;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
