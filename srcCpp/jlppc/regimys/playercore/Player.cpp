#include "Player.hpp"

Player::Player(string name) {
	this->name = name;
	dressID = Utils::randU(999999999);
	equipe = Equipe(this->name);

}

Equipe Player::getEquipe(){
	return equipe;
}

void Player::addItem(int itemID){
	bag[itemID]++;
}

int Player::checkItem(int itemID){
	if(itemID > sizeof bag || itemID < 0){
		Main::gererErreur("Player : itemID invalide", true);
	}
	return bag[itemID];
}

bool Player::deleteItem(int itemID){

	if(bag[itemID] != 0 || itemID < 0){
		Main::gererErreur("Player : itemID invalide", true);
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
			Attaque atk = (*pkmn.getAttaques())[j];
			atk.healPP();

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
