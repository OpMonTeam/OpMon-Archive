
#include "IPokeball.hpp"

I_Pokeball::I_Pokeball(string nom, float tauxCapture, int ID) : Item(nom, false, true, true, BagCat::OBJETS, ID){
	this->tauxCapture = tauxCapture;
}

