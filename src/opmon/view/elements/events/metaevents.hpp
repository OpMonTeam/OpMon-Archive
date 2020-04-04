/*!
 * \file metaevents.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "LinearMetaEvent.hpp"

namespace OpMon::Elements {
	class DoorEvent : public LinearMetaEvent {
	public:
		DoorEvent(OverworldData &data, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, EventTrigger eventTrigger = EventTrigger::GO_IN, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
		void action(Player &player, Overworld &overworld);
		void update(Player &player, Overworld &overworld);
	};
}
