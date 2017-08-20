#include "IOpball.hpp"

I_Opball::I_Opball(std::string &name, float tauxCapture, int ID) : Item(name, false, true, true, BagCat::OBJETS, ID) {
    this->tauxCapture = tauxCapture;
}

