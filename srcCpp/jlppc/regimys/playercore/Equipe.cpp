
#include "Equipe.hpp"

Equipe::Equipe(string nom, Pokemon equipe[]) {
	int size = sizeof equipe;
	if(size < 6){
		Pokemon equipe2[6];
		for(int i = 0; i < 6; i++){
			if(i < size){
				equipe2[i] = equipe[i];
			}else{
				equipe2[i] = PNULL;
			}
		}
		equipe = equipe2;
	}
	for(int i = 0; i < size; i++){
		if(i > 5){
			break;
		}

		this->equipe[i] = equipe[i];
		if(equipe[i] != PNULL){
			nbreOfPoke++;
		}

	}
	if(nbreOfPoke == 0){
		Main::gererErreur("Erreur : Equipe générée sans Pokémon.", true);
	}
}

void Equipe::heal(){
	for(int i = 0; i < nbreOfPoke; i++){
		if(equipe[i] != PNULL){
			equipe[i].heal(equipe[i].getStatPV());
			equipe[i].confus = false;
			equipe[i].setStatus(Status::AUCUN);
		}

	}
}

bool Equipe::addPokemon(Pokemon toAdd){
	for(int i = 0; i < nbreOfPoke; i++){
		if(equipe[i] == NULL){
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
				equipe[5] = NULL;
			}
		}

	}
}

Pokemon Equipe::operator[](int id){
	return equipe[id];
}

bool Equipe::isKo() const{
	int ko = 0;
	for(int i = 0; i < nbreOfPoke; i++){
		if(equipe[i] == NULL){
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

