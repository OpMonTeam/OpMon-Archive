#include "IOpBox.hpp"

namespace OpMon {
    namespace Model {

        I_OpBox::I_OpBox(std::string &name, float tauxCapture, int ID)
          : Item(name, false, true, true, BagCat::OBJECTS, ID) {
            this->tauxCapture = tauxCapture;
        }

    } // namespace Model
} // namespace OpMon
