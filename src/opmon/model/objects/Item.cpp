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

    std::unique_ptr<std::vector<sf::String> > Item::use(OpMon* opmon, int& itemCount){
      if(opmonEffect == nullptr){
	handleError("Calling an unknown item effect !");
	return nullptr;
      }
      bool result = (*opmonEffect)(opmon);
      itemCount = (result ? itemCount - 1 : itemCount);
      return opmonEffect->getDialog();
    }

    std::unique_ptr<std::vector<sf::String> > Item::use(Player* player, int& itemCount){
      if(playerEffect == nullptr){
	handleError("Calling an unknown item effect !");
	return nullptr;
      }
      bool result = (*playerEffect)(player);
      itemCount = (result ? itemCount - 1 : itemCount);
      return playerEffect->getDialog();
    }

    void Item::updateHeld(Turn& owner, Turn& opponent, int& itemCount){
      if(heldEffect == nullptr){
		handleError("Calling an unknown item effect !");
		return;
      }
      bool result = (*heldEffect)(owner, opponent);
      itemCount = (result ? itemCount - 1 : itemCount);
    }

    namespace Items {
      HpHealEffect::HpHealEffect(int hpHealed)
	: hpHealed(hpHealed){
	
      }

      bool HpHealEffect::operator()(OpMon* opmon){
	dialog = std::make_unique<std::vector<sf::String> >();
	bool toReturn = true;
	if(opmon->getHP() == opmon->getStatHP()){
	  dialog->push_back(Utils::OpString::quickString("items.dialog.heal.fullHP", {opmon->getNickname()}));
	  toReturn = false;
	}else if(opmon->getHP() <= 0){
	  dialog->push_back(Utils::OpString::quickString("items.dialog.heal.healKO", {opmon->getNickname()}));
	  toReturn = false;
	}else{
	  int oldHP = opmon->getHP();
	  opmon->heal(hpHealed);
	  int healed = opmon->getHP() - oldHP;
	  dialog->push_back(Utils::OpString::quickString("items.dialog.heal.healHP", {opmon->getNickname(), std::to_string(healed)}));
	  
	}

	dialog->push_back(Utils::OpString::quickString("void"));
	dialog->push_back(Utils::OpString::quickString("void"));

	return toReturn;
	
      }
    }
    
  }
}

#pragma GCC diagnostic pop
