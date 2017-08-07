#include "Events.hpp"
#include "Overworld.hpp"

UNS

Event::~Event() {
    delete(sprite);
}

Event::Event(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, int sides, bool passable) :
    baseTexture(baseTexture), otherTextures(otherTextures), eventTrigger(eventTrigger),
    position(position), passable(passable), sides(sides) {
    sprite = new sf::Sprite();
    sprite->setTexture(this->baseTexture);
    sf::Vector2f posMap((position.x+9)*32, (position.y+9)*32);
    sprite->setPosition(posMap);
}



namespace Events {

    bool justTP = false;

    sf::Sound doorSound;

    namespace DoorType {
        std::vector<sf::Texture> NORMAL, SHOP;
    }

    TPEvent::TPEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int ppDir, int sides, bool passable):
        Event(baseTexture, otherTextures, eventTrigger, position, sides, passable), tpCoord(tpPos), mapID(mapID), ppDir(ppDir) {

    }

    DoorEvent::DoorEvent(std::vector<sf::Texture> &doorType, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int eventTrigger, int ppDir, int sides, bool passable):
        Event(doorType[0], doorType, eventTrigger, position, sides, passable),
        TPEvent(doorType[0], doorType, eventTrigger, position, tpPos, mapID, ppDir, sides, passable) {
        this->sprite->move(0, -6);
        if(&doorType[0] == &DoorType::SHOP[0]) {
                this->sprite->move(-4, 0);
            }
    }

    TalkingEvent::TalkingEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, sf::Vector2f position, std::vector<OpString> dialogKeys, int sides, int eventTrigger, bool passable):
        Event(baseTexture, otherTextures, eventTrigger, position, sides, passable), dialogKeys(dialogKeys) {
        this->reloadKeys();
    }

    void TalkingEvent::reloadKeys() {
        dialogs.clear();
        FOR_EACH(OpString, this->dialogKeys, this->dialogKeys.size(), {)
                 dialogs.push_back(objActuel->getString());
        }
    }

    LockedDoorEvent::LockedDoorEvent(std::vector<sf::Texture> &doorType, Item *needed, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int ppDir, int eventTrigger, bool consumeItem,int sides, bool passable) :
        DoorEvent(doorType, position, tpPos, mapID, eventTrigger, ppDir, sides, passable),
        Event(this->baseTexture, this->otherTextures, eventTrigger, position, sides, passable),
        TalkingEvent(this->baseTexture, this->otherTextures, position, LockedDoorEvent::keysLock, sides, eventTrigger, passable),
        needed(needed), consumeItem(consumeItem) {

    }

    CharacterEvent::CharacterEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, int moveStyle, int eventTrigger, bool passable, int sides):
        Event(charTextures[0], charTextures, eventTrigger, position, sides, passable),
        moveStyle(moveStyle) {

    }

    TalkingCharaEvent::TalkingCharaEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, std::vector<OpString> dialogKeys, int eventTrigger, int moveStyle, bool passable, int sides):
        Event(charTextures[0], charTextures, eventTrigger, position, sides, passable),
        CharacterEvent(charTextures, position, moveStyle, eventTrigger, sides),
        TalkingEvent(charTextures[0], charTextures, position, dialogKeys, sides, eventTrigger, passable) {

    }

//les actions

    void TPEvent::action(Player &player) {
        if(!justTP) {
                MainFrame::Overworld::tp(mapID, tpCoord);
                if(this->ppDir != -1) {
                        Main::player.setppDir(this->ppDir);
                    }
                justTP = true;
            }

    }

    void TPEvent::update(Player &player) {

    }

    void DoorEvent::action(Player &player) {
        animStarted = 0;
    }

    void DoorEvent::update(Player &player) {
        if(animStarted != -1) {
                animStarted++;
                if(animStarted < 8 && (animStarted / 2)*2 == animStarted) {
                        sprite->setTexture(otherTextures[animStarted / 2]);
                    }
                else if(animStarted > 10) {
                        TPEvent::action(player);
                        animStarted = -1;
                        sprite->setTexture(otherTextures[0]);
                        doorSound.setVolume(100);
                        doorSound.play();
                    }

            }
    }

    void TalkingEvent::action(Player &player) {
        MainFrame::Overworld::boucleDialog(this->dialogs);
    }

    void TalkingEvent::update(Player &player) {

    }

    void CharacterEvent::update(Player &player) {

    }

    void TalkingCharaEvent::action(Player &player) {

    }

    void TalkingCharaEvent::update(Player &player) {

    }

    void CharacterEvent::setPredefinedMove(std::vector<int> moves) {

    }

    void LockedDoorEvent::action(Player &player) {

    }

    void LockedDoorEvent::update(Player &player) {

    }

  std::vector<OpString> LockedDoorEvent::keysLock = std::vector<OpString>();


}

void initEnumsEvents() {
    Events::DoorType::NORMAL = Initializer::doorsTextures[0];
    Events::DoorType::SHOP = Initializer::doorsTextures[1];
}
