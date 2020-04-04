#include "BattleEvent.hpp"

namespace OpMon {
	namespace Elements {

		BattleEvent::BattleEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, OpTeam *team, EventTrigger eventTrigger, bool passable, int side)
		: AbstractEvent(textures, eventTrigger, position, side, passable)
		, team(team){
		}

		void BattleEvent::action(Player &player, Overworld &overworld) {
			//overworld.declareBattle(this);
			//TODO : To uncomment.
			over = !overworld.isInBattle();
		}

		void BattleEvent::update(Player &player, Overworld &overworld) {
			over = !overworld.isInBattle();
		}

	} /* namespace Elements */
} /* namespace OpMon */
