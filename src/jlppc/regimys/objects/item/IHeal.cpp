
#include "IHeal.hpp"
#include "../../start/main.hpp"

UNS

I_Heal::I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int heal, bool healAllStatus, int ID) : Item(nom, usable, usableInFight, givable, categorie, ID) {
	this->pvHeal = pvHeal;
	this->healed = heal;
	healAll = healAllStatus;
	statAdd = Stats::RIEN;
	allAttacksHeal = false;
	ppHeal = 0;
	PPheal = false;
}

I_Heal::I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int ppHeal, bool allAttacksHeal, int ID) : Item(nom, usable, usableInFight, givable, categorie, ID) {
	this->pvHeal = 0;
	this->healed = Status::AUCUN;
	healAll = false;
	statAdd = Stats::RIEN;
	PPheal = true;
	this->ppHeal = ppHeal;
	this->allAttacksHeal = allAttacksHeal;
}

I_Heal::I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int ID) : Item(nom, usable, usableInFight, givable, categorie, ID) {
	this->pvHeal = pvHeal;
	this->healed = Status::AUCUN;
	this->healAll = false;
	statAdd = Stats::RIEN;
	allAttacksHeal = false;
	ppHeal = 0;
	PPheal = false;
}

I_Heal::I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int heal, bool healAllStatus, int ID, bool status) : Item(nom, usable, usableInFight, givable, categorie, ID) {
	this->pvHeal = 0;
	this->healed = heal;
	healAll = healAllStatus;
	statAdd = Stats::RIEN;
	allAttacksHeal = false;
	ppHeal = 0;
	PPheal = false;
}

I_Heal::I_Heal(string nom, int statAdd, int ID) : Item(nom, true, true, true, BagCat::SOIN, ID) {
	pvHeal = 0;
	healed = Status::AUCUN;
	healAll = false;
	this->statAdd = statAdd;
	allAttacksHeal = false;
	PPheal = false;
	ppHeal = 0;
}

