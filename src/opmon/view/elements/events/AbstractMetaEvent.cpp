#include "AbstractMetaEvent.hpp"

namespace OpMon::Elements {
	AbstractMetaEvent::AbstractMetaEvent(std::queue<AbstractEvent*> eventQueue)
	: AbstractEvent(eventQueue.front()->getTextures(), eventQueue.front()->getEventTrigger(), eventQueue.front()->getPosition(), eventQueue.front()->getSide(), eventQueue.front()->isPassable())
	, eventQueue(eventQueue) {}

	AbstractMetaEvent::~AbstractMetaEvent(){
		while(eventQueue.size() > 0){
			if(eventQueue.front() != nullptr) delete(eventQueue.front());
			eventQueue.pop();
		}
	}

	void AbstractMetaEvent::update(Player &player, Overworld &overworld){
		AbstractEvent* event = eventQueue.front();
		otherTextures = event->getTextures();
		eventTrigger = event->getEventTrigger();
		position = event->getPosition();
		mapPos = event->getPositionMap();
		passable = event->isPassable();
		sides = event->getSide();
	}
}
