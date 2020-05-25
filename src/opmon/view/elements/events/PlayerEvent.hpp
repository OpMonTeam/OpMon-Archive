/*!
 * \file PlayerEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "CharacterEvent.hpp"

namespace OpMon::Elements {
	class PlayerEvent : public CharacterEvent {
	private:
		Player *player;

	public:
		PlayerEvent(OverworldData &data);

		Player* getPlayer() {return player;}
	};
}
