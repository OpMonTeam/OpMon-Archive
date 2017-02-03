
#include "Attaques.hpp"

namespace Attaques {
int Abime::effetAvant(Pokemon &atk, Pokemon &def){
	precision = ((atk.getLevel() - def.getLevel()) + 30);
	if(atk.getLevel() < def.getLevel()){
		return 2;
	}
	if(Utils::randU(100) > precision){
		return 2;
	}else{
		def.attacked(def.getPV());
		return 2;
	}
}

int Acidarmure::effetApres(Pokemon &atk, Pokemon &def){
	if(atk.changeDEF(2)){
		//Texte
	}else{
		//Texte
	}
	return 2;
}
	
	int Acide::effetApres(Pokemon &atk, Pokemon &def){
		if(Utils::randU(10) == 2){
			if(def.changeDEFSPE(-1)){
				//Texte
			}else{
				//Texte
			}
		}
		return 0;
	}
	
	int Affutage::effetApres(Pokemon &atk, Pokemon &def){
		if(atk.changeATK(1)){
			//Texte
		}else{
			//Texte
		}
		return 0;
	}
	
	int Aiguisage::effetApres(Pokemon &atk, Pokemon &def){
		if(atk.changeATK(1)){
		}else{
		}
		if(atk.changePRE(1)){
		}else{
		}
		return 0;
	}

	int Amnesie::effetApres(Pokemon &atk, Pokemon &def){
		if(atk.changeDEFSPE(2)){

		}else{

		}
		return 0;
	}

	int Armure::effetApres(Pokemon &atk, Pokemon &def){
		if(atk.changeDEF(1)){

		}else{

		}
		return 0;
	}

	int Belier::effetApres(Pokemon &atk, Pokemon &def){
		atk.attacked(round(pvPerdus / 4));
		return 0;
	}
	
	int Balayage::effetApres(Pokemon &atk, Pokemon &def){
		if(def.getEspece().getPoids() <= 10){
			puissance = 20;
		}else if(def.getEspece().getPoids() > 10 && def.getEspece().getPoids() <= 25){
			puissance = 40;
		}else if(def.getEspece().getPoids() > 25 && def.getEspece().getPoids() <=50){
			puissance = 60;
		}else if(def.getEspece().getPoids() > 50 && def.getEspece().getPoids() <= 100){
			puissance = 80;
		}else if(def.getEspece().getPoids() > 100 && def.getEspece().getPoids() <= 200){
			puissance = 100;
		}else{
			puissance = 120;
		}
	}
	
	int Berceuse::effetApres(Pokemon &atk, Pokemon &def){
		if(def.setStatus(Status::SOMMEIL)){
			
		}else{
			
		}
	}
}
