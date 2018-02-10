/*
CT.hpp
Author : Jlppc
File under the licence GPL-3.0
http://opmon-game.ga
Contains the CT class definition
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_

#include "../Attack.hpp"
#include "Item.hpp"

namespace OpMon {
    namespace Model {
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
    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_ */
