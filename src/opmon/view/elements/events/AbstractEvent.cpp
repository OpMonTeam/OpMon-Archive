#include "AbstractEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"
#include "src/utils/log.hpp"

namespace OpMon {
	namespace Elements {
		AbstractEvent::AbstractEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, int sides, bool passable)
		: otherTextures(otherTextures)
		, eventTrigger(eventTrigger)
		, position(sf::Vector2f((position.x) * 32, (position.y) * 32))
		, mapPos(position, true)
		, passable(passable)
		, sides(sides)
		, sprite(std::make_unique<sf::Sprite>())
		, currentTexture(otherTextures.begin()) {}

		AbstractEvent::AbstractEvent(OverworldData &data, nlohmann::json jsonData)
		: otherTextures(data.getEventsTexture(jsonData.at("textures")))
		, eventTrigger(jsonData.value("trigger", EventTrigger::PRESS))
		, position(sf::Vector2f(jsonData.value("position", std::vector<int>{0,0})[0], jsonData.value("position", std::vector<int>{0,0})[1]))
		, mapPos(position, true)
		, passable(jsonData.value("passable", false))
		, sides(jsonData.value("side", SIDE_ALL))
		, sprite(std::make_unique<sf::Sprite>())
		, currentTexture(otherTextures.begin()) {
		}

		void AbstractEvent::updateTexture() {
			this->sprite->setPosition(position);
			this->sprite->setTexture(*currentTexture);
		}
	}
}

