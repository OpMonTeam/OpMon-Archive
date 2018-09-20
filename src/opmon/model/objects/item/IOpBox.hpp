/*
IOpBox.hpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBOX_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBOX_HPP_

#include "Item.hpp"
#include <iostream>

namespace OpMon {
    namespace Model {

        /**
       Defines OpBox item type
    */
        class I_OpBox : public Item {
          public:
            I_OpBox(std::string &name, float captureRate, int ID);
            float getCaptureRate() const {
                return captureRate;
            }
            int itemTypeID = 2;

          private:
            float captureRate;
        };

    } // namespace Model
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IOPBOX_HPP_ */
