#include "OverworldCtrl.hpp"

#include "../model/storage/Data.hpp"
#include "EventsCtrl.hpp"

namespace OpMon{
	namespace Controller{
		GameStatus OverworldCtrl::checkEvents(sf::Event const& events, View::Overworld& overworld, Model::Player& player){
			bool is_dialog_open = overworld.getDialog() && !overworld.getDialog()->isDialogOver();

			switch(events.type) {
				case sf::Event::KeyPressed:
					if(events.key.code == sf::Keyboard::Equal) {
						debugMode = !debugMode;
					}
					if(debugMode) {
						if(events.key.code == sf::Keyboard::F10) {
							overworld.printlayer[0] = !overworld.printlayer[0];
						}
						if(events.key.code == sf::Keyboard::F11) {
							overworld.printlayer[1] = !overworld.printlayer[1];
						}
						if(events.key.code == sf::Keyboard::F12) {
							overworld.printlayer[2] = !overworld.printlayer[2];
						}
					}
				default:
					break;
			}
			if(debugMode) {
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
					overworld.moveCamera(Model::Side::TO_DOWN);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
					overworld.moveCamera(Model::Side::TO_LEFT);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
					overworld.moveCamera(Model::Side::TO_UP);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
					overworld.moveCamera(Model::Side::TO_DOWN);
				}
			}

			if(is_dialog_open){
				return checkEventsDialog(events, overworld);
			}else{
				return checkEventsNoDialog(events, player);
			}

		}


		GameStatus OverworldCtrl::checkEventsDialog(sf::Event const& events, View::Overworld& overworld){
			switch(events.type) {
				case sf::Event::KeyPressed:
					if(events.key.code == sf::Keyboard::Space) {
						overworld.getDialog()->pass();
					}
					break;
				default:
					break;
			}
			return GameStatus::CONTINUE;
		}

		GameStatus OverworldCtrl::checkEventsNoDialog(sf::Event const& event, Model::Player& player){
			EventsCtrl::updateEvents(Model::Data::World::maps.at(player.getMapId())->getEvents(), player);
			EventsCtrl::checkAction(event, player);
			return GameStatus::CONTINUE;
		}
	}
}
