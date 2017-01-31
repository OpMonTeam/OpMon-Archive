
#include "Item.hpp"

Item::Item(string nom, bool usable, bool usableInFight, bool givable, BagCat categorie, int id) {
    this->nom = nom;
    this->usable = usable;
    this->usableInFight = usableInFight;
    this->id = id;
    this->givable = givable;
    this->categorie = categorie;
}

Item* Item::getItem(string const& name) const {
    for(int i = 0; i < itemsList.size(); i++){
        if(itemsList[i]->getName() == name){
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

int Item::searchItem(Item const& toSearch) const {
    for(int i = 0; i < itemsList.size();i++){
        if(toSearch == *itemsList.size()){
            return i;
        }
    }
    return -1;
}

bool Item::operator==(Item const& a, Item const& b) const{
    if (a.categorie != b.categorie) {
			return false;
		}
		if (a.givable != b.givable) {
			return false;
		}
		if (!(a.nom == b.nom)) {
			return false;
		}
		if (a.usable != b.usable) {
			return false;
		}
		if (a.usableInFight != b.usableInFight) {
			return false;
		}
		if(a.id != b.id){
            return false;
		}
        return true;
}

void Item::initItems(){
}
