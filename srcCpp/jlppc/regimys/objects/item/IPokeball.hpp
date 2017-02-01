
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IPOKEBALL_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IPOKEBALL_HPP_

#include "includeAll.hxx"

class I_Pokeball: public Item {
public:
	I_Pokeball(string nom, float tauxCapture, int ID);
	float getTauxCapture() const{return tauxCapture;}
private:
	float tauxCapture;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IPOKEBALL_HPP_ */
