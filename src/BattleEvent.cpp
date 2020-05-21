#include "BattleEvent.hpp"
#include "Overworld.hpp"

namespace OpMon {
	namespace Elements {

		BattleEvent::BattleEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, OpTeam *team, EventTrigger eventTrigger, bool passable, int side)
		: AbstractEvent(textures, eventTrigger, position, side, passable)
		, team(team){
		}

		BattleEvent::BattleEvent(OverworldData &data, nlohmann::json jsonData)
		: AbstractEvent(data, jsonData)
		, team(data.getTrainer(jsonData.at("trainer"))){

		}

		void BattleEvent::action(Player &player, Overworld &overworld) {
			if(over){
				overworld.declareBattle(this);
				over = false;
			}
		}

		void BattleEvent::update(Player &player, Overworld &overworld) {
		}

		BattleEvent::~BattleEvent(){
			delete(team);
		}

	} /* namespace Elements */
} /* namespace OpMon */
