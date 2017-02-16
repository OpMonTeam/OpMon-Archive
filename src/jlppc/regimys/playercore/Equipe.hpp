/*
Equipe.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la définition de la classe Equipe
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include <iostream>
#include "../objects/Pokemon.hpp"
/**
Classe permettant de contenir l'equipe d'un joueur ou d'un dresseur.
*/
class Equipe{
public:
	Equipe(std::string nom);
	std::string getNom() const {return nom;}
	Pokemon* getEquipe()  {return equipe;}
	void heal();
	/**
	Ajoute un pokémon a l'equipe. Renvoie false si l'equipe est pleine
	*/
	bool addPokemon(Pokemon toAdd);
	void removePoke(int number);
	/**
	Operateur permettant de recuperer le Pokémon a la place donnée en parametre
	*/
	Pokemon operator[](int id) const;
	bool isKo() const ;
	int getSize() const ;
	//Opérateurs non pratiques, mais je les met quand meme.Ils permettent de raccourcir l'utilisation de quelques methodes, mais ne sont surement pas conformes a leur utilisation de base.
	void operator+=(Pokemon const& pkmn){addPokemon(pkmn);}
	void operator-=(int id){removePoke(id);}
	/**Pokemon vide*/
	static Pokemon PNULL;

private:
    //T->Useless
	int nbreOfPoke = 6;
	Pokemon equipe[6] = {PNULL, PNULL, PNULL, PNULL, PNULL, PNULL};
	std::string nom;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
