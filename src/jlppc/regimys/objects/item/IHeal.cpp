








#include "IHeal.hpp"
#include "../../start/main.hpp"

UNS

I_Heal::I_Heal(string &nom, bool usable, bool usableInFight, bool givable, int categorie, int hpHeal, int heal, bool healAllStatus, int ID) : Item(nom, usable, usableInFight, givable, categorie, ID) {
    this->hpHeal = hpHeal;
    this->healed = heal;
    healAll = healAllStatus;
    statAdd = Stats::NOTHING;
    allAttacksHeal = false;
    ppHeal = 0;
    PPheal = false;
}

I_Heal::I_Heal(string &nom, bool usable, bool usableInFight, bool givable, int categorie, int ppHeal, bool allAttacksHeal, int ID) : Item(nom, usable, usableInFight, givable, categorie, ID) {
    this->hpHeal = 0;
    this->healed = Status::NOTHING;
    healAll = false;
    statAdd = Stats::NOTHING;
    PPheal = true;
    this->ppHeal = ppHeal;
    this->allAttacksHeal = allAttacksHeal;
}

I_Heal::I_Heal(string &nom, bool usable, bool usableInFight, bool givable, int categorie, int hpHeal, int ID) : Item(nom, usable, usableInFight, givable, categorie, ID) {
    this->hpHeal = hpHeal;
    this->healed = Status::NOTHING;
    this->healAll = false;
    statAdd = Stats::NOTHING;
    allAttacksHeal = false;
    ppHeal = 0;
    PPheal = false;
}

I_Heal::I_Heal(string &nom, bool usable, bool usableInFight, bool givable, int categorie, int heal, bool healAllStatus, int ID, bool status) : Item(nom, usable, usableInFight, givable, categorie, ID) {
    this->hpHeal = 0;
    this->healed = heal;
    healAll = healAllStatus;
    statAdd = Stats::NOTHING;
    allAttacksHeal = false;
    ppHeal = 0;
    PPheal = false;
}

I_Heal::I_Heal(string &nom, int statAdd, int ID) : Item(nom, true, true, true, BagCat::SOIN, ID) {
    hpHeal = 0;
    healed = Status::NOTHING;
    healAll = false;
    this->statAdd = statAdd;
    allAttacksHeal = false;
    PPheal = false;
    ppHeal = 0;
}

