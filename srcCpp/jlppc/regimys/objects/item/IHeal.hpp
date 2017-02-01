
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_

#include "Item.hpp"

class I_Heal: public Item {
public:
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, BagCat categorie, int pvHeal, Status heal, bool healAllStatus, int ID);
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, BagCat categorie, int ppHeal, bool allAttacksHeal, int ID);
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, BagCat categorie, int pvHeal, int ID);
	I_Heal(string nom, bool usable, bool usableInFight, bool givable, BagCat categorie, Status heal, bool healAllStatus, int ID);
	I_Heal(string nom, Stats statAdd, int ID);

private:
	int pvHeal;
	Status healed;
	bool healAll;
	Stats statAdd;
	bool PPheal;//Si l'item soigne des PP
	int ppHeal;//Les PP soignés
	bool allAttacksHeal;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_ */
