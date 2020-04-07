#include "AbstractMetaEvent.hpp"
#include "TPEvent.hpp"
#include "AnimationEvent.hpp"
#include "DialogEvent.hpp"
#include "SoundEvent.hpp"
#include "metaevents.hpp"

namespace OpMon::Elements {
	AbstractMetaEvent::AbstractMetaEvent(std::queue<AbstractEvent*> eventQueue)
	: AbstractEvent(eventQueue.front()->getTextures(), eventQueue.front()->getEventTrigger(), eventQueue.front()->getPosition(), eventQueue.front()->getSide(), eventQueue.front()->isPassable())
	, eventQueue(eventQueue) {}

	AbstractMetaEvent::AbstractMetaEvent(OverworldData &data, nlohmann::json jsonData)
	: AbstractEvent(data, jsonData.at("events").at(0)){
		for(nlohmann::json event : jsonData.at("events")){
			std::string type = event.at("type");
			if(type == "TP") eventQueue.push(new TPEvent(data, event));
			else if(type == "Animation") eventQueue.push(new AnimationEvent(data, event));
			else if(type == "Character") eventQueue.push(new CharacterEvent(data, event));
			else if(type == "Dialog") eventQueue.push(new DialogEvent(data, event));
			else if(type == "Sound") eventQueue.push(new SoundEvent(data, event));
			else if(type == "Battle") eventQueue.push(new BattleEvent(data, event));
		}
	}

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
