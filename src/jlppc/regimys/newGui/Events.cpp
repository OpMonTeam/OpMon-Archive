#include "Events.hpp"

UNS

Event::Event(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2i position, bool passable) :
baseTexture(baseTexture), otherTextures(otherTextures), eventTrigger(eventTrigger), position(position), passable(passable){
    sprite = new sf::Sprite();
    sprite.setTexture(this->baseTexture);
    sprite.setPosition(this->position);
}

namespace Events{

TPEvent::TPEvent(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2i position, sf::Vector2i tpPos, int mapID):
Event(baseTexture, otherTextures, eventTrigger, position, passable), tpCoord(tpPos), mapID(mapID){

}

DoorEvent::DoorEvent(int doorType, sf::Vector2i position, sf::Vector2i tpPos, int eventTrigger = 3):
TPEvent(selectDoorType(doorType), selectDoorTypeOther(doorType), eventTrigger, position, tpPos, mapID), doorType(doorType){

}



}
