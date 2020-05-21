#include "AbstractMetaEvent.hpp"
#include "TPEvent.hpp"
#include "AnimationEvent.hpp"
#include "DialogEvent.hpp"
#include "SoundEvent.hpp"
#include "metaevents.hpp"

namespace OpMon::Elements {
	AbstractMetaEvent::AbstractMetaEvent(std::queue<AbstractEvent*> eventQueue)
	: AbstractEvent(*eventQueue.front())
	, eventQueue(eventQueue)
	, mainEvent(eventQueue.front()){}

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
			else if(type == "Trainer") eventQueue.push(new TrainerEvent(data, event));
			else if(type == "TalkingCharacter") eventQueue.push(new TrainerEvent(data, event));
			else if(type == "Door") eventQueue.push(new DoorEvent(data, event));
			else if(type == "LinearMeta") eventQueue.push(new LinearMetaEvent(data, event));
			else if(type == "nullptr") eventQueue.push(nullptr);
		}
		mainEvent = eventQueue.front();
	}

	AbstractMetaEvent::~AbstractMetaEvent(){
		while(eventQueue.size() > 0){
			if(eventQueue.front() != nullptr) delete(eventQueue.front());
			eventQueue.pop();
		}
	}

	void AbstractMetaEvent::update(Player &player, Overworld &overworld){
		position = mainEvent->getPosition();
		mapPos = mainEvent->getPositionMap();
	}

	void AbstractMetaEvent::setPosition(sf::Vector2i pos){
		mainEvent->setPosition(pos);
		AbstractEvent::setPosition(pos);
	}
}
