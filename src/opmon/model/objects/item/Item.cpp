/*
Item.cpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#include "Item.hpp"
#include "../../../../utils/defines.hpp"
#include "IHeal.hpp"
#include "IOpBox.hpp"

namespace OpMon {
    namespace Model {

        Item *Item::itemsLst[ITEM_NUMBER] = {0};

        void initItems() {
            //TODO
        }

        Item::Item(std::string name, bool usable, bool usableInFight, bool givable, BagCat categorie, int id)
          : name(name) {
            this->usable = usable;
            this->usableInFight = usableInFight;
            this->id = id;
            this->givable = givable;
            this->categorie = categorie;
        }

        Item *Item::getItem(std::string const &name) {
            for(unsigned int i = 0; i < ITEM_NUMBER; i++) {
                if(itemsLst[i] != nullptr) {
                    if(itemsLst[i]->getName() == name) {
                        return itemsLst[i];
                    }
                }
            }
            return itemsLst[0]; //Default
        }

        Item *Item::getItem(int id2) {
            unsigned int id = ((id2 >= 0 && id2 < ITEM_NUMBER) ? id2 : 0);
            if(itemsLst[id] != nullptr) {
                return itemsLst[id];
            } else {
                return itemsLst[0];
            }
        }

        int Item::searchItem(Item *toSearch) {
            for(unsigned int i = 0; i < ITEM_NUMBER; i++) {
                if(toSearch == itemsLst[i]) {
                    return i;
                }
            }
            return -1;
        }

        bool Item::operator==(Item const &b) const {
            return (categorie == b.categorie) && (givable == b.givable) && (name == b.name) && (usable == b.usable) && (usableInFight == b.usableInFight) && (id == b.id);
        }

    } // namespace Model
} // namespace OpMon
