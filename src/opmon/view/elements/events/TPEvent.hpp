/*!
 * \file TPEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractEvent.hpp"

namespace OpMon {
	namespace Elements {
		class TPEvent : public AbstractEvent {
		private:
			int frames = -1;
			/*!
			 * \brief The coordinates of where the event will teleport the player.
			 */
			sf::Vector2i tpCoord;
			/*!
			 * \brief The id of he map where the event will teleport the player.
			 */
			std::string map;
			/*!
			 * \brief The direction in which the character will be looking after the teleportation.
			 */
			Side ppDir;

		public:
			TPEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
			virtual void update(Player &player, Overworld &overworld);
			virtual void action(Player &player, Overworld &overworld);
			bool isOver() {return true;}
		};
	}
}
