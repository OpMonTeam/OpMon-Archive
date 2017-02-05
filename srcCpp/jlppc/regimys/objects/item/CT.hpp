
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_

#include "../../../utils/Class.hpp"
#include "Item.hpp"
#include "../Attaque.hpp"

typedef Class<Attaque*> ClassAtk;

class CT : public Item {
public:
CT(ClassAtk atk, int ctNumber, int ID);
	ClassAtk getAtk() const{return atk;}
private:
	ClassAtk atk;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_ */
