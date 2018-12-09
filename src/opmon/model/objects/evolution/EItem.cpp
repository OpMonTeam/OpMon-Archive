/*
EItem.cpp
Author : Cyrion
File under GNU GPL v3.0
*/
#include "evolutions.hpp"
#pragma GCC diagnostic ignored "-Wunused-parameter"
namespace OpMon {
    namespace Model {

        namespace Evolutions {
	  E_Item::E_Item(int evo, std::string const& itemId)
              : Evolution(evo)
              , itemID(itemId) {
            }
            
	  bool E_Item::checkEvolve(OpMon const &toCheck) const {
	    //Temporary
	    return false;
	  }
        } // namespace Evolutions

    } // namespace Model
} // namespace OpMon
#pragma GCC diagnostic pop
