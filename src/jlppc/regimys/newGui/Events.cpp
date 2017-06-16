#include "Events.hpp"

UNS

Event::Event(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2i position, bool passable) :
baseTexture(baseTexture), otherTextures(otherTextures), eventTrigger(eventTrigger),
position(position), passable(passable){
    sprite = new sf::Sprite();
    sprite.setTexture(this->baseTexture);
    sprite.setPosition(this->position);
}

namespace Events{

TPEvent::TPEvent(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2i position, sf::Vector2i tpPos, int mapID, bool passable):
Event(baseTexture, otherTextures, eventTrigger, position, passable), tpCoord(tpPos), mapID(mapID){

}

DoorEvent::DoorEvent(int doorType, sf::Vector2i position, sf::Vector2i tpPos, int mapID, int eventTrigger = 3, bool passable):
TPEvent(selectDoorType(doorType), selectDoorTypeOther(doorType), eventTrigger, position, tpPos, mapID, passable),
doorType(doorType){

}

TalkingEvent::TalkingEvent(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, sf::Vector2i position, std::vector<std::string> dialogKeys, int eventTrigger = 0, bool passable = false):
Event(baseTexture, otherTextures, eventTrigger, position, passable), dialogKeys(dialogKeys){
    this->reloadKeys();
}

void TalkingEvent::reloadKeys(){
    dialogs.clear();
    FOR_EACH(std::string, this->dialogsKeys, this->dialogKeys.size(),{)
        dialogs.push_back(StringKeys::get(*objActuel));
    }
}

LockedDoorEvent::LockedDoorEvent(int doorType, Item* needed, sf::Vector2i position, sf::Vector2i tpPos, int mapID, int eventTrigger = 0, bool passable = false, bool consumeItem = false) :
DoorEvent(doorType, position, tpPos, mapID, eventTrigger, passable),
TalkingEvent(this->baseTexture, this->otherTextures, eventTrigger, position, LockedDoorEvent::keysLock),
needed(needed), consumeItem(consumeItem){

}

CharacterEvent::CharacterEvent(std::vector<sf::Texture> charTextures, sf::Vector2i position, int moveStyle = 0, int eventTrigger = 0, bool passable = false):
Event(charTextures[0], charTextures, eventTrigger, position, passable),
moveStyle(moveStyle){

}

TalkingCharaEvent::TalkingCharaEvent(std::vector<sf::Texture> charTextures, sf::Vector2i position, std::vector<std::string> dialogKeys, int eventTrigger = 0, int moveStyle = 0):
CharacterEvent(charTextures, position, moveStyle, eventTrigger),
TalkingEvent(charTextures[0], charTextures, eventTrigger, position, dialogKeys){

}







}
