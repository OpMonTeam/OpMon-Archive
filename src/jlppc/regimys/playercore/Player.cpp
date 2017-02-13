#include "Player.hpp"
#include "../start/main.hpp"

Player::Player(string name) {
	this->name = name;
	dressID = Utils::randUI(0xFFFFFFFF);
	equipe = Equipe(name);

}

Equipe Player::getEquipe() const{
	return equipe;
}

void Player::addItem(int itemID){
	bag[itemID]++;
}

int Player::checkItem(int itemID){
	unsigned int itemID2 = itemID;
	if(itemID2 > ITEM_NUMBER || itemID2 < 0){
		gererErreur("Player : itemID invalide", true);
	}
	return bag[itemID];
}

bool Player::deleteItem(int itemID){

	if(bag[itemID] != 0 || itemID < 0){
		gererErreur("Player : itemID invalide", true);
	}
	if(bag[itemID] != 0){
		bag[itemID]--;
		return true;
	}else{
		return false;
	}
}

void Player::healPoke(){
	equipe.heal();
	for(int i = 0; i < equipe.getSize(); i++){
		Pokemon pkmn = equipe[i];

		pkmn.amour = false;
		pkmn.malediction = false;
		pkmn.vampigraine = false;
		for(int j = 0; j < 4;j++){
			Attaque *atk = (pkmn.getAttaques())[j];
			atk->healPP();

		}


	}
}

bool Player::addPokeToEquipe(Pokemon toAdd){
	if(equipe.addPokemon(toAdd)){
		return true;
	}else{
		addPokemonToPC(toAdd);
		return false;
	}
}
