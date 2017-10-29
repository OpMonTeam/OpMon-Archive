/*
IOpball.hpp
Author : Jlppc
Fichier sous licence GPL-3.0.
http://opmon-game.ga
Contient la définition de la classe I_Opball
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBALL_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBALL_HPP_

#include <iostream>
#include "Item.hpp"
/**
Définit un item de type Opball
*/
class I_Opball: public Item {
public:
    I_Opball(std::string &name, float tauxCapture, int ID);
    float getTauxCapture() const {
        return tauxCapture;
    }
    int itemTypeID = 2;
private:
    float tauxCapture;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOpball_HPP_ */
