#include "AbstractEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"

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

		void AbstractEvent::updateTexture() {
			this->sprite->setPosition(position);
			this->sprite->setTexture(*currentTexture);
		}
	}
}

