/*!
 * \file metaevents.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "LinearMetaEvent.hpp"
#include "CharacterEvent.hpp"
#include "BattleEvent.hpp"
#include "src/opmon/screens/overworld/OverworldData.hpp"

namespace OpMon::Elements {
	/*!
	 * \brief An shortcut for an door event.
	 * \ingroup Events
	 */
	class DoorEvent: public LinearMetaEvent {
	public:
		DoorEvent(OverworldData &data, nlohmann::json jsonData);
		void update(Overworld &overworld);
	};

	/*!
	 * \brief A talking NPC.
	 * \ingroup Events
	 */
	class TalkingCharaEvent: public LinearMetaEvent {
	public:
		TalkingCharaEvent(OverworldData &data, nlohmann::json jsonData);
		void action(Overworld &overworld);
		void update(Overworld &overworld);
	};

	/*!
	 * \brief A trainer.
	 * \ingroup Events
	 *
	 * The TrainerEvent class is a basic meta event (Not a LinearMetaEvent) containing three events : two TalkingCharaEvents and one BattleEvent.
	 * The first TalkingCharaEvent represents the trainer before the battle,
	 * the BattleEvent represents the battle and
	 * the second TalkingCharaEvent represents the trainer after the battle.
	 */
	class TrainerEvent: public AbstractMetaEvent {
	private:
		/*!
		 * \brief If `true`, the trainer has been battled.
		 *
		 * \note In the future, this variable will be true only if the player won against the trainer.
		 */
		bool defeated = false;
		/*!
		 * \brief If `true`, the player has interacted with the event.
		 *
		 * This variable is set to `false` at the end of the battle (if not defeated) or dialog (if defeated).
		 */
		bool triggered = false;

		/*!
		 * \brief Contains the pointers to the pre battle and battle events when the objects are still used somewhere in the code.
		 */
		std::list<AbstractEvent*> garbage;

	public:
		TrainerEvent(TalkingCharaEvent* prebattlenpc, BattleEvent* battle, TalkingCharaEvent* postbattlenpc);
		TrainerEvent(OverworldData &data, nlohmann::json jsonData);
		~TrainerEvent();
		void action(Overworld &overworld);
		void update(Overworld &overworld);
		bool isDefeated() {return defeated;}
	};
}
