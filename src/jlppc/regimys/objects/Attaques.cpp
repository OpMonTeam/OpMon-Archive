
#include "Attaques.hpp"

void initAttaquesClass(void){
    using namespace Attaques;

}

namespace Attaques {

    Class<Abime>* Abime::classe = new Class<Abime>("Abime", 0xFFFF);
    Class<Acidarmure>* Acidarmure::classe = new Class<Acidarmure>("Acidarmure", 0xFFFE);
    Class<Acide>* Acide::classe = new Class<Acide>("Acide", 0xFFFD);
    Class<Affutage>* Affutage::classe = new Class<Affutage>("Affutage", 0xFFFC);
    Class<Aiguisage>* Aiguisage::classe = new Class<Aiguisage>("Aiguisage", 0xFFFB);
    Class<Amnesie>* Amnesie::classe = new Class<Amnesie>("Amnesie", 0xFFFA);
    Class<Armure>* Armure::classe = new Class<Armure>("Armure", 0xFFF9);
    Class<Belier>* Belier::classe = new Class<Belier>("Belier", 0xFFF8);
    Class<Balayage>* Balayage::classe = new Class<Balayage>("Balayage", 0xFFF7);
    Class<BecVrille>* BecVrille::classe = new Class<BecVrille>("Bec Vrille", 0xFFF6);
    Class<Berceuse>* Berceuse::classe = new Class<Berceuse>("Berceuse", 0xFFF5);


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

int Balayage::effetAvant(Pokemon &atk, Pokemon &def){
	if(def.getEspece()->getPoids() <= 10){
		puissance = 20;
	}else if(def.getEspece()->getPoids() > 10 && def.getEspece()->getPoids() <= 25){
		puissance = 40;
	}else if(def.getEspece()->getPoids() > 25 && def.getEspece()->getPoids() <=50){
		puissance = 60;
	}else if(def.getEspece()->getPoids() > 50 && def.getEspece()->getPoids() <= 100){
		puissance = 80;
	}else if(def.getEspece()->getPoids() > 100 && def.getEspece()->getPoids() <= 200){
		puissance = 100;
	}else{
		puissance = 120;
	}
	return 0;
}

int Berceuse::effetApres(Pokemon &atk, Pokemon &def){
	if(def.setStatus(Status::SOMMEIL)){

	}else{

	}
	return 0;
}
};

