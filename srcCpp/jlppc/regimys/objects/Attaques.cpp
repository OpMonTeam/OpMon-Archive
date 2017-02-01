
#include "Attaques.hpp"

namespace Attaques {
int Abime::effetAvant(Pokemon atk, Pokemon def){
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

int Abime::effetApres(Pokemon atk, Pokemon def){
	if(atk.changeDEF(2)){
		//Texte
	}else{
		//Texte
	}
	return 2;
}
}
