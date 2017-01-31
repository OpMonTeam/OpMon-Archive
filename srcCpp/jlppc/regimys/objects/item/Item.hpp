#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_

#include <iostream>
#include "../enums/Enums.hpp"
#include <vector>
using namespace std;

class Item: public RegimysObject {
public:
	Item(string nom, bool usable, bool usableInFight, bool givable, BagCat categorie, int id);
	static Class<Item>* getStatClass(){return classe;}
	static void initItems();
	static Item* getItem(string name);
	static Item* getItem(int id);
	static int searchItem(Item* const& toSearch);
	bool operator==(Item const& a, Item const& b);
	string getNom(){return nom;}
	bool isUsable(){return usable;}
	bool isGivable(){return givable;}
	BagCat getCategorie(){return categorie;}
	bool isUsableInFight(){return usableInFight;}
	int getID(){return id;}
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
