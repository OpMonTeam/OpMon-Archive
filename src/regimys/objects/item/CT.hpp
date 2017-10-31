/*
CT.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la définition de la classe CT
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_

#include "Item.hpp"
#include "../Attack.hpp"
/**
Définit un item de type CT
*/
class CT : public Item {
public:
  std::string getAtk() const {
        return atk;
    }
    int itemTypeID = 3;
  CT(std::string atk, int ctNumber, int ID);
private:
    /**Contient la classe de l'attaque de la CT*/
  std::string atk;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_ */
