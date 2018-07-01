#include "Events.hpp"

#include "../../../utils/defines.hpp"
#include "../../../utils/log.hpp"
#include "../../view/Overworld.hpp"
#include "../storage/Data.hpp"

#pragma GCC diagnostic ignored "-Wreorder"
#pragma GCC diagnostic ignored "-Wunused-parameter"
UNS

  namespace OpMon {
    namespace Model {

        using namespace Events;

        Event::~Event() {
        }

        Event::Event(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position,
                     int sides, bool passable)
          : otherTextures(otherTextures)
          , eventTrigger(eventTrigger)
          , position(sf::Vector2f((position.x) * 32, (position.y) * 32))
          , mapPos(position, true)
          , passable(passable)
          , sides(sides)
          , sprite(new sf::Sprite())
          , currentTexture(otherTextures.begin()) {
        }

        void Event::updateTexture() {
            this->sprite->setPosition(position);
            this->sprite->setTexture(*currentTexture);
        }

        namespace Events {

            bool justTP = false;

            sf::Sound doorSound;
            sf::Sound shopdoorSound;

            namespace DoorType {
                std::vector<sf::Texture> NORMAL, SHOP;
            }

            TPEvent::TPEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger,
                             sf::Vector2f const &position, sf::Vector2i const &tpPos, string const &map, Side ppDir,
                             int sides, bool passable)
              : Event(otherTextures, eventTrigger, position, sides, passable)
              , tpCoord(tpPos)
              , map(map)
              , ppDir(ppDir) {
            }

	  DoorEvent::DoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpPos,
                                 string const &map, EventTrigger eventTrigger, Side ppDir, int sides, bool passable)
              : Event(doorTextures, eventTrigger, position, sides, passable)
              , TPEvent(doorTextures, eventTrigger, position, tpPos, map, ppDir, sides, passable)
	      , doorType(doorType){
                this->position += sf::Vector2f(0, -6);
                if(doorType == "shop door") {
                    this->position.x -= 4;
                }
		if(doorType != "door" && doorType != "shop door"){
		  handleError(std::string("Warning - DoorEvent : Unknown door type \" ") + doorType + "\"");
		}
            }

            TalkingEvent::TalkingEvent(std::vector<sf::Texture> &otherTextures, sf::Vector2f const &position,
                                       std::vector<Utils::OpString> const &dialogKeys, int sides, EventTrigger eventTrigger,
                                       bool passable)
              : Event(otherTextures, eventTrigger, position, sides, passable)
              , dialogKeys(dialogKeys) {
                this->onLangChanged();
            }

            void TalkingEvent::onLangChanged() {
                dialogs.clear();
                for(auto &currentObj : this->dialogKeys) {
                    dialogs.push_back(currentObj.getString());
                }
            }

	  LockedDoorEvent::LockedDoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, Item *needed, sf::Vector2f const &position,
                                             sf::Vector2i const &tpPos, string const &map, Side ppDir,
                                             EventTrigger eventTrigger, bool consumeItem, int sides, bool passable)
	    : DoorEvent(doorTextures, doorType, position, tpPos, map, eventTrigger, ppDir, sides, passable)
              , Event(doorTextures, eventTrigger, position, sides, passable)
              , TalkingEvent(doorTextures, position, LockedDoorEvent::keysLock, sides, eventTrigger, passable)
              , needed(needed)
              , consumeItem(consumeItem) {
            }

	  CharacterEvent::CharacterEvent(std::vector<sf::Texture>& textures, sf::Vector2f const &position, Side posDir, MoveStyle moveStyle,
                                           EventTrigger eventTrigger, std::vector<Side> predefinedPath, bool passable,
                                           int sides)
              : Event(textures, eventTrigger, position, sides, passable)
              , moveStyle(moveStyle) {
                sprite->setScale(2, 2);
                sprite->setOrigin(16, 16);
                this->position += sf::Vector2f(16, 0);
                setPredefinedMove(predefinedPath);
                mapPos.setDir(posDir);
            }

	  TalkingCharaEvent::TalkingCharaEvent(std::vector<sf::Texture>& textures, sf::Vector2f const &position,
                                                 std::vector<Utils::OpString> const &dialogKeys, Side posDir, EventTrigger eventTrigger,
                                                 MoveStyle moveStyle, std::vector<Side> predefinedPath, bool passable,
                                                 int sides)
              : Event(textures, eventTrigger, position, sides, passable)
              , CharacterEvent(texturesKey, position, posDir, moveStyle, eventTrigger, predefinedPath, passable, sides)
              , TalkingEvent(textures, position, dialogKeys, sides, eventTrigger, passable) {
            }

            //Actions

            void TPEvent::action(Model::Player &player, View::Overworld &overworld) {
                if(!justTP) {
                    overworld.tp(map, tpCoord);
                    if(this->ppDir != -1) {
                        player.getPosition().setDir(this->ppDir);
                    }
                    justTP = true;
                }
            }

            void TPEvent::update(Model::Player &player, View::Overworld &overworld) {
            }

            void DoorEvent::action(Model::Player &player, View::Overworld &overworld) {
                animStarted = 0;
                player.getPosition().lockMove();
                overworld.getData().getUiDataPtr()->getJukebox().play(doorType + " sound");
            }

            void DoorEvent::update(Model::Player &player, View::Overworld &overworld) {
                if(animStarted != -1) {
                    animStarted++;
                    if(animStarted < 8 && (animStarted / 2) * 2 == animStarted) {
                        currentTexture = otherTextures.begin() + (animStarted / 2);
                    } else if(animStarted > 10) {
                        player.getPosition().unlockMove();
                        TPEvent::action(player, overworld);
                        animStarted = -1;
                        currentTexture = otherTextures.begin();
                    }
                }
            }

            void TalkingEvent::action(Model::Player &player, View::Overworld &overworld) {
                overworld.startDialog(this->dialogs);
            }

            void TalkingEvent::update(Model::Player &player, View::Overworld &overworld) {
            }

            void CharacterEvent::update(Model::Player &player, View::Overworld &overworld) {
                frames++;
                if(!mapPos.isAnim()) {
                    int randomMove;
                    switch(moveStyle) {
                    case MoveStyle::PREDEFINED:
                        predefinedCounter++;
                        if(predefinedCounter >= movements.size()) {
                            predefinedCounter = 0;
                        }
                        move(movements[predefinedCounter]);
                        if(!mapPos.isMoving()) {
			  if(predefinedCounter != 0){
                            predefinedCounter--;
			  }
			  predefinedCounter = movements.size() - 1;
                        }
                        break;

                    case MoveStyle::NO_MOVE:
                        break;

                    case MoveStyle::RANDOM:
                        randomMove = Utils::Misc::randUI(5) - 1;
                        switch(randomMove) {
                        case -1:
                            move(Side::NO_MOVE);
                            break;
                        case 0:
                            move(Side::TO_UP);
                            break;
                        case 1:
                            move(Side::TO_DOWN);
                            break;
                        case 2:
                            move(Side::TO_LEFT);
                            break;
                        case 3:
                            move(Side::TO_RIGHT);
                            break;
                        default:
                            handleError("[WARNING] - Random number out of bounds CharacterEvent::update");
                            move(Side::NO_MOVE);
                        }
                        break;

                    case MoveStyle::FOLLOWING:
                        //TODO
                        break;
                    }
                }
                if(mapPos.isAnim() && !anims && mapPos.getDir() != Side::STAY) {
                    currentTexture = otherTextures.begin() + ((int)mapPos.getDir() + 4);
                    animsCounter++;
                    anims = animsCounter > 8;
                } else if(mapPos.isAnim() && anims && mapPos.getDir() != Side::STAY) {
                    currentTexture = otherTextures.begin() + ((int)mapPos.getDir() + 8);
                    animsCounter++;
                    if(animsCounter > 16) {
                        anims = false;
                        animsCounter = 0;
                    }
                } else if(!mapPos.isAnim()) {
                    currentTexture = otherTextures.begin() + (int)mapPos.getDir();
                }

                if(mapPos.isAnim()) {
                    switch(mapPos.getDir()) {
                    case Side::TO_UP:
                        if(frames - startFrames >= 7) {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(0, -4);
                            mapPos.stopMove();
                        } else {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(0, -4);
                        }
                        break;

                    case Side::TO_DOWN:
                        if(frames - startFrames >= 7) {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(0, 4);
                            mapPos.stopMove();
                        } else {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(0, 4);
                        }
                        break;

                    case Side::TO_LEFT:
                        if(frames - startFrames >= 7) {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(4, 0);
                            mapPos.stopMove();
                        } else {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(4, 0);
                        }
                        break;

                    case Side::TO_RIGHT:
                        if(frames - startFrames >= 7) {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(-4, 0);
                            mapPos.stopMove();
                        } else {
                            if(mapPos.isMoving())
                                position -= sf::Vector2f(-4, 0);
                        }
                        break;

                    case Side::STAY:
                        if(frames - startFrames >= 7) {
                            mapPos.stopMove();
                        }
			break;
		    default: break;
                    }
                }
            }

            void CharacterEvent::move(Side direction) {
                startFrames = frames;
                mapPos.move(direction);
            }

            void CharacterEvent::move(Side direction, Model::Player &player, View::Overworld &overworld) {
                move(direction);
            }

            void TalkingCharaEvent::action(Model::Player &player, View::Overworld &overworld) {
                mapPos.lockMove();
                talking = true;
            }

            void TalkingCharaEvent::update(Model::Player &player, View::Overworld &overworld) {
                CharacterEvent::update(player, overworld);
                if(talking && !mapPos.isAnim()) {
                    switch(player.getPosition().getDir()) {
                    case Side::TO_DOWN:
                        mapPos.setDir(Side::TO_UP);
                        break;
                    case Side::TO_UP:
                        mapPos.setDir(Side::TO_DOWN);
                        break;
                    case Side::TO_LEFT:
                        mapPos.setDir(Side::TO_RIGHT);
                        break;
                    case Side::TO_RIGHT:
                        mapPos.setDir(Side::TO_LEFT);
                        break;
                    default:
                        break;
                    }
                    currentTexture = otherTextures.begin() + (int)mapPos.getDir();
                    updateTexture();
                    mapPos.unlockMove();
                    talking = false;
                    overworld.startDialog(this->dialogs);
                }
            }

            void CharacterEvent::setPredefinedMove(std::vector<Side> moves) {
                this->movements = moves;
            }

            void LockedDoorEvent::action(Model::Player &player, View::Overworld &overworld) {
            }

            void LockedDoorEvent::update(Model::Player &player, View::Overworld &overworld) {
            }

            std::vector<Utils::OpString> LockedDoorEvent::keysLock = std::vector<Utils::OpString>();

        } // namespace Events

        

    } // namespace Model
}
#pragma GCC diagnostic pop
