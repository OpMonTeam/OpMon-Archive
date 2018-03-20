/*
  IOpBox.hpp
  Author : Jlppc
  File under the licence GPL-3.0.
  http://opmon-game.ga
  Contains the I_OpBox class definition
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBOX_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBOX_HPP_

#include "Item.hpp"
#include <iostream>

namespace OpMon {
    namespace Model {

        /**
       Défine OpBox item type
    */
        class I_OpBox : public Item {
          public:
            I_OpBox(std::string &name, float tauxCapture, int ID);
            float getTauxCapture() const {
                return tauxCapture;
            }
            int itemTypeID = 2;

          private:
            float tauxCapture;
        };

    } // namespace Model
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBOX_HPP_ */
