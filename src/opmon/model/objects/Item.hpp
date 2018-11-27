/**
Item.hpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#pragma once

#include "OpMon.hpp"
#include "../../../utils/OpString.hpp"
#include "../../start/Core.hpp"
#include <vector>

#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace OpMon{
  namespace Model{

    struct Turn;

    typedef struct Turn Turn;

    class Player;
    
    class ItemEffect {
    public:
      ItemEffect() {handleError("Trying to instanciate an empty ItemEffect. Why ?", true);}
      
      /** Different effects. The boolean returned is true if the item must be consumed */
      
      /** Effect when used on an OpMon */
      bool operator()(OpMon *opmon){ return false; }
      /** Effect when used on the field */
      bool operator()(Player* player){ return false; }
      /** Effect when held during a turn */
      bool operator()(Turn& owner, Turn& opponent){ return false; }
      /** Dialog used when the object is used on an OpMon or on the field */
      std::vector<sf::String> getDialog() { return dialog; }
      
    protected:

      std::vector<sf::String> dialog;
      
    };
    
    class Item {
    public:
      Item(Utils::OpString name, bool usable, bool onOpMon, ItemEffect* opmonEffect = nullptr, ItemEffect* playerEffect = nullptr, ItemEffect* heldEffect = nullptr);

      std::vector<sf::String> use(OpMon* opmon, int& itemCount);
      std::vector<sf::String> use(Player* player, int& itemCount);
      void updateHeld(Turn& owner, Turn& opponent, int& itemCount);
      
    protected:
      Utils::OpString name;
      bool usable;
      bool onOpMon;
      ItemEffect* opmonEffect;
      ItemEffect* playerEffect;
      ItemEffect* heldEffect;
    };

    namespace Items {
      
    }
    
  }
}

#pragma GCC diagnostic pop
