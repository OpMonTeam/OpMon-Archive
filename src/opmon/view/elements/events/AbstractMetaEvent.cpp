#include "AbstractMetaEvent.hpp"

namespace OpMon::Elements {
	AbstractMetaEvent::AbstractMetaEvent(std::queue<AbstractEvent*> eventQueue)
	: AbstractEvent(eventQueue.front()->getTextures(), eventQueue.front()->getEventTrigger(), eventQueue.front()->getPosition(), eventQueue.front()->getSide(), eventQueue.front()->isPassable())
	, eventQueue(eventQueue) {}
}
