#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_

#include <iostream>
#include "../../enums/Enums.hpp"
#include "../../../utils/Class.hpp"
#include <vector>
using namespace std;

namespace ItemType{
    const int IHeal = 1, IPokeball = 2, ICT = 3;
}
class Item{
public:
	Item(string nom, bool usable, bool usableInFight, bool givable, int categorie, int id);
	static void initItems();
	static  Item* getItem (string const& name);
	static  Item* getItem (int id);
	static int searchItem (Item *toSearch);
	bool operator==(Item const& b) const;
	string getNom() const {return nom;}
	bool isUsable() const {return usable;}
	bool isGivable() const {return givable;}
	int getCategorie () const{return categorie;}
	bool isUsableInFight() const{return usableInFight;}
	int getID() const {return id;}
	static int getItemNumber() {return sizeof(itemsList;}
	virtual int getItemTypeID(){return itemTypeID;}
    static Item* itemsList[200];

private:
    int itemTypeID = 0;
    string nom;
    bool usable;
    bool givable;
    int categorie;
    bool usableInFight;
    int id;

};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_ */
