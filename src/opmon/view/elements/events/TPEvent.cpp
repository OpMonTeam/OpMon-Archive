#include "TPEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"

namespace OpMon {
	namespace Elements {

		TPEvent::TPEvent(sf::Texture &texture, std::vector<sf::IntRect> rectangles, EventTrigger eventTrigger,
				sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, Side ppDir,
				int sides, bool passable)
		: AbstractEvent(texture, rectangles, eventTrigger, position, sides, passable)
		, tpCoord(tpPos)
		, map(map)
		, ppDir(ppDir) {
		}

		TPEvent::TPEvent(OverworldData& data, nlohmann::json jsonData)
		: AbstractEvent(data, jsonData)
		, tpCoord(sf::Vector2f(jsonData.at("tp").at("position")[0], jsonData.at("tp").at("position")[1]))
		, map(jsonData.at("tp").at("map"))
		, ppDir(jsonData.at("tp").value("side", Side::NO_MOVE)){
			this->rectangles = std::vector<sf::IntRect>{sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y)};
			this->currentFrame = rectangles.begin();
		}

		void TPEvent::action(Overworld &overworld) {
			command = true;
			overworld.getCharacter().getPositionMapRef().lockMove();
		}

		void TPEvent::update(Overworld &overworld) {
			if(command && !overworld.getCharacter().getPositionMap().isMoving()){
				if(!overworld.getCharacter().getPositionMap().justTP) {
					overworld.tp(map, tpCoord, ppDir);
					overworld.getCharacter().getPositionMapRef().justTP = true;
				}
				command = false;
				//The movement lock will be unlocked in Overworld
			}
		}

	} /* namespace Elements */
} /* namespace OpMon */
