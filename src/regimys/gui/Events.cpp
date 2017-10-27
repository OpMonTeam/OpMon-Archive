#include "Events.hpp"
#include "Overworld.hpp"
#pragma GCC diagnostic ignored "-Wreorder"


UNS

using namespace Events;

Event::~Event() {
    delete(sprite);
}

Event::Event(sf::Texture &baseTexture, std::vector<sf::Texture>& otherTextures, EventTrigger eventTrigger, sf::Vector2f const& position, int sides, bool passable) :
    baseTexture(baseTexture), otherTextures(otherTextures), eventTrigger(eventTrigger),
    position(position),
    passable(passable),
    sides(sides) {
    sprite = new sf::Sprite();
    sprite->setTexture(this->baseTexture);
    sf::Vector2f posMap((position.x+8)*32, (position.y+8)*32);
    sprite->setPosition(posMap);
}



namespace Events {

bool justTP = false;

sf::Sound doorSound;
sf::Sound shopdoorSound;

namespace DoorType {
std::vector<sf::Texture> NORMAL, SHOP;
}

TPEvent::TPEvent(sf::Texture &baseTexture, std::vector<sf::Texture>& otherTextures, EventTrigger eventTrigger, sf::Vector2f const& position, sf::Vector2i const& tpPos, string const& map, Side ppDir, int sides, bool passable):
    Event(baseTexture, otherTextures, eventTrigger, position, sides, passable), tpCoord(tpPos), map(map), ppDir(ppDir) {

}

DoorEvent::DoorEvent(std::vector<sf::Texture> &doorType, sf::Vector2f const& position, sf::Vector2i const& tpPos, string const& map, EventTrigger eventTrigger, Side ppDir, int sides, bool passable):
    Event(doorType[0], doorType, eventTrigger, position, sides, passable),
    TPEvent(doorType[0], doorType, eventTrigger, position, tpPos, map, ppDir, sides, passable) {
    this->sprite->move(0, -6);
    if(&doorType[0] == &DoorType::SHOP[0]) {
        this->sprite->move(-4, 0);
        this->doorType = 1;
    }else{
        this->doorType = 0;
    }
}

TalkingEvent::TalkingEvent(sf::Texture &baseTexture, std::vector<sf::Texture>& otherTextures, sf::Vector2f const& position, std::vector<OpString> const& dialogKeys, int sides, EventTrigger eventTrigger, bool passable):
    Event(baseTexture, otherTextures, eventTrigger, position, sides, passable), dialogKeys(dialogKeys) {
    this->reloadKeys();
}

void TalkingEvent::reloadKeys() {
    dialogs.clear();
    FOR_EACH(OpString, this->dialogKeys, (int) this->dialogKeys.size(), {)
             dialogs.push_back(currentObj->getString());
            }
}

LockedDoorEvent::LockedDoorEvent(std::vector<sf::Texture> &doorType, Item *needed, sf::Vector2f const& position, sf::Vector2i const& tpPos, string const& map, Side ppDir, EventTrigger eventTrigger, bool consumeItem,int sides, bool passable) :
    DoorEvent(doorType, position, tpPos, map, eventTrigger, ppDir, sides, passable),
    Event(this->baseTexture, this->otherTextures, eventTrigger, position, sides, passable),
    TalkingEvent(this->baseTexture, this->otherTextures, position, LockedDoorEvent::keysLock, sides, eventTrigger, passable),
    needed(needed), consumeItem(consumeItem) {

}

  CharacterEvent::CharacterEvent(std::string texturesKey, sf::Vector2f const& position, MoveStyle moveStyle, EventTrigger eventTrigger, std::vector<Side> predefinedPath, bool passable, int sides):
    Event(Initializer::charaTextures[texturesKey][0], Initializer::charaTextures[texturesKey], eventTrigger, position, sides, passable),
    moveStyle(moveStyle) {
    sprite->setScale(2, 2);
    sprite->setOrigin(16, 16);
    sf::Vector2f posMap(((position.x+8)*32) + 16, (position.y+8)*32);
    sprite->setPosition(posMap);
    setPredefinedMove(predefinedPath);

}

  TalkingCharaEvent::TalkingCharaEvent(std::string texturesKey, sf::Vector2f const& position, std::vector<OpString> const& dialogKeys, EventTrigger eventTrigger, MoveStyle moveStyle, std::vector<Side> predefinedPath, bool passable, int sides):
  Event(Initializer::charaTextures[texturesKey][0], Initializer::charaTextures[texturesKey], eventTrigger, position, sides, passable),
    CharacterEvent(texturesKey, position, moveStyle, eventTrigger, predefinedPath, passable, sides),
    TalkingEvent(Initializer::charaTextures[texturesKey][0], Initializer::charaTextures[texturesKey], position, dialogKeys, sides, eventTrigger, passable) {

}

//Actions

void TPEvent::action(Player &player) {
    if(!justTP) {
        Main::mainframe.overworld.tp(map, tpCoord);
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
    if(doorType == 0){
        doorSound.setVolume(100);
        doorSound.play();
    }else if(doorType == 1){
        shopdoorSound.setVolume(300);
        shopdoorSound.play();
    }

}

void DoorEvent::update(Player &player) {
    if(animStarted != -1) {
        animStarted++;

        if(animStarted < 8 && (animStarted / 2)*2 == animStarted) {
            sprite->setTexture(otherTextures[animStarted / 2]);
        } else if(animStarted > 10) {
            TPEvent::action(player);
            animStarted = -1;
            sprite->setTexture(otherTextures[0]);
        }

    }
}

void TalkingEvent::action(Player &player) {
    Main::mainframe.overworld.boucleDialog(this->dialogs);
}

void TalkingEvent::update(Player &player) {

}

void CharacterEvent::update(Player &player) {
    frames++;
    if(anim == Side::NO_MOVE) {
      int randomMove;
      switch(moveStyle) {
        case MoveStyle::PREDEFINED:
            predefinedCounter++;
            if(predefinedCounter >= movements.size()) {
                predefinedCounter = 0;
            }
            move(movements[predefinedCounter], player);
            break;

        case MoveStyle::NO_MOVE:
            break;

        case MoveStyle::RANDOM:
	  randomMove = Utils::randUI(5) - 1;
	  switch(randomMove){
	  case -1:
	    move(Side::NO_MOVE, player);
	    break;
	  case 0:
	    move(Side::TO_UP, player);
	    break;
	  case 1:
	    move(Side::TO_DOWN, player);
	    break;
	  case 2:
	    move(Side::TO_LEFT, player);
	    break;
	  case 3:
	    move(Side::TO_RIGHT, player);
	    break;
	  default:
	    oplog("[WARNING] - Random number out of bounds CharacterEvent::update");
	    move(Side::NO_MOVE, player);
	  }
            break;

        case MoveStyle::FOLLOWING:
            //TODO
            break;
        }
    }
    if(anim >= 0 && !anims) {
      sprite->setTexture(otherTextures[(int) (anim + 4)]);
        animsCounter++;
        anims = animsCounter > 8;
    } else if(anim >= 0 && anims) {
      sprite->setTexture(otherTextures[(int) (anim + 8)]);
        animsCounter++;
        if(animsCounter > 16) {
            anims = false;
            animsCounter = 0;
        }
    } else if(anim < 0) {
      sprite->setTexture(otherTextures[(int) charaDir]);
    }

    switch(anim) {
    case Side::TO_UP:
        if(frames - startFrames >= 7) {
	  if(moving == Side::TO_UP) {
                sprite->move(0, -4);
            }
	  anim = Side::NO_MOVE;
	  moving = Side::NO_MOVE;
        } else {
            if(moving == Side::TO_UP) {
                sprite->move(0, -4);
            }
        }
        break;


    case Side::TO_DOWN:
        if(frames - startFrames >= 7) {
            if(moving == Side::TO_DOWN) {
                sprite->move(0, 4);
            }
            anim = Side::NO_MOVE;
            moving = Side::NO_MOVE;
        } else {
            if(moving == Side::TO_DOWN) {
                sprite->move(0, 4);
            }
        }
        break;


    case Side::TO_LEFT:
        if(frames - startFrames >= 7) {
            if(moving == Side::TO_LEFT) {
                sprite->move(-4, 0);
            }
            anim = Side::NO_MOVE;
            moving = Side::NO_MOVE;
        } else {
            if(moving == Side::TO_LEFT) {
                sprite->move(-4, 0);
            }
        }
        break;


    case Side::TO_RIGHT:
        if(frames - startFrames >= 7) {
            if(moving == Side::TO_RIGHT) {
                sprite->move(4, 0);
            }
            anim = Side::NO_MOVE;
            moving = Side::NO_MOVE;
        } else {
            if(moving == Side::TO_RIGHT) {
                sprite->move(4, 0);
            }
        }
        break;

    case Side::STAY:
        if(frames - startFrames >= 7) {
	  anim = Side::NO_MOVE;
        }
    };


}

void CharacterEvent::move(Side direction, Player& player) {
    startFrames = frames;
    if(anim == Side::NO_MOVE && direction == Side::NO_MOVE) {
      anim = Side::STAY;
      return;
    }
    if(anim == Side::NO_MOVE && direction != Side::NO_MOVE) {
        anim = direction;
        charaDir = direction;
        switch(direction) {
        case Side::TO_UP:
            if(position.y - 1 >= 0) {
                if(Main::mainframe.overworld.actual->getPassArr()[(int)position.y - 1][(int)position.x] == 0) {
                    if(!(position.y - 1 == player.getPosY() && position.x == player.getPosX())) {
                        for(Event *nextEvent : Main::mainframe.overworld.actual->getEvent(sf::Vector2i(position.x, position.y - 1))) {
                            if(!nextEvent->isPassable()) {
                                return;
                            }
                        }
                        moving = Side::TO_UP;
                        position.y--;
                    } else if(moveStyle == MoveStyle::PREDEFINED) {
                        predefinedCounter--;
                    }

                }
            }
            break;
        case Side::TO_DOWN:
            if(position.y + 1 < Main::mainframe.overworld.actual->getH()) {
                if(Main::mainframe.overworld.actual->getPassArr()[(int)position.y + 1][(int)position.x] == 0) {
                    if(!(position.y + 1 == player.getPosY() && position.x == player.getPosX())) {
                        for(Event *nextEvent : Main::mainframe.overworld.actual->getEvent(sf::Vector2i(position.x, position.y + 1))) {
                            if(!nextEvent->isPassable()) {
                                return;
                            }
                        }
                        moving = Side::TO_DOWN;
                        position.y++;
                    } else if(moveStyle == MoveStyle::PREDEFINED) {
                        predefinedCounter--;
                    }

                }
            }
            break;

        case Side::TO_RIGHT:
            if(position.x + 1 < Main::mainframe.overworld.actual->getW()) {
                if(Main::mainframe.overworld.actual->getPassArr()[(int)position.y][(int)position.x + 1] == 0) {
                    if(!(position.x + 1 == player.getPosX() && position.y == player.getPosY())) {
                        for(Event *nextEvent : Main::mainframe.overworld.actual->getEvent(sf::Vector2i(position.x + 1, position.y))) {
                            if(!nextEvent->isPassable()) {
                                return;
                            }
                        }
                        moving = Side::TO_RIGHT;
                        position.x++;
                    } else if(moveStyle == MoveStyle::PREDEFINED) {
                        predefinedCounter--;
                    }

                }
            }
            break;

        case Side::TO_LEFT:
            if(position.x - 1 >= 0) {
                if(Main::mainframe.overworld.actual->getPassArr()[(int)position.y][(int)position.x - 1] == 0) {
                    if(!(position.x - 1 == player.getPosX() && position.y == player.getPosY())) {
                        for(Event *nextEvent : Main::mainframe.overworld.actual->getEvent(sf::Vector2i(position.x - 1, position.y))) {
                            if(!nextEvent->isPassable()) {
                                return;
                            }
                        }
                        moving = Side::TO_LEFT;
                        position.x--;
                    } else if(moveStyle == MoveStyle::PREDEFINED) {
                        predefinedCounter--;
                    }

                }
            }
            break;
        default:
            break;
        }


    }
}

void TalkingCharaEvent::action(Player &player) {
    Main::mainframe.overworld.movementLock = true;
    talking = true;

}

void TalkingCharaEvent::update(Player &player) {
    if(Main::mainframe.overworld.movementLock && talking && anim == -1) {
        switch(player.getppDir()) {
        case Side::TO_UP:
	  sprite->setTexture(otherTextures[(int) Side::TO_DOWN]);
	  break;
        case Side::TO_DOWN:
	  sprite->setTexture(otherTextures[(int) Side::TO_UP]);
	  break;
        case Side::TO_LEFT:
	  sprite->setTexture(otherTextures[(int) Side::TO_RIGHT]);
	  break;
        case Side::TO_RIGHT:
	  sprite->setTexture(otherTextures[(int) Side::TO_LEFT]);
	  break;
        }
        Main::mainframe.overworld.movementLock = false;
        talking = false;
        Main::mainframe.overworld.boucleDialog(this->dialogs);
    }
    CharacterEvent::update(player);
}

void CharacterEvent::setPredefinedMove(std::vector<Side> moves) {
    this->movements = moves;
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
