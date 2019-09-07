/*
EItem.cpp
Author : Cyrielle
File under GNU GPL v3.0
*/
#include <utility>

#include "evolutions.hpp"

namespace OpMon::Model::Evolutions {
    E_Item::E_Item(int evo, std::string itemId)
      : Evolution(evo)
      , itemID(std::move(itemId)) {
    }

    bool E_Item::checkEvolve(OpMon const &toCheck) const {
        //Temporary
        return false;
    }
} // namespace OpMon::Model::Evolutions
