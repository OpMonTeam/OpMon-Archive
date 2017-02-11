
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_

#include "../../../utils/Class.hpp"
#include "Item.hpp"
#include "../Attaque.hpp"

class CT : public Item {
public:
	CT(Class<Attaque*> atk, int ctNumber, int ID);
	Class<Attaque*> getAtk() const{return atk;}
	int itemTypeID = 3;
private:
	Class<Attaque*> atk;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_ */
