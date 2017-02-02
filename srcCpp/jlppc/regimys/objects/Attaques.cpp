
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
	}
}
