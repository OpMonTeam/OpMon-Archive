
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
	Class<CanonGraine> *CanonGraine::classe = new Class<CanonGraine>("Canongraine", 0xFFEE);
        Class<Cascade> *Cascade::classe = new Class<Cascade>("Cascade", 0xFFED);
	Class<Charge> *Charge::classe = new Class<Charge>("Charge", 0xFFEC);
	Class<ChocMental> *ChocMental::classe = new Class<ChocMental>("ChocMental", 0xFFEB);
	Class<ChocPsy> *ChocPsy::classe = new Class<ChocPsy>("ChocPsy", 0xFFEA);
	Class<ComboGriffe> *ComboGriffe::classe = new Class<ComboGriffe>("ComboGriffe", 0xFFE9);
	Class<Conversion> *Conversion::classe = new Class<Conversion>("Conversion", 0xFFE8);
	Class<CoupdBoule> *CoupdBoule::classe = new Class<CoupdBoule>("CoupdBoule", 0xFFE7);
	Class<CoudKrane> *CoudKrane::classe = new Class<CoudKrane>("CoudKrane", 0xFFE6);
	Class<CoupeVent> *CoupeVent::classe = new Class<CoupeVent>("CoupeVent", 0xFFE5);
	Class<CrocDeMort> *CrocDeMort::classe = new Class<CrocDeMort>("CrocDeMort", 0xFFE4);
	Class<CrocFatal> *CrocFatal::classe = new Class<CrocFatal>("CrocFatal", 0xFFE3);



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
		return 0;
	}

	int Cascade::effetApres(OpMon &atk, OpMon &def){
		if (Utils::randU(5) ==2){
		def.peur = true;
		}
		return 0;
	}

	int ChocMental::effetApres(OpMon &atk, OpMon &def){
		if (Utils::randU(10) ==2){
		def.confus = true;
		}
		return 0;
	}

	int ChocPsy::effetAvant(OpMon &atk, OpMon &def){
		this->def = def.getStatDEF();
		this->defspe = def.getStatDEFSPE();
		def.setStat("DEFSPE", this->def);
		return 0;
	}

	int ChocPsy::effetApres(OpMon &atk, OpMon &def){
		def.setStat("DEFSPE", this->defspe);
		return 0;
	}

	int ComboGriffe::effetApres(OpMon &atk, OpMon &def){
		if(def.getPV() <= 0){
			return 0;
		}
		int it = 0;
		int coups = Utils::randU(4);
		for(it = 0; it != coups + 1; it++){
			def.attacked(pvPerdus);
			if(def.getPV() <= 0){
				return 0;
			}
		}
		return 0;
	}

	int Conversion::effetApres(OpMon &atk, OpMon &def){
		Attaque **tab = atk.getAttaques();
		atk.setType1(tab[0]->getType());
		atk.setType2(Type::AUCUN);
		return 0;
	}

	int CoupdBoule::effetApres(OpMon &atk, OpMon &def){
		if (Utils::randU(100) <= 30){
		}
		return 0;
	}
	int CoudKrane::effetAvant(OpMon &atk, OpMon &def){
		if (part==0){
			def.changeDEF(1);
			part = 1;
			return 1;
		}else{
			part = 0;
			def.changeDEF(-1);
			return 0;
		}
		}
	int CoupeVent::effetAvant(OpMon &atk, OpMon &def){
		if(part == 0){
			part = 1;
			return 1;
		}else{
			part = 0;
		}

			return 0;

    }

	int CrocDeMort::effetApres(OpMon &atk, OpMon &def){
		if (Utils::randU(10) ==2){
		}
		return 0;
	}
	int CrocFatal::effetAvant(OpMon &atk, OpMon &def){
		if(def.getPV() != 1){
			def.attacked(def.getPV() / 2);
		}else{
			def.attacked(1);
		}
		return 2;
	}

};







