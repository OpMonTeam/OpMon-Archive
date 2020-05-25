/*!
 * \file TPEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractEvent.hpp"

namespace OpMon {
	namespace Elements {
		/*!
		 * \brief An event that teleports the player.
		 * \ingroup Events
		 *
		 * This event, when triggered, waits for the player to stop first, and then teleports the character.
		 */
		class TPEvent : public AbstractEvent {
		private:
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
			/*!
			 * \brief If the event have been triggered but the player not teleported yet.
			 */
			bool command = false;

		public:
			TPEvent(sf::Texture &texture, std::vector<sf::IntRect> rectangles, EventTrigger eventTrigger, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
			TPEvent(OverworldData& data, nlohmann::json jsonData);
			virtual void update(Player &player, Overworld &overworld);
			virtual void action(Player &player, Overworld &overworld);
			bool isOver() const {return !command;}
		};
	}
}
