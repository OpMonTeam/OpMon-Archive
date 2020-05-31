#include "metaevents.hpp"
#include "AnimationEvent.hpp"
#include "SoundEvent.hpp"
#include "TPEvent.hpp"
#include "DialogEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"
#include <queue>

namespace OpMon::Elements {

	DoorEvent::DoorEvent(OverworldData &data, nlohmann::json jsonData)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new AnimationEvent(data, jsonData, {sf::IntRect(0, 0, 42, 36), sf::IntRect(42, 0, 42, 36), sf::IntRect(84, 0, 42, 36), sf::IntRect(126, 0, 42, 36)}),
				new SoundEvent(data, jsonData),
				new TPEvent(data, jsonData),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false, false}))){
		this->sprite->setOrigin(5, 6); //The doors are a bit bigger than a square (42x36 instead of 32x32).
	}

	void DoorEvent::update(Overworld &overworld){
		LinearMetaEvent::update(overworld);
		if(!processing && !overworld.getCharacter().getPositionMap().isLocked()){
			eventQueue.front()->resetFrame();
		}
	}

	TalkingCharaEvent::TalkingCharaEvent(OverworldData &data, nlohmann::json jsonData)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new CharacterEvent(data, jsonData),
				new DialogEvent(data, jsonData),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, false, false}))) {}

	void TalkingCharaEvent::action(Overworld& overworld){
		mapPos.lockMove();
		LinearMetaEvent::action(overworld);
	}

	void TalkingCharaEvent::update(Overworld &overworld){
		LinearMetaEvent::update(overworld);
		if(processing && !mapPos.isAnim()){
			mapPos.unlockMove();
		}
	}


	TrainerEvent::TrainerEvent(TalkingCharaEvent* prebattlenpc, BattleEvent* battle, TalkingCharaEvent* postbattlenpc)
	: AbstractMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		prebattlenpc, battle, postbattlenpc
	}))) {}

	TrainerEvent::TrainerEvent(OverworldData &data, nlohmann::json jsonData)
	: AbstractMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new TalkingCharaEvent(data, jsonData.at("prebattle")),
				new BattleEvent(data, jsonData.at("prebattle"))
	}))) {
		// If "postbattle" field doesn't exist, the post battle character is the same as the pre battle one.
		eventQueue.push(jsonData.contains("postbattle") ? new TalkingCharaEvent(data, jsonData.at("postbattle")) : eventQueue.front());
	}

	void TrainerEvent::update(Overworld &overworld){
		eventQueue.front()->update(overworld); //Updates the first event in the queue.
		if(triggered && !defeated && eventQueue.front()->isOver()){ //If the event has been triggered, not defeated yet and that the current action is over,
																	//it means that the player has interacted with the event, so the dialog has been launched
																	//and is now over, and the battle can now start.
			garbage.push_back(eventQueue.front()); //Deleting the pre-battle NPC or the battle event
			eventQueue.pop();
			mainEvent = eventQueue.front();
			eventQueue.front()->action(overworld); //Starts the battle

			garbage.push_back(eventQueue.front());
			eventQueue.pop(); //Shows the post battle npc
			defeated = true;
			triggered = false;
			if(eventQueue.front()->getPositionMap().getPosition() == sf::Vector2i(0,0))            //If the position of the new event is 0,0
				eventQueue.front()->setPosition(garbage.front()->getPositionMap().getPosition());  //sets it to the position of the pre battle event
			mainEvent = eventQueue.front();
		}

		AbstractMetaEvent::update(overworld);
	}

	void TrainerEvent::action(Overworld &overworld){
		eventQueue.front()->action(overworld); //Triggers the first event in the queue.
		triggered = true;
	}

	TrainerEvent::~TrainerEvent(){
		for(AbstractEvent* event : garbage) {
			delete(event);
		}
	}
}
