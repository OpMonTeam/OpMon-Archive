
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_

#include "Item.hpp"
#include <iostream>

using namespace std;

class I_Heal: public Item {
public:
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int heal, bool healAllStatus, int ID);
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int ppHeal, bool allAttacksHeal, int ID);
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int ID);
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, int categorie, int heal, bool healAllStatus, int ID, bool status);//De toutes facons meme si status est false ce sera quand meme du status lol
	I_Heal(string nom, int statAdd, int ID);
	bool isHealAll() const{return healAll;}
	bool getPvHeal() const{return pvHeal;}
	int getStatusHeald() const{return healed;}
	static Class<I_Heal> classe;
private:
	int pvHeal;
	int healed;
	bool healAll;
	int statAdd;
	bool PPheal;//Si l'item soigne des PP
	int ppHeal;//Les PP soignés
	bool allAttacksHeal;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_ */
