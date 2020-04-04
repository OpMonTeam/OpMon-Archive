#include "LinearMetaEvent.hpp"

namespace OpMon {
	namespace Elements {

		LinearMetaEvent::LinearMetaEvent(std::queue<AbstractEvent*> eventQueue, std::queue<bool> actionQueue)
		: AbstractMetaEvent(eventQueue)
		, actionQueue(actionQueue){

		}

		void LinearMetaEvent::action(Player &player, Overworld &overworld){
			if(!processing){
				processing = true;
				processingList.clear();
			}
		}

		void LinearMetaEvent::update(Player &player, Overworld &overworld){
			AbstractEvent* firstEvent = eventQueue.front();
			do {
				if(eventQueue.front() != nullptr) eventQueue.front()->update(player, overworld);
				eventQueue.push(eventQueue.front());
				eventQueue.pop();
			} while(firstEvent != eventQueue.front());
			if(processing){
				processingList.remove_if([](AbstractEvent* event){return event->isOver();});
				if(processingList.empty()){
					do {
						if(eventQueue.front() == nullptr){
							processingList.clear();
							processing = false;
							return;
						}
						processingList.push_back(eventQueue.front());
						eventQueue.front()->action(player, overworld);
						eventQueue.push(eventQueue.front());
						eventQueue.pop();
						actionQueue.push(actionQueue.front());
						actionQueue.pop();
					} while(actionQueue.front());
				}
			}
		}

	} /* namespace Elements */
} /* namespace OpMon */
