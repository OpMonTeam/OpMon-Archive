#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_

#include <iostream>
#include "includeAll.hxx"
#include <vector>
using namespace std;

class Player : public RegimysObject{
public:
	Player(string name);
	Equipe getEquipe() const;
	void addItem(int itemID);
	int checkItem(int itemID);
	bool deleteItem(int itemID);
	string getName() const {return name;}
	int getDressID() const {return dressID;}
	void addPokemonToPC(Pokemon toAdd){pc.push_back(toAdd);}
	Pokemon getPoke(int ID) const {return equipe[ID];}
	void healPoke();
	bool addPokeToEquipe(Pokemon toAdd);
	static const Class<Player> *classe = new Class<Player>("Player", 4698764);
private:
	string name;
	int dressID;//9 chiffres
	int bag[Item::getItemNumber()];
	vector<Pokemon> pc = vector<Pokemon>();
	Equipe equipe;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_ */
