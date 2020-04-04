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
	 *
	 * This class takes two queues of the same size, one of events and the other of booleans.
	 * If the boolean is `true`, the event will be called at the same time as the previous events.
	 * Else, the meta event will wait for the previous events to end before activating the new one.
	 */
	class LinearMetaEvent : public AbstractMetaEvent {
	private:
		/*!
		 * \brief A queue of the same size as eventQueue. One boolean is associated with one event.
		 *
		 * If the boolean is `true`, the event will be called at the same time as the previous events.
		 * Else, the meta event will wait for the previous events to end before activating the new one.
		 */
		std::queue<bool> actionQueue;
	public:
		LinearMetaEvent(std::queue<AbstractEvent*> eventQueue, std::queue<bool> actionQueue);
		void action(Player &player, Overworld &overworld);
		void update(Player &player, Overworld &overworld);
	};
}
