#include "metaevents.hpp"
#include "AnimationEvent.hpp"
#include "SoundEvent.hpp"
#include "TPEvent.hpp"
#include "DialogEvent.hpp"
#include <queue>

namespace OpMon::Elements {
	DoorEvent::DoorEvent(OverworldData &data, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, EventTrigger eventTrigger, Side ppDir, int sides, bool passable)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new AnimationEvent(data.getDoorsTexture(doorType), eventTrigger, position, 4, false, passable, sides),
				new SoundEvent(data.getDoorsTexture(doorType), eventTrigger, position, doorType + " sound", false, false, sides, passable),
				new TPEvent(data.getDoorsTexture(doorType), eventTrigger, position, tpCoord, map, ppDir, sides, passable),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false, false}))){
		this->sprite->setOrigin(5, 6); //The doors are a bit bigger than a square (42x36 instead of 32x32).
	}

	DoorEvent::DoorEvent(OverworldData &data, nlohmann::json jsonData)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new AnimationEvent(data, jsonData),
				new SoundEvent(data, jsonData),
				new TPEvent(data, jsonData),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false, false}))){
		this->sprite->setOrigin(5, 6); //The doors are a bit bigger than a square (42x36 instead of 32x32).
	}

	void DoorEvent::update(Player &player, Overworld &overworld){
		LinearMetaEvent::update(player, overworld);
		if(!processing){
			eventQueue.front()->resetTexture();
		}
	}


	TalkingCharaEvent::TalkingCharaEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Utils::OpString const &dialogKey, Side posDir, EventTrigger eventTrigger, MoveStyle moveStyle, std::vector<Side> predefinedPath, bool passable, int side)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new CharacterEvent(textures, position, posDir, moveStyle, eventTrigger, predefinedPath, passable, sides),
				new DialogEvent(textures, position, dialogKey, sides, eventTrigger, passable),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, false, false}))) {}

	TalkingCharaEvent::TalkingCharaEvent(OverworldData &data, nlohmann::json jsonData)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new CharacterEvent(data, jsonData),
				new DialogEvent(data, jsonData),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, false, false}))) {}

	void TalkingCharaEvent::action(Player &player, Overworld& overworld){
		mapPos.lockMove();
		LinearMetaEvent::action(player, overworld);
	}

	void TalkingCharaEvent::update(Player &player, Overworld &overworld){
		LinearMetaEvent::update(player, overworld);
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

	void TrainerEvent::update(Player &player, Overworld &overworld){
		eventQueue.front()->update(player, overworld); //Updates the first event in the queue.
		if(triggered && !defeated && eventQueue.front()->isOver()){ //If the event has been triggered, not defeated yet and that the current action is over,
																	//it means that the player has interacted with the event, so the dialog has been launched
																	//and is now over, and the battle can now start.
			garbage.push_back(eventQueue.front()); //Deleting the pre-battle NPC or the battle event
			eventQueue.pop();
			mainEvent = eventQueue.front();
			eventQueue.front()->action(player, overworld); //Starts the battle

			garbage.push_back(eventQueue.front());
			eventQueue.pop(); //Shows the post battle npc
			defeated = true;
			triggered = false;
			if(eventQueue.front()->getPositionMap().getPosition() == sf::Vector2i(0,0))            //If the position of the new event is 0,0
				eventQueue.front()->setPosition(garbage.front()->getPositionMap().getPosition());  //sets it to the position of the pre battle event
			mainEvent = eventQueue.front();
		}

		AbstractMetaEvent::update(player, overworld);
	}

	void TrainerEvent::action(Player &player, Overworld &overworld){
		eventQueue.front()->action(player, overworld); //Triggers the first event in the queue.
		triggered = true;
	}

	TrainerEvent::~TrainerEvent(){
		for(AbstractEvent* event : garbage) {
			delete(event);
		}
	}
}
