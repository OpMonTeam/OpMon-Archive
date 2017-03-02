/*
IOpball.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0.
http://regimys.tk
Contient la définition de la classe I_Opball
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBALL_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBALL_HPP_

#include <iostream>
#include "Item.hpp"
/**
Définit un item de type Pokeball
*/
class I_Pokeball: public Item {
	public:
		I_Pokeball(std::string nom, float tauxCapture, int ID);
		float getTauxCapture() const {return tauxCapture;}
		int itemTypeID = 2;
	private:
		float tauxCapture;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IPOKEBALL_HPP_ */
