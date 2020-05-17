#include "AbstractEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"
#include "src/utils/log.hpp"
#include "src/utils/misc.hpp"

namespace OpMon {
	namespace Elements {
		AbstractEvent::AbstractEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, int sides, bool passable)
		: otherTextures(otherTextures)
		, eventTrigger(eventTrigger)
		, position(32.0f * position)
		, mapPos(position, true)
		, passable(passable)
		, sides(sides)
		, sprite(new sf::Sprite())
		, currentTexture(otherTextures.begin()) {

		}

		AbstractEvent::AbstractEvent(OverworldData &data, nlohmann::json jsonData)
		: otherTextures(data.getEventsTexture(jsonData.at("textures")))
		, eventTrigger(jsonData.value("trigger", EventTrigger::PRESS))
		, position(32.0f * sf::Vector2f(jsonData.value("position", std::vector<int>{0,0})[0], jsonData.value("position", std::vector<int>{0,0})[1]))
		, mapPos((1.0f / 32.0f) * position, true)
		, passable(jsonData.value("passable", true))
		, sides(jsonData.value("side", SIDE_ALL))
		, sprite(new sf::Sprite())
		, currentTexture(otherTextures.begin()) {
		}

		void AbstractEvent::updateTexture() {
			this->sprite->setPosition(position);
			this->sprite->setTexture(*currentTexture);
		}

		void AbstractEvent::setPosition(sf::Vector2i pos) {
			position = 32.0f * sf::Vector2f(pos.x, pos.y);
			mapPos.setPosition(pos.x, pos.y);
			sprite->setPosition(position);
		}
	}
}

