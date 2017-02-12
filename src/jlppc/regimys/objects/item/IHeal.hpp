/*
IHeal.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la définition de la classe I_Heal
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_

#include "Item.hpp"
#include <iostream>


/**
Définit un item de soin
*/
class I_Heal: public Item {
public:
	I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int heal, bool healAllStatus, int ID);
	I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int ppHeal, bool allAttacksHeal, int ID);
	I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int ID);
	I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int heal, bool healAllStatus, int ID, bool status);//De toutes facons meme si status est false ce sera quand meme du status lol
	I_Heal(std::string nom, int statAdd, int ID);
	bool isHealAll() const{return healAll;}
	bool getPvHeal() const{return pvHeal;}
	int getStatusHeald() const{return healed;}//oui je sais Heald ca ne se dit pas. Enfin je crois.
	int itemTypeID = 1;
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
