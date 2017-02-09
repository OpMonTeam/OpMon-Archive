
#include "Equipe.hpp"
#include "../objects/Pokemon.hpp"


Equipe::Equipe(string nom) {
	this->nom = nom;
}

void Equipe::heal(){
	for(int i = 0; i < nbreOfPoke; i++){
		if(equipe[i].falsif != PNULL.falsif){
			equipe[i].heal(equipe[i].getStatPV());
			equipe[i].confus = false;
			equipe[i].setStatus(Status::AUCUN);
		}

	}
}

bool Equipe::addPokemon(Pokemon toAdd){
	for(int i = 0; i < nbreOfPoke; i++){
		if(equipe[i] == PNULL){
			equipe[i] = toAdd;
			return true;
		}
	}
	return false;
}

void Equipe::removePoke(int number){//Number en partant de 0
	if(nbreOfPoke == 1){
		return;
	}
	for(int i = 0; i < nbreOfPoke; i++){
		if(i >= number){
			if(i != 5){
				equipe[i] = equipe[i + 1];
			}else{
				equipe[5] = PNULL;
			}
		}

	}
}

Pokemon Equipe::operator[](int id) const{
	return equipe[id];
}

bool Equipe::isKo() const{
	int ko = 0;
	for(int i = 0; i < nbreOfPoke; i++){
		if(equipe[i].falsif == PNULL.falsif){
			ko++;
		}else if(equipe[i].getPV() <= 0){
			ko++;
		}
	}
	return (ko == 6);
}

int Equipe::getSize() const{
	return nbreOfPoke;
}

