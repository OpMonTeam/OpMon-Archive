#include "BattleEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"

namespace OpMon {
	namespace Elements {

		BattleEvent::BattleEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, OpTeam *team, EventTrigger eventTrigger, bool passable, int side)
		: AbstractEvent(textures, eventTrigger, position, side, passable)
		, team(team){
		}

		void BattleEvent::action(Player &player, Overworld &overworld) {
			if(over) overworld.declareBattle(this);
		}

		void BattleEvent::update(Player &player, Overworld &overworld) {
		}

		BattleEvent::~BattleEvent(){
			delete(team);
		}

	} /* namespace Elements */
} /* namespace OpMon */
