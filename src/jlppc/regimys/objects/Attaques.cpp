
#include "Attaques.hpp"

void initAttaquesClass(void) {
	using namespace Attaques;

}

namespace Attaques {

	Class<Abime> *Abime::classe = new Class<Abime>("Abime", 0xFFFF);
	Class<Acidarmure> *Acidarmure::classe = new Class<Acidarmure>("Acidarmure", 0xFFFE);
	Class<Acide> *Acide::classe = new Class<Acide>("Acide", 0xFFFD);
	Class<Affutage> *Affutage::classe = new Class<Affutage>("Affutage", 0xFFFC);
	Class<Aiguisage> *Aiguisage::classe = new Class<Aiguisage>("Aiguisage", 0xFFFB);
	Class<Amnesie> *Amnesie::classe = new Class<Amnesie>("Amnesie", 0xFFFA);
	Class<Armure> *Armure::classe = new Class<Armure>("Armure", 0xFFF9);
	Class<Belier> *Belier::classe = new Class<Belier>("Belier", 0xFFF8);
	Class<Balayage> *Balayage::classe = new Class<Balayage>("Balayage", 0xFFF7);
	Class<BecVrille> *BecVrille::classe = new Class<BecVrille>("BecVrille", 0xFFF6);
	Class<Berceuse> *Berceuse::classe = new Class<Berceuse>("Berceuse", 0xFFF5);
	Class<BombOeuf> *BombOeuf::classe = new Class<BombOeuf>("BombOeuf", 0xFFF4);
	Class<Bouclier> *Bouclier::classe = new Class<Bouclier>("Bouclier", 0xFFF3);
	Class<Brouillard> *Brouillard::classe = new Class<Brouillard>("Brouillard", 0xFFF2);
	Class<BueeNoire> *BueeNoire::classe = new Class<BueeNoire>("BueeNoire", 0xFFF1);
	Class<BullesDo> *BullesDo::classe = new Class<BullesDo>("BullesDo", 0xFFF0);
	Class<CageEclair> *CageEclair::classe = new Class<CageEclair>("CageEclair", 0xFFEF);
	
	
	
	int Abime::effetAvant(OpMon &atk, OpMon &def) {
		precision = ((atk.getLevel() - def.getLevel()) + 30);
		if (atk.getLevel() < def.getLevel()) {
			return 2;
		}
		if (Utils::randU(100) > precision) {
			return 2;
		} else {
			def.attacked(def.getPV());
			return 2;
		}
	}

	int Acidarmure::effetApres(OpMon &atk, OpMon &def) {
		if (atk.changeDEF(2)) {
			//Texte
		} else {
			//Texte
		}
		return 2;
	}

	int Acide::effetApres(OpMon &atk, OpMon &def) {
		if (Utils::randU(10) == 2) {
			if (def.changeDEFSPE(-1)) {
				//Texte
			} else {
				//Texte
			}
		}
		return 0;
	}

	int Affutage::effetApres(OpMon &atk, OpMon &def) {
		if (atk.changeATK(1)) {
			//Texte
		} else {
			//Texte
		}
		return 0;
	}

	int Aiguisage::effetApres(OpMon &atk, OpMon &def) {
		if (atk.changeATK(1)) {
		} else {
		}
		if (atk.changePRE(1)) {
		} else {
		}
		return 0;
	}

	int Amnesie::effetApres(OpMon &atk, OpMon &def) {
		if (atk.changeDEFSPE(2)) {

		} else {

		}
		return 0;
	}

	int Armure::effetApres(OpMon &atk, OpMon &def) {
		if (atk.changeDEF(1)) {

		} else {

		}
		return 0;
	}

	int Belier::effetApres(OpMon &atk, OpMon &def) {
		atk.attacked(round(pvPerdus / 4));
		return 0;
	}

	int Balayage::effetAvant(OpMon &atk, OpMon &def) {
		if (def.getEspece()->getPoids() <= 10) {
			puissance = 20;
		} else if (def.getEspece()->getPoids() > 10 && def.getEspece()->getPoids() <= 25) {
			puissance = 40;
		} else if (def.getEspece()->getPoids() > 25 && def.getEspece()->getPoids() <= 50) {
			puissance = 60;
		} else if (def.getEspece()->getPoids() > 50 && def.getEspece()->getPoids() <= 100) {
			puissance = 80;
		} else if (def.getEspece()->getPoids() > 100 && def.getEspece()->getPoids() <= 200) {
			puissance = 100;
		} else {
			puissance = 120;
		}
		return 0;
	}

	int Berceuse::effetApres(OpMon &atk, OpMon &def) {
		if (def.setStatus(Status::SOMMEIL)) {

		} else {

		}
		return 0;
	}

	int Blizzard::effetApres(OpMon &atk, OpMon &def){
	    if(Utils::randU(10) == 2){
            //Texte
            def.setStatus(Status::GEL);
	    }
	}

	int Bouclier::effetApres(OpMon &atk, OpMon &def){
	    if(atk.changeDEF(2)){
	    }else{
	    }
		return 0;
		
	}

	int Brouillard::effetApres(OpMon &atk, OpMon &def){
	    if(def.changePRE(-1)){
	    }else{
	    }
		return 0;
		
	}	

	int BueeNoire::effetApres(OpMon &atk, OpMon &def){
	   // atk.setStats(Fight.oldStats[0], atk.getAttaques(), atk.getEspece(), new Type[]{atk.getType1(), atk.getType2()});
		//def.setStats(Fight.oldStats[1], def.getAttaques(), def.getEspece(), new Type[]{def.getType1(), def.getType2()});
		//TODO
	}


	int BullesDo::effetApres(OpMon &atk, OpMon &def){
	    if (Utils::randU(10) ==2){
		   if(def.changeVIT(-1)){
		   }else{
		   }
	     }
		return 0;
	}
	
	int CageEclair::effetApres(OpMon &atk, OpMon &def){
		if (def.getType1()==Type::ELECTRIQUE || def.getType2()==Type::ELECTRIQUE){
		}else{
		if(def.setStatus(Status::PARALYSIE)){
		}else{
		}	
		}
	} 
	return 0;

		






}; 

