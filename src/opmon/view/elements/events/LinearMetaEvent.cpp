#include "LinearMetaEvent.hpp"

namespace OpMon {
	namespace Elements {

		LinearMetaEvent::LinearMetaEvent(std::queue<AbstractEvent*> eventQueue, std::queue<bool> actionQueue)
		: AbstractMetaEvent(eventQueue)
		, actionQueue(actionQueue){
			if(eventQueue.size() != actionQueue.size()){
				throw Utils::UnexpectedValueException(std::to_string(actionQueue.size()), std::to_string(eventQueue.size()) + ", the size of eventQueue. Mismatch in LinearMetaEvent.");
			}
		}

		void LinearMetaEvent::action(Player &player, Overworld &overworld){
			if(!processing){ //When triggered, start the process.
				processing = true;
				processingList.clear();
			}
		}

		void LinearMetaEvent::update(Player &player, Overworld &overworld){
			//Updating all the events in the queue.
			AbstractEvent* firstEvent = eventQueue.front(); //Storing the first event pointer to stop the loop.
			do { //Loops until it gets back to start.
				if(eventQueue.front() != nullptr) eventQueue.front()->update(player, overworld);
				eventQueue.push(eventQueue.front());
				eventQueue.pop();
			} while(firstEvent != eventQueue.front());

			if(processing){ //Processes the events.
				//Removes the event that have finished their execution of the processing list.
				processingList.remove_if([](AbstractEvent* event){return event->isOver();});
				if(processingList.empty()){//If the processing list is empty, add the next events.
					do {
						if(eventQueue.front() == nullptr){ //If the event is nullptr, pause the process and clear the processing list.
							processingList.clear();
							processing = false;
							return;
						}
						processingList.push_back(eventQueue.front()); //Adds the event in the processing list.
						eventQueue.front()->action(player, overworld); //Triggers the event.
						//Puts the event at the end of the queue.
						eventQueue.push(eventQueue.front());
						eventQueue.pop();
						actionQueue.push(actionQueue.front());
						actionQueue.pop();
					} while(actionQueue.front());//If the next event action is false, the program must wait for the queue to be empty again.
				}
			}
		}

	} /* namespace Elements */
} /* namespace OpMon */
