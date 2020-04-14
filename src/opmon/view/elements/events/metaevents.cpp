#include "metaevents.hpp"
#include "AnimationEvent.hpp"
#include "SoundEvent.hpp"
#include "TPEvent.hpp"
#include "DialogEvent.hpp"
#include <queue>

namespace OpMon::Elements {
	DoorEvent::DoorEvent(OverworldData &data, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, EventTrigger eventTrigger, Side ppDir, int sides, bool passable)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new AnimationEvent(data.getDoorsTexture(doorType), eventTrigger, position, 1, false, passable, sides),
				new SoundEvent(data.getDoorsTexture(doorType), eventTrigger, position, doorType + " sound", false, false, sides, passable),
				new TPEvent(data.getDoorsTexture(doorType), eventTrigger, position, tpCoord, map, ppDir, sides, passable),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false, false}))){
		this->position += sf::Vector2f(0, -6); //TODO : Fix the sprites to get rid of this little fix
		if(doorType == "shop door") {
			this->position.x -= 4;
		}
	}

	DoorEvent::DoorEvent(OverworldData &data, nlohmann::json jsonData)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new AnimationEvent(data, jsonData),
				new SoundEvent(data, jsonData),
				new TPEvent(data, jsonData),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false, false}))){
		this->position += sf::Vector2f(0, -6); //TODO : Fix the sprites to get rid of this little fix
		if(jsonData.at("textures") == "shop door") {
			this->position.x -= 4;
		}
	}

	void DoorEvent::action(Player &player, Overworld &overworld){
		player.getPosition().lockMove();
		LinearMetaEvent::action(player, overworld);
	}

	void DoorEvent::update(Player &player, Overworld &overworld){
		LinearMetaEvent::update(player, overworld);
		if(!processing){
			player.getPosition().unlockMove();
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
				new BattleEvent(data, jsonData.at("battle")),
				new TalkingCharaEvent(data, jsonData.at("postbattle"))
	}))) {}

	void TrainerEvent::update(Player &player, Overworld &overworld){
		eventQueue.front()->update(player, overworld); //Updates the first event in the queue.
		if(triggered && !defeated && eventQueue.front()->isOver()){ //If the event has been triggered, not defeated yet and that the current action is over,
																	//it means that the player has interacted with the event, so the dialog has been launched
																	//and is now over, and the battle can now start, or that the battle just ended.
			delete(eventQueue.front()); //Deleting the pre-battle NPC or the battle event
			eventQueue.pop();
			mainEvent = eventQueue.front();
			if(eventQueue.size() == 2){ //If the only events left are the battle and the post-battle NPC
				eventQueue.front()->action(player, overworld); //Starts the battle
			}else{ //It can only mean one thing : one event left, and it is the post-battle NPC
				defeated = true; //If the only event left is the post-battle NPC and the trainer is not defeated, it means the battle just ended.
				triggered = false;
			}
		}

		AbstractMetaEvent::update(player, overworld);
	}

	void TrainerEvent::action(Player &player, Overworld &overworld){
		eventQueue.front()->action(player, overworld); //Triggers the first event in the queue.
		triggered = true;
	}
}
