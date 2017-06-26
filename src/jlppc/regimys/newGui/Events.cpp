#include "Events.hpp"
#include "Overworld.hpp"

UNS

Event::~Event(){
    delete(sprite);
}

Event::Event(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, bool passable) :
baseTexture(baseTexture), otherTextures(otherTextures), eventTrigger(eventTrigger),
position(position), passable(passable){
    sprite = new sf::Sprite();
    sprite->setTexture(this->baseTexture);
    sf::Vector2f posMap((position.x+9)*32, (position.y+9)*32);
    sprite->setPosition(posMap);
}

namespace Events{

TPEvent::TPEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, sf::Vector2i tpPos, int mapID, bool passable):
Event(baseTexture, otherTextures, eventTrigger, position, passable), tpCoord(tpPos), mapID(mapID){

}

DoorEvent::DoorEvent(int doorType, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int eventTrigger, bool passable):
Event(selectDoorType(doorType), selectDoorTypeOther(doorType), eventTrigger, position, passable),
TPEvent(selectDoorType(doorType), selectDoorTypeOther(doorType), eventTrigger, position, tpPos, mapID, passable){

}

TalkingEvent::TalkingEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, sf::Vector2f position, std::vector<std::string> dialogKeys, int eventTrigger, bool passable):
Event(baseTexture, otherTextures, eventTrigger, position, passable), dialogKeys(dialogKeys){
    this->reloadKeys();
}

void TalkingEvent::reloadKeys(){
    dialogs.clear();
    FOR_EACH(std::string, this->dialogKeys, this->dialogKeys.size(),{)
        dialogs.push_back(StringKeys::get(*objActuel));
    }
}

LockedDoorEvent::LockedDoorEvent(int doorType, Item* needed, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int eventTrigger, bool consumeItem, bool passable) :
DoorEvent(doorType, position, tpPos, mapID, eventTrigger, passable),
Event(this->baseTexture, this->otherTextures, eventTrigger, position, passable),
TalkingEvent(this->baseTexture, this->otherTextures, position, LockedDoorEvent::keysLock, eventTrigger, passable),
needed(needed), consumeItem(consumeItem){

}

CharacterEvent::CharacterEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, int moveStyle, int eventTrigger, bool passable):
Event(charTextures[0], charTextures, eventTrigger, position, passable),
moveStyle(moveStyle){

}

TalkingCharaEvent::TalkingCharaEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, std::vector<std::string> dialogKeys, int eventTrigger, int moveStyle, bool passable):
Event(charTextures[0], charTextures, eventTrigger, position, passable),
CharacterEvent(charTextures, position, moveStyle, eventTrigger),
TalkingEvent(charTextures[0], charTextures, position, dialogKeys, eventTrigger, passable){

}

//les actions

void TPEvent::action(Player &player){

}

void TPEvent::update(Player &player){

}

sf::Texture& DoorEvent::selectDoorType(int doorType){
}

std::vector<sf::Texture> DoorEvent::selectDoorTypeOther(int doorType){
    return std::vector<sf::Texture>();
}

void DoorEvent::action(Player &player){

}

void DoorEvent::update(Player &player){

}

void TalkingEvent::action(Player &player){
    MainFrame::Overworld::boucleDialog(this->dialogs);
}

void TalkingEvent::update(Player &player){

}

void CharacterEvent::update(Player &player){

}

void TalkingCharaEvent::action(Player &player){

}

void TalkingCharaEvent::update(Player &player){

}

void CharacterEvent::setPredefinedMove(std::vector<int> moves){

}

void LockedDoorEvent::action(Player &player){

}

void LockedDoorEvent::update(Player &player){

}

std::vector<std::string> LockedDoorEvent::keysLock = std::vector<std::string>();


}
