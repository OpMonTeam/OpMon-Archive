/*
Events.cpp
Author : Cyrielle
Contributors : BAKFR, Stelyus
File under GNU GPL v3.0 license
*/
#include "Events.hpp"

#include "../../../utils/defines.hpp"
#include "../../../utils/log.hpp"
#include "../../core/Core.hpp"
#include "../Overworld.hpp"
#include "Position.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wreorder"

namespace OpMon {
    namespace Model {

        using namespace Events;

        Event::Event(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position,
                     int sides, bool passable)
          : otherTextures(otherTextures)
          , eventTrigger(eventTrigger)
          , position(sf::Vector2f((position.x) * 32, (position.y) * 32))
          , mapPos(position, true)
          , passable(passable)
          , sides(sides)
          , sprite(std::make_unique<sf::Sprite>())
          , currentTexture(otherTextures.begin()) {
        }

        void Event::updateTexture() {
            this->sprite->setPosition(position);
            this->sprite->setTexture(*currentTexture);
        }

        namespace Events {
            std::vector<sf::Texture> alpha = std::vector<sf::Texture>(1);
            bool justTP = false;

            sf::Sound doorSound;
            sf::Sound shopdoorSound;

            namespace DoorType {
                std::vector<sf::Texture> NORMAL, SHOP;
            }

            TPEvent::TPEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger,
                             sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, Side ppDir,
                             int sides, bool passable)
              : Event(otherTextures, eventTrigger, position, sides, passable)
              , tpCoord(tpPos)
              , map(map)
              , ppDir(ppDir) {
            }

            DoorEvent::DoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpPos,
                                 std::string const &map, EventTrigger eventTrigger, Side ppDir, int sides, bool passable)
              : Event(doorTextures, eventTrigger, position, sides, passable)
              , TPEvent(doorTextures, eventTrigger, position, tpPos, map, ppDir, sides, passable)
              , doorType(doorType) {
                //The doors doesn't fit exactly.
                this->position += sf::Vector2f(0, -6);
                if(doorType == "shop door") {
                    this->position.x -= 4;
                }
                if(doorType != "door" && doorType != "shop door") {
                    handleError(std::string("Warning - DoorEvent : Unknown door type \" ") + doorType + "\"");
                }
            }

            TalkingEvent::TalkingEvent(std::vector<sf::Texture> &otherTextures, sf::Vector2f const &position,
                                       Utils::OpString const &dialogKey, int sides, EventTrigger eventTrigger,
                                       bool passable)
              : Event(otherTextures, eventTrigger, position, sides, passable)
              , dialogKey(dialogKey) {
                this->onLangChanged();
            }

            void TalkingEvent::onLangChanged() {
                dialog.clear();
                dialog = dialogKey.getString();
            }

            LockedDoorEvent::LockedDoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, Item *needed, sf::Vector2f const &position,
                                             sf::Vector2i const &tpPos, std::string const &map, Side ppDir,
                                             EventTrigger eventTrigger, bool consumeItem, int sides, bool passable)
              : DoorEvent(doorTextures, doorType, position, tpPos, map, eventTrigger, ppDir, sides, passable)
              , Event(doorTextures, eventTrigger, position, sides, passable)
              , TalkingEvent(doorTextures, position, LockedDoorEvent::keysLock, sides, eventTrigger, passable)
              , needed(needed)
              , consumeItem(consumeItem) {
            }

            CharacterEvent::CharacterEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Side posDir, MoveStyle moveStyle,
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

            TalkingCharaEvent::TalkingCharaEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position,
                                                 Utils::OpString const &dialogKey, Side posDir, EventTrigger eventTrigger,
                                                 MoveStyle moveStyle, std::vector<Side> predefinedPath, bool passable,
                                                 int sides)
              : Event(textures, eventTrigger, position, sides, passable)
              , CharacterEvent(textures, position, posDir, moveStyle, eventTrigger, predefinedPath, passable, sides)
              , TalkingEvent(textures, position, dialogKey, sides, eventTrigger, passable) {
            }

            TrainerEvent::TrainerEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, OpTeam *team, Utils::OpString const &dialogKeys, Utils::OpString const &defeatedDialog, Side posDir, EventTrigger eventTrigger, MoveStyle moveStyle, std::vector<Side> predefinedPath, bool passable, int side)
              : Event(textures, eventTrigger, position, side, passable)
              , TalkingCharaEvent(textures, position, dialogKeys, posDir, eventTrigger, moveStyle, predefinedPath, passable, side)
              , team(team)
              , defeatedDialog(defeatedDialog) {
            }

            TrainerEvent::~TrainerEvent() {
                delete(team);
            }

            TrainerEyesightEvent::TrainerEyesightEvent(TrainerEvent *trainer, sf::Vector2f position)
              : Event(alpha, EventTrigger::BE_IN, position, SIDE_ALL, true)
              , trainer(trainer) {
            }

            //Actions and updates

            void TPEvent::action(Model::Player &player, View::Overworld &overworld) {
                if(!justTP) {
                    overworld.tp(map, tpCoord);
                    //Sets the player's direction after the teleportation. If this->ppDir == -1, the old player position is kept
                    if(this->ppDir != -1) {
                        player.getPosition().setDir(this->ppDir);
                    }
                    justTP = true;
                }
            }

            void TPEvent::update(Model::Player &player, View::Overworld &overworld) {
            }

            void DoorEvent::action(Model::Player &player, View::Overworld &overworld) {
                //Starts the animation. The animation itself will be done in update()
                animStarted = 0;
                player.getPosition().lockMove();
                overworld.getData().getUiDataPtr()->getJukebox().playSound(doorType + " sound");
            }

            void DoorEvent::update(Model::Player &player, View::Overworld &overworld) {
                if(animStarted != -1) { //If true, action() has started the animation
                    ++animStarted;
                    if(animStarted < 8 && animStarted % 2 == 0) {
                        currentTexture = otherTextures.begin() + (animStarted / 2);
                    } else if(animStarted > 10) { //End of the animation
                        player.getPosition().unlockMove();
                        TPEvent::action(player, overworld);
                        animStarted = -1; //Resets the animation
                        currentTexture = otherTextures.begin();
                    }
                }
            }

            void TalkingEvent::action(Model::Player &player, View::Overworld &overworld) {
                overworld.startDialog(this->dialog);
            }

            void TalkingEvent::update(Model::Player &player, View::Overworld &overworld) {
            }

            void TalkingEvent::changeDialog(Utils::OpString newDialog) {
                dialogKey = newDialog;
                this->onLangChanged();
            }

            void CharacterEvent::update(Model::Player &player, View::Overworld &overworld) {
                frames++;
                if(!mapPos.isAnim()) { //Checks if not already moving
                    int randomMove;
                    switch(moveStyle) {
                    case MoveStyle::PREDEFINED: //Movement predefined during the npc's initialization
                        predefinedCounter++;
                        if(predefinedCounter >= movements.size()) { //TODO : Add the possibility of disabling the loop, for one-time movements
                            predefinedCounter = 0;
                        }

                        if(!move(movements[predefinedCounter], overworld.getData().getCurrentMap())) { //If the movement is impossible, decreases the counter to not ignore the movement.
                            if(predefinedCounter != 0) {
                                predefinedCounter--;
                            } else {
                                predefinedCounter = movements.size() - 1;
                            }
                        }
                        break;

                    case MoveStyle::NO_MOVE: //This is easy to do.
                        break;

                    case MoveStyle::RANDOM: //I don't think I will be using this often, but I keep it here, who knows?
                        randomMove = Utils::Misc::randUI(5) - 1;
                        switch(randomMove) {
                        case -1:
                            move(Side::NO_MOVE, overworld.getData().getCurrentMap());
                            break;
                        case 0:
                            move(Side::TO_UP, overworld.getData().getCurrentMap());
                            break;
                        case 1:
                            move(Side::TO_DOWN, overworld.getData().getCurrentMap());
                            break;
                        case 2:
                            move(Side::TO_LEFT, overworld.getData().getCurrentMap());
                            break;
                        case 3:
                            move(Side::TO_RIGHT, overworld.getData().getCurrentMap());
                            break;
                        default: //This would be weird
                            handleError("[WARNING] - Random number out of bounds CharacterEvent::update");
                            move(Side::NO_MOVE, overworld.getData().getCurrentMap());
                        }
                        break;

                    case MoveStyle::FOLLOWING:
                        //TODO
                        break;
                    }
                }
                //Changes the texture to print, handles the movement itself.
                if(mapPos.isAnim() && !anims && mapPos.getDir() != Side::STAY) { //First part of the animation
                    currentTexture = otherTextures.begin() + ((int)mapPos.getDir() + 4);
                    animsCounter++;
                    anims = animsCounter > 8;
                } else if(mapPos.isAnim() && anims && mapPos.getDir() != Side::STAY) { //Second part of the animation
                    currentTexture = otherTextures.begin() + ((int)mapPos.getDir() + 8);
                    animsCounter++;
                    if(animsCounter > 16) {
                        anims = false;
                        animsCounter = 0;
                    }
                } else if(!mapPos.isAnim()) { //The NPC is resting. With all these movements, maybe it's tired.
                    currentTexture = otherTextures.begin() + (int)mapPos.getDir();
                }

                //This part moves the sprite's position
                if(mapPos.isAnim()) {
                    sf::Vector2f toMove;
                    switch(mapPos.getDir()) {
                    case Side::TO_UP:
                        toMove = sf::Vector2f(0, -4);
                        break;

                    case Side::TO_DOWN:
                        toMove = sf::Vector2f(0, 4);
                        break;

                    case Side::TO_LEFT:
                        toMove = sf::Vector2f(4, 0);
                        break;

                    case Side::TO_RIGHT:
                        toMove = sf::Vector2f(-4, 0);
                        break;
                    default:
                        break;
                    }
                    if(mapPos.isMoving())
                        position -= toMove;
                    if(frames - startFrames >= 7)
                        mapPos.stopMove();
                }
            }

            bool CharacterEvent::move(Side direction, Map *map) {
                startFrames = frames;
                return mapPos.move(direction, map);
            }

            void CharacterEvent::move(Side direction, Model::Player &player, View::Overworld &overworld) {
                move(direction, overworld.getData().getCurrentMap());
            }

            void TalkingCharaEvent::action(Model::Player &player, View::Overworld &overworld) {
                mapPos.lockMove();
                talking = true;
            }

            void TalkingCharaEvent::update(Model::Player &player, View::Overworld &overworld) {
                CharacterEvent::update(player, overworld);
                if(talking && !mapPos.isAnim()) {           //Talking is set by "action".
                    switch(player.getPosition().getDir()) { //Put the character's face in front of the player's one
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
                    //Put the correct texture to the NPC
                    currentTexture = otherTextures.begin() + (int)mapPos.getDir();
                    updateTexture();
                    mapPos.unlockMove();
                    talking = false;
                    overworld.startDialog(this->dialog);
                }
            }

            void CharacterEvent::setPredefinedMove(std::vector<Side> moves) {
                this->movements = moves;
            }

            void LockedDoorEvent::action(Model::Player &player, View::Overworld &overworld) {
            }

            void LockedDoorEvent::update(Model::Player &player, View::Overworld &overworld) {
            }

            void TrainerEvent::action(Model::Player &player, View::Overworld &overworld) {
                TalkingCharaEvent::action(player, overworld);
            }

            void TrainerEvent::update(Model::Player &player, View::Overworld &overworld) {
                if(triggerBattle) {
                    triggerBattle = false;
                    overworld.declareBattle(this);
                }
                if(!defeated) {
                    if(talking && !checkTalking) {
                        checkTalking = true;
                    }
                    if(!talking && checkTalking) {
                        triggerBattle = true;
                    }
                }
                TalkingCharaEvent::update(player, overworld);
            }

            void TrainerEvent::defeat() {
                defeated = true;
                this->changeDialog(defeatedDialog);
            }

            Utils::OpString LockedDoorEvent::keysLock = Utils::OpString();

        } // namespace Events

    } // namespace Model
} // namespace OpMon
#pragma GCC diagnostic pop
