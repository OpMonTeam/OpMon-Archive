
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_

#include "Item.hpp"

template<typename Attke>

class CT: public Item {
public:
	CT(Class<Attke> atk, int ctNumber);
	Class<Attke> getAtk() const{return atk;}
private:
	Class<Attke> atk;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_ */
