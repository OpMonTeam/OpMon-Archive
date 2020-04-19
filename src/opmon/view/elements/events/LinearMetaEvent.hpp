/*!
 * \file LinearMetaEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractMetaEvent.hpp"

namespace OpMon::Elements {
	/*!
	 * \brief A meta event that calls one group of events after the other.
	 * \ingroup Events
	 *
	 * This class takes two queues of the same size, one of events and the other of booleans.
	 * If the boolean is `true`, the event will be called at the same time as the previous events.
	 * Else, the meta event will wait for the previous events to end before activating the new one.
	 *
	 * Since the processing of the queue will loop after processing have been set to `true`,
	 * you can use `nullptr` to pause the loop. It can be used anywhere in the queue to pause it,
	 * or you can use it at the end to stop at the end of the queue. The `nullptr` value will clear \ref processingList
	 * and set \ref processing to `false`. To continue the processing, the player will have to interact again with the event.
	 */
	class LinearMetaEvent : public AbstractMetaEvent {
	protected:

		/*!
		 * \brief A queue of the same size as eventQueue. One boolean is associated with one event.
		 *
		 * If the boolean is `true`, the event will be called at the same time as the previous events.
		 * Else, the meta event will wait for the previous events to end before activating the new one.
		 */
		std::queue<bool> actionQueue;
	public:
		LinearMetaEvent(std::queue<AbstractEvent*> eventQueue, std::queue<bool> actionQueue);
		LinearMetaEvent(OverworldData &data, nlohmann::json jsonData);
		void action(Player &player, Overworld &overworld);
		void update(Player &player, Overworld &overworld);
	};
}
