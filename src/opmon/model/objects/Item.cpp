#include "Item.hpp"
#include "Turn.hpp"
#include "../sysObjects/Player.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace OpMon {
  namespace Model {

    Item::Item(Utils::OpString name, bool usable, bool onOpMon, ItemEffect* opmonEffect, ItemEffect* playerEffect, ItemEffect* heldEffect)
      : name(name),
	usable(usable),
	onOpMon(onOpMon),
	opmonEffect(opmonEffect),
	playerEffect(playerEffect),
	heldEffect(heldEffect)
    {}

    std::vector<sf::String> Item::use(OpMon* opmon, int& itemCount){
      bool result = (*opmonEffect)(opmon);
      itemCount = (result ? itemCount - 1 : itemCount);
      return opmonEffect->getDialog();
    }

    std::vector<sf::String> Item::use(Player* player, int& itemCount){
      bool result = (*playerEffect)(player);
      itemCount = (result ? itemCount - 1 : itemCount);
      return playerEffect->getDialog();
    }

    void Item::updateHeld(Turn& owner, Turn& opponent, int& itemCount){
      bool result = (*heldEffect)(owner, opponent);
      itemCount = (result ? itemCount - 1 : itemCount);
    }
    
  }
}

#pragma GCC diagnostic pop
