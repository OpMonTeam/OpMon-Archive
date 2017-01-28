#include "Pokemon.hpp"

float CalcCourbes::p(int x) {
	switch (x) {
	case 0:
		return 0;
	case 1:
		return 0.008;
	case 2:
		return 0.014;
	default:
		return 0.008;
	}
}

int CalcCourbes::erratique(int n) {
	if (0 < n && n <= 50) {
		return round(pow(n, 3) * ((100 - n) / 50));
	} else if (51 <= n && n <= 68) {
		return round(pow(n, 3) * ((150 - n) / 50));
	} else if (69 <= n && n <= 98) {
		return round(1.274f - ((1 / 50) * (n / 3)) - p(n % 3));
	} else if (n >= 99) {
		return round(pow(n, 3) * ((160 - n) / 100));
	} else {
		Main::gererErreur("Erreur dans le calcul d'experience : niveau <= 0",
				true);
	}
}

int CalcCourbes::fluctuante(int n) {
	if (0 < n && n <= 15) {
		return round(pow(n, 3) * ((24 + ((n + 1) / 3) / 50)));
	} else if (16 <= n && n <= 35) {
		return round(pow(n, 3) * ((14 + n) / 50));
	} else if (n >= 36) {
		return round(pow(n, 3) * ((32 + (n / 2)) / 50));
	} else {
		Main::gererErreur("Erreur dans le calcul d'experience : niveau <= 0",
				true);
	}
}

int CalcCourbes::lente(int n) {
	return round(1.25f * pow(n, 3));
}

int CalcCourbes::moyenne(int n) {
	return round(pow(n, 3));
}
int CalcCourbes::parabolique(int n) {
	return round(1.2f * pow(n, 3) - 15 * pow(n, 2) + (100 * n) - 140);
}
int CalcCourbes::rapide(int n) {
	return round(0.8f * pow(n, 3));
}
Pokemon::Pokemon(string surnom, Espece espece, int level, Attaque attaques[],
		Caractere caractere) {
	statATK = round(
			((((2 * espece.getBaseAtk() + atkIV + (atkEV / 4)) * level) / 100)
					+ 5)
					* ((caractere.bonus == Stats.ATK) ?
							1.1 : ((caractere.malus == Stats.ATK) ? 0.9 : 1)));
	statDEF = round(
			((((2 * espece.getBaseDef() + defIV + (defEV / 4)) * level) / 100)
					+ 5)
					* ((caractere.bonus == Stats.DEF) ?
							1.1 : ((caractere.malus == Stats.DEF) ? 0.9 : 1)));
	statATKSPE =
			round(
					((((2 * espece.getBaseAtkSpe() + atkSpeIV + (atkSpeEV / 4))
							* level) / 100) + 5)
							* ((caractere.bonus == Stats.ATKSPE) ?
									1.1 :
									((caractere.malus == Stats.ATKSPE) ? 0.9 : 1)));
	statDEFSPE =
			round(
					((((2 * espece.getBaseDefSpe() + defSpeIV + (defSpeEV / 4))
							* level) / 100) + 5)
							* ((caractere.bonus == Stats.DEFSPE) ?
									1.1 :
									((caractere.malus == Stats.DEFSPE) ? 0.9 : 1)));
	statVIT = round(
			((((2 * espece.getBaseVit() + vitIV + (vitEV / 4)) * level) / 100)
					+ 5)
					* ((caractere.bonus == Stats.VIT) ?
							1.1 : ((caractere.malus == Stats.VIT) ? 0.9 : 1)));
	statPV = round(((2 * espece.getBasePV() + pvIV + (pvEV / 4)) * level) / 100)
			+ level + 10;
	this->espece = espece;
	this->level = level;
	//TODO attaquesChoix Quand les attaques seront ok
	this->caractere = caractere;
	this->surnom = surnom;
	tauxCapture = espece.getTauxDeCapture();
	PV = statPV;
	type1 = espece.getType1();
	type2 = espece.getType2();
	using namespace CalcCourbes;
	switch (this->espece.getCourbe()) {
	case CourbeExp::ERRATIQUE:
		toNextLevel = erratique(this->level + 1);
		exp = erratique(this->level);
		break;
	case CourbeExp::FLUCTUANTE:
		toNextLevel = fluctuante(this->level + 1);
		exp = fluctuante(this->level);
		break;
	case CourbeExp::LENTE:
		toNextLevel = lente(this->level + 1);
		exp = lente(this->level);
		break;
	case CourbeExp::MOYENNE:
		toNextLevel = moyenne(this->level + 1);
		exp = moyenne(this->level);
		break;
	case CourbeExp::PARABOLIQUE:
		toNextLevel = parabolique(this->level + 1);
		exp = parabolique(this->level);
		break;
	case CourbeExp::RAPIDE:
		toNextLevel = rapide(this->level + 1);
		exp = rapide(this->level);
		break;
	}

}

bool Pokemon::captured(I_Pokeball pokeball) {
	Status listeUnCinq[] = { Status.PARALYSIE, Status.POISON, Status.BRULURE };
	Status listeDeux[] = { Status.SOMMEIL, Status.GEL };
	int a =
			round(
					(((3 * statPV - 2 * PV) * tauxCapture
							* pokeball.getTauxCapture()
							* (Comparaisons.muliEgal(status, listeUnCinq, 3) ?
									1.5 :
									(Comparaisons.muliEgal(status, listeDeux,
											2) ? 2 : 1))) / (3 * statPV)));
	int b = round((pow(2, 16) - 1) * pow(a / (pow(2, 8) - 1), 0.25));
	int c[] = { Utils::randU(65535), Utils::randU(65535), Utils::randU(65535),
			Utils::randU(65535) };
	int nbreOk = 0;
	int i = 0;
	for (i = 0; i < 4; i++) {
		if (c[i] <= b) {
			nbreOk++;
		}
	}
	if (nbreOk == 0) {
		return false;
	} else {
		//System.out.println("Remue...");
		if (nbreOk == 1) {
			return false;
		}
		//System.out.println("Remue...");
		if (nbreOk == 2) {
			return false;
		}
		//System.out.println("Remue...");
		if (nbreOk == 3) {
			return false;
		}
		if (nbreOk != 4) {
			Main::gererErreur("InternalError : Pokemon.cpp : nbreOk != 4",
					true);
		}
		return true;
	}
}

void Pokemon::setStat(string stat, int newStat) {
	if (stat == "atk") {
		statATK = newStat;
	} else if (stat == "def") {
		statDEF = newStat;
	} else if (stat == "atkspe") {
		statATKSPE = newStat;
	} else if (stat == "defspe") {
		statDEFSPE = newStat;
	} else if (stat == "vit") {
		statVIT = newStat;
	} else if (stat == "pv") {
		statPV = newStat;
	} else {

	}
}

void Pokemon::levelUp() {
	using namespace CalcCourbes;
	level++;
	switch (this->espece.getCourbe()) {
	case CourbeExp::ERRATIQUE:
		toNextLevel = erratique(this->level + 1);
		exp = erratique(this->level);
		break;
	case CourbeExp::FLUCTUANTE:
		toNextLevel = fluctuante(this->level + 1);
		exp = fluctuante(this->level);
		break;
	case CourbeExp::LENTE:
		toNextLevel = lente(this->level + 1);
		exp = lente(this->level);
		break;
	case CourbeExp::MOYENNE:
		toNextLevel = moyenne(this->level + 1);
		exp = moyenne(this->level);
		break;
	case CourbeExp::PARABOLIQUE:
		toNextLevel = parabolique(this->level + 1);
		exp = parabolique(this->level);
		break;
	case CourbeExp::RAPIDE:
		toNextLevel = rapide(this->level + 1);
		exp = rapide(this->level);
		break;
	}
	calcStats();
	if (espece.getEvolType().checkEvolve(this)) {
		if (*(espece.getEvolType().getClass()) == *(E_Trade::classe)) {
			evolve();
		}
	}
}

int Pokemon::win(Pokemon vaincu) {
	getEvs(vaincu);
	exp += ((vaincu.espece.getExp() * vaincu.level) / this->level) * expBoost;
	while (exp >= toNextLevel && level < 100) {
		if (exp < toNextLevel) {
			break;
		}
		levelUp();
	}
	calcStats();
	return (((vaincu.espece.getExp() * vaincu.level) / this->level) * expBoost);
}

void Pokemon::getEvs(Pokemon vaincu) {
	if (!((atkEV + defEV + pvEV + atkSpeEV + defSpeEV + vitEV) > 510)) {
		Stats *statsVaincu[];
		vaincu.espece.getEv(statsVaincu);
		for (int i = 0; i < sizeof *statsVaincu; i++) {
			switch (*statsVaincu[i]) { //Creer enumération Stats
			case Stats::ATK:
				if (atkEV < 252) {
					atkEV++;
				}
				break;
			case Stats::ATKSPE:
				if (atkSpeEV < 252) {
					atkSpeEV++;
				}
				break;
			case Stats::DEF:
				if (defEV < 252) {
					atkEV++;
				}
				break;
			case Stats::DEFSPE:
				if (defSpeEV < 252) {
					defSpeEV++;
				}
				break;
			case Stats::PV:
				if (pvEV < 252) {
					pvEV++;
				}
				break;
			case Stats::RIEN:
				break;
			case Stats::VIT:
				if (vitEV < 252) {
					vitEV++;
				}
				break;

			}
		}

	}
}


