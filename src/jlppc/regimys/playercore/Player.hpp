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
class Player {
	public:
		Player(std::string name);
		Equipe getEquipe() const;
		/**Ajoute un item au sac*/
		void addItem(int itemID);
		/**Renvoie le nombre d'exemplaires dans le sac de l'item donné en paramètres*/
		int checkItem(int itemID);
		/**Enlève un exemplaire de l'item dans le sac donné en paramètres*/
		bool deleteItem(int itemID);
		std::string getName() const {return name;}
		int getDressID() const {return dressID;}
		void addPokemonToPC(Pokemon toAdd) {pc.push_back(toAdd);}
		Pokemon getPoke(int ID) const {return equipe[ID];}
		/**Soigne tous les Poké*/
		void healPoke();
		/**Essaie d'ajouter un pokémon a l'equipe. Renvoie false si ce n'est pas possible*/
		bool addPokeToEquipe(Pokemon toAdd);
	private:
		std::string name;
		unsigned int dressID;//jusqu'a 8 chiffres (Hexadecimal) (jusqu'a 16^8)
		int bag[ITEM_NUMBER];
		std::vector<Pokemon> pc = std::vector<Pokemon>();
		Equipe equipe = Equipe("temp");
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_ */
