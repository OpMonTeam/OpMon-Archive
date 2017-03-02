
#include "IOpball.hpp"

I_Opball::I_Opball(std::string nom, float tauxCapture, int ID) : Item(nom, false, true, true, BagCat::OBJETS, ID) {
	this->tauxCapture = tauxCapture;
}

