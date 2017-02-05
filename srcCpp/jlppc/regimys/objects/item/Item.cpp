
#include "Item.hpp"

Item::Item(string nom, bool usable, bool usableInFight, bool givable, int categorie, int id) {
    this->nom = nom;
    this->usable = usable;
    this->usableInFight = usableInFight;
    this->id = id;
    this->givable = givable;
    this->categorie = categorie;
}

 Item* Item::getItem(string const& name) const {
    for(int i = 0; i < itemsList.size(); i++){
        if(itemsList[i]->getNom() == name){
            return itemsList[i];
        }
    }
    return NULL;
}

 Item* Item::getItem(int id) const {
    if(!(id < 0 || id > itemsList.size())){
        return itemsList[id];
    }else{
        return NULL;
    }
}

 int Item::searchItem(Item const *toSearch) const {
    for(int i = 0; i < itemsList.size();i++){
        if(toSearch == *itemsList.size()){
            return i;
        }
    }
    return -1;
}

bool Item::operator==(Item const& b) const{
    if (categorie != b.categorie) {
			return false;
		}
		if (givable != b.givable) {
			return false;
		}
		if (!(nom == b.nom)) {
			return false;
		}
		if (usable != b.usable) {
			return false;
		}
		if (usableInFight != b.usableInFight) {
			return false;
		}
		if(id != b.id){
            return false;
		}
        return true;
}

void Item::initItems(){
	itemsList = vector<Item*>()
	itemsList.push_back(new const I_Heal("Baie Oran", true, true, true, BagCat::BAIES, 10, Status::AUCUN, false, 0));
	itemsList.push_back(new const I_Heal("Baie Sitrus", true, true, true, BagCat::BAIES, 30, Status::AUCUN, false, 1));
	itemsList.push_back(new const I_Heal("Baie Mepo", true, true, true, BagCat::BAIES, 10, false, 2));
	itemsList.push_back(new const I_Heal("Baie Prine", true, true, true, BagCat::BAIES, 0, Status::POISON, true, 3));
	itemsList.push_back(new const I_Heal("Baie Willia",true, true, true, BagCat::BAIES, 0, Status::GEL, false, 4));
	itemsList.push_back(new const I_Heal("Baie Fraive", true, true, true, BagCat::BAIES, 0, Status::BRULURE, false, 5));
	//Jusqu'a 24 : Baies (Pas de baies de soin conditionnel, pas de baies autres
	itemsList.push_back(new const I_Heal("Défense +", Stats::DEF, 25));
	//Jusqu'a 31 : Stats+ sauf Muscle +
	itemsList.push_back(new const Item("Améliorator", false, false, true, BagCat::OBJETS, 32));
	//Jusqu'a 42 : Objets evolution / echange a tenir
	itemsList.push_back(new const Item("Pierre Eclat", true, false, true, BagCat::OBJETS, 43));
	//Jusqu'a 51 : Pierres evolutives
	itemsList.push_back(new const Item("Petit Champi", false, false, true, BagCat::OBJETS, 52));
	//Jusqu'a 71 : Items a vendre
	//itemsList.push_back(new const) Items d'amélioration d'EV. Classe a ajouter.
	//Jusqu'a 82 : Items d'amélioration d'EV (Sauf : Aile Sprint, Pilule Talent, Aile Mental, Aile Esprit, Aile Santé)
	itemsList.push_back(new const I_Heal("Soda Cool", true, true, true, BagCat::SOIN, 60, 83));
	//Jusqu'a 95 : Items de soin PV
	itemsList.push_back(new const I_Heal("Huile", true, true, true, BagCat::SOIN, 10, false, 96));
	//Jusqu'a 99 : Items de soin de PP
	//itemsList.push_back(new const I_Heal("Rappel", TODO)) Items de Rappel a faire
	//Jusqu'a 103 : Items de Rappel
	itemsList.push_back(new const I_Heal("Galette Illumis", true, true, true, BagCat::SOIN, 0, Status::POISON, true, 104));
	//Jusqu'a 114 : Items de Soin de Status
	itemsList.push_back(new const I_Pokeball("Poké Ball", 1, 115));
	//Jusqu'a 124 : Balls classiques (+ Memoire Ball + Honor ball + Reve ball)
	//itemsList.push_back(new const...) TODO pokeballs spéciales
	//Jusqu'a 133 : Balls spéciales
	//Ensuite items TODO : Jusqu'a 136 : Repousses
	//137 : Corde Sortie
	//Jusqu'a 140 : Objets permettant de s'enfuir poké  sauvage
	//Enfin, tout ce qui est Item a tenir.
	itemsList.push_back(new const Item("Croc Rasoir", false, false, true, BagCat::OBJETS, 3));
	//Jusqu'a
}
