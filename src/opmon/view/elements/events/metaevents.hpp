/*!
 * \file metaevents.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "LinearMetaEvent.hpp"
#include "CharacterEvent.hpp"
#include "BattleEvent.hpp"

namespace OpMon::Elements {
	/*!
	 * \brief An shortcut for an door event.
	 */
	class DoorEvent: public LinearMetaEvent {
	public:
		DoorEvent(OverworldData &data, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, EventTrigger eventTrigger = EventTrigger::GO_IN, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
		void action(Player &player, Overworld &overworld);
		void update(Player &player, Overworld &overworld);
	};

	/*!
	 * \brief A talking NPC.
	 */
	class TalkingCharaEvent: public LinearMetaEvent {
	public:
		TalkingCharaEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Utils::OpString const &dialogKey, Side posDir = Side::TO_UP, EventTrigger eventTrigger = EventTrigger::PRESS, MoveStyle moveStyle = MoveStyle::NO_MOVE, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int side = SIDE_ALL);
		void action(Player &player, Overworld &overworld);
		void update(Player &player, Overworld &overworld);
	};

	/*!
	 * \brief A trainer.
	 *
	 * The TrainerEvent class is a basic meta event (Not a LinearMetaEvent) containing three events : two TalkingCharaEvents and one BattleEvent.
	 * The first TalkingCharaEvent represents the trainer before the battle,
	 * the BattleEvent represents the battle and
	 * the second TalkingCharaEvent represents the trainer after the battle.
	 */
	class TrainerEvent: public AbstractMetaEvent {
	private:
		bool defeated = false;
		bool triggered = false;
	public:
		TrainerEvent(TalkingCharaEvent* prebattlenpc, BattleEvent* battle, TalkingCharaEvent* postbattlenpc);
		void action(Player &player, Overworld &overworld);
		void update(Player &player, Overworld &overworld);
		bool isDefeated() {return defeated;}
	};
}
