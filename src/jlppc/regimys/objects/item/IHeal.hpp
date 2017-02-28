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
	    /**Construit un item de heal (presque) polyvalent*/
		I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int heal, bool healAllStatus, int ID);
		/**Construit un item de heal de PP*/
		I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int ppHeal, bool allAttacksHeal, int ID);
		/**Construit un item de heal de pv*/
		I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int pvHeal, int ID);
		/**Construit un item de heal de status*/
		I_Heal(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int heal, bool healAllStatus, int ID, bool status);//De toutes facons meme si status est false ce sera quand meme du status lol
		/**Construit un stat+*/
		I_Heal(std::string nom, int statAdd, int ID);
		bool isHealAll() const {return healAll;}
		bool getPvHeal() const {return pvHeal;}
		int getStatusHeald() const {return healed;}
		int itemTypeID = 1;
	private:
		int pvHeal;
		/**Le status soigné*/
		//->WaitEnum->Status
        int healed;
		/**Si l'item soigne tous les status*/
		bool healAll;
		int statAdd;
		/**Si l'item soigne des PP*/
		bool PPheal;
		/**Les PP soignés*/
		int ppHeal;

		bool allAttacksHeal;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_ */
