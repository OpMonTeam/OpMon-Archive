#include "Item.hpp"
#include "Turn.hpp"
#include "../sysObjects/Player.hpp"
#include "../../../utils/StringKeys.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace OpMon {
  namespace Model {

    Item::Item(Utils::OpString name, bool usable, bool onOpMon, std::unique_ptr<ItemEffect> opmonEffect, std::unique_ptr<ItemEffect> playerEffect, std::unique_ptr<ItemEffect> heldEffect)
      : name(name),
	usable(usable),
	onOpMon(onOpMon),
	opmonEffect(std::move(opmonEffect)),
	playerEffect(std::move(playerEffect)),
	heldEffect(std::move(heldEffect))
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

    namespace Items {
      HpHealEffect::HpHealEffect(int hpHealed)
	: hpHealed(hpHealed){
	
      }

      bool HpHealEffect::operator()(OpMon* opmon){
	bool toReturn = true;
	if(opmon->getHP() == opmon->getStatHP()){
	  dialog.push_back(Utils::OpString::quickString("items.heal.fullHP", {opmon->getNickname()}));
	  toReturn = false;
	}else if(opmon->getHP() <= 0){
	  dialog.push_back(Utils::OpString::quickString("items.heal.healKO", {opmon->getNickname()}));
	  toReturn = false;
	}else{
	  int oldHP = opmon->getHP();
	  opmon->heal(hpHealed);
	  int healed = opmon->getHP() - oldHP;
	  dialog.push_back(Utils::OpString::quickString("items.heal.healHP", {opmon->getNickname(), std::to_string(healed)}));
	  
	}

	dialog.push_back(Utils::OpString::quickString("void"));
	dialog.push_back(Utils::OpString::quickString("void"));

	return toReturn;
	
      }
    }
    
  }
}

#pragma GCC diagnostic pop
