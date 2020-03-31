/*!
 * \file EventBase.cpp
 * \author Author: cyrielle
 * \copyright GNU GPL v3.0
 */

#include "AbstractEvent.hpp"

namespace OpMon {
	namespace Elements {
		BaseEvent::BaseEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, int sides, bool passable)
		: otherTextures(otherTextures)
		, eventTrigger(eventTrigger)
		, position(sf::Vector2f((position.x) * 32, (position.y) * 32))
		, mapPos(position, true)
		, passable(passable)
		, sides(sides)
		, sprite(std::make_unique<sf::Sprite>())
		, currentTexture(otherTextures.begin()) {}

		void Event::updateTexture() {
			this->sprite->setPosition(position);
			this->sprite->setTexture(*currentTexture);
		}
	}
}

