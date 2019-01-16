/*
IOpBox.cpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#include "IOpBox.hpp"

namespace OpMon {
    namespace Model {

        I_OpBox::I_OpBox(std::string &name, float captureRate, int ID)
          : Item(name, false, true, true, BagCat::OBJECTS, ID) {
            this->captureRate = captureRate;
        }

    } // namespace Model
} // namespace OpMon
