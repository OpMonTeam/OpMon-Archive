#include "TPEvent.hpp"

namespace OpMon {
	namespace Elements {

		TPEvent::TPEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger,
				sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, Side ppDir,
				int sides, bool passable)
		: AbstractEvent(otherTextures, eventTrigger, position, sides, passable)
		, tpCoord(tpPos)
		, map(map)
		, ppDir(ppDir) {
		}

		void TPEvent::action(Player &player, Overworld &overworld) {
			if(!player.getPosition().justTP) {
				overworld.tp(map, tpCoord);
				//Sets the player's direction after the teleportation. If this->ppDir == -1, the old player position is kept
				if(this->ppDir != -1) {
					player.getPosition().setDir(this->ppDir);
				}
				player.getPosition().justTP = true;
			}
		}

		void TPEvent::update(Player &player, Overworld &overworld) {
		}

	} /* namespace Elements */
} /* namespace OpMon */
