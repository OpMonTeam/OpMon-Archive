#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_

#include <iostream>
#include "../enums/Enums.hpp"
#include "IPokeball.hpp"
#include <vector>
using namespace std;

class Item : public RegimysObject {
public:
	Item(string nom, bool usable, bool usableInFight, bool givable, BagCat categorie, int id);
	static Class<Item>* getStatClass() const {return classe;}
	static void initItems();
	static Item* getItem (string const& name) const ;
	static Item* getItem (int id) const;
	static int searchItem (Item const* toSearch) const;
	bool operator== (Item const& a, Item const& b) const;
	string getNom() const {return nom;}
	bool isUsable() const {return usable;}
	bool isGivable() const {return givable;}
	BagCat getCategorie () const{return categorie;}
	bool isUsableInFight() const{return usableInFight;}
	int getID() const {return id;}
	static int getItemNumber() const{return itemsList.size();}
private:
    string nom;
    bool usable;
    bool givable;
    BagCat categorie;
    bool usableInFight;
    int id;
    static vector<Item*> itemsList = vector<Item>();

	static const Class<Item> *classe = new Class<Item>("Item", 4984631);
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_ */
