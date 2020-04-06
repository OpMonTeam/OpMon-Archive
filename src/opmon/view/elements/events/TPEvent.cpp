#include "TPEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"

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

		TPEvent::TPEvent(OverworldData& data, nlohmann::json jsonData)
		: AbstractEvent(data.getEventsTexture(jsonData.value("textures", "alpha")), jsonData)
		, tpCoord(sf::Vector2f(jsonData.at("tp").at("position")[0], jsonData.at("tp").at("position")[1]))
		, map(jsonData.at("tp").at("map"))
		, ppDir(jsonData.at("tp").value("side", Side::NO_MOVE)){

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
