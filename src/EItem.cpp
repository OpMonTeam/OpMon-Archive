/*
  EItem.cpp
  Author : Cyrielle
  File under GNU GPL v3.0
*/
#include <string>

#include "OpString.hpp"
#include "evolutions.hpp"
#include "Evolution.hpp"

namespace OpMon {
class OpMon;
}  // namespace OpMon

#pragma GCC diagnostic ignored "-Wunused-parameter"
namespace OpMon {

    namespace Evolutions {
        E_Item::E_Item(int evo, std::string const &itemId)
            : Evolution(evo)
            , itemID(itemId) {
        }

        bool E_Item::checkEvolve(OpMon const &toCheck) const {
            //Temporary
            return false;
        }
    } // namespace Evolutions

} // namespace OpMon
#pragma GCC diagnostic pop
