
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_

#include "Item.hpp"


class CT : public Item {
public:
CT(Class<Attaque*> atk, int ctNumber, int ID);
	Class<Attaque*> getAtk() const{return atk;}
private:
	Class<Attaque*> atk;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_ */
