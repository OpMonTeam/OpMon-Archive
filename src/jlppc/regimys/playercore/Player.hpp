/*
Player.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la définition de la classe Player
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_

#include <iostream>
#include <vector>
#include "Equipe.hpp"
#include "../objects/item/Item.hpp"
/**
Classe représentant le joueur
*/
class Player{
public:
	Player(std::string name);
	Equipe getEquipe() const;
	void addItem(int itemID);
	int checkItem(int itemID);
	bool deleteItem(int itemID);
    std::string getName() const {return name;}
	int getDressID() const {return dressID;}
	void addPokemonToPC(Pokemon toAdd){pc.push_back(toAdd);}
	Pokemon getPoke(int ID) const {return equipe[ID];}
	void healPoke();
	bool addPokeToEquipe(Pokemon toAdd);
private:
	std::string name;
	unsigned int dressID;//jusqu'a 8 chiffres (Hexadecimal) (jusqu'a 16^8)
	int bag[ITEM_NUMBER];
	std::vector<Pokemon> pc = std::vector<Pokemon>();
	Equipe equipe;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_ */
