#include "CharacterEvent.hpp"

#include "src/opmon/screens/overworld/Overworld.hpp"
#include "src/utils/misc.hpp"

#define ANIM_1 0
#define ANIM_2 4
#define STAND_STILL 8

namespace OpMon {
    namespace Elements {

        CharacterEvent::CharacterEvent(sf::Texture &texture,
                                       std::vector<sf::IntRect> rectangles,
                                       sf::Vector2f const &position,
                                       Side posDir, MoveStyle moveStyle,
                                       EventTrigger eventTrigger,
                                       std::vector<Side> predefinedPath,
                                       bool passable, int sides)
            : AbstractEvent(texture, rectangles, eventTrigger, position, sides,
                            passable),
              moveStyle(moveStyle) {
            sprite->setScale(2, 2);
            sprite->setOrigin(16, 16);
            this->position += sf::Vector2f(16, 0);
            setPredefinedMove(predefinedPath);
            mapPos.setDir(posDir);
            currentFrame = rectangles.begin();
        }

        CharacterEvent::CharacterEvent(OverworldData &data,
                                       nlohmann::json jsonData)
            : AbstractEvent(data, jsonData),
              moveStyle(jsonData.value("moveStyle", MoveStyle::NO_MOVE)) {
            sprite->setScale(2, 2);
            sprite->setOrigin(16, 16);
            this->position += sf::Vector2f(16, 0);

            // Initialization of path
            std::vector<std::vector<int>> prePath =
                jsonData.value("path", std::vector<std::vector<int>>());
            std::vector<Side> charaPath;
            if(!prePath.empty()) {
                nlohmann::json prePathJson = jsonData.at("path");
                for(auto pitor = prePathJson.begin();
                    pitor != prePathJson.end(); ++pitor) {
                    for(unsigned int r = 0; r < pitor->at(1); r++) {
                        charaPath.push_back(pitor->at(0));
                    }
                }
            }
            setPredefinedMove(charaPath);
            mapPos.setDir(jsonData.value("facing", Side::TO_DOWN));

            // Initialization of rectangles
            rectangles.clear();
            for(unsigned int i = 0; i < 12; i++) {
                rectangles.push_back(
                    sf::IntRect((i * 32) % 128, (i / 4) * 32, 32, 32));
            }
            currentFrame = rectangles.begin();
        }

        void CharacterEvent::update(Overworld &overworld) {
            frames++;
            if(!mapPos.isAnim()) { // Checks if not already moving
                int randomMove;
                switch(moveStyle) {
                    case MoveStyle::PREDEFINED: // Movement predefined during
                                                // the npc's initialization
                        predefinedCounter++;
                        if(predefinedCounter >=
                           movements.size()) { // TODO : Add the possibility of
                                               // disabling the loop, for
                                               // one-time movements
                            predefinedCounter = 0;
                        }

                        if(!move(
                               movements[predefinedCounter],
                               overworld.getData()
                                   .getCurrentMap())) { // If the movement is
                                                        // impossible, decreases
                                                        // the counter to not
                                                        // ignore the movement.
                            if(predefinedCounter != 0) {
                                predefinedCounter--;
                            } else {
                                predefinedCounter = movements.size() - 1;
                            }
                        }
                        break;

                    case MoveStyle::NO_MOVE: // This is easy to do.
                        break;

                    case MoveStyle::RANDOM: // I don't think I will be using
                                            // this often, but I keep it here,
                                            // who knows?
                        randomMove = Utils::Misc::randUI(5) - 1;
                        try {
                            switch(randomMove) {
                                case -1:
                                    move(Side::NO_MOVE,
                                         overworld.getData().getCurrentMap());
                                    break;
                                case 0:
                                    move(Side::TO_UP,
                                         overworld.getData().getCurrentMap());
                                    break;
                                case 1:
                                    move(Side::TO_DOWN,
                                         overworld.getData().getCurrentMap());
                                    break;
                                case 2:
                                    move(Side::TO_LEFT,
                                         overworld.getData().getCurrentMap());
                                    break;
                                case 3:
                                    move(Side::TO_RIGHT,
                                         overworld.getData().getCurrentMap());
                                    break;
                                default:
                                    throw Utils::UnexpectedValueException(
                                        std::to_string(randomMove),
                                        "an integer in [-1,3] representing a "
                                        "random movement in "
                                        "CharacterEvent::update");
                            }
                        } catch(Utils::UnexpectedValueException &e) {
                            if(e.fatal)
                                throw;
                            Utils::Log::oplog(e.desc(), true);
                            move(Side::NO_MOVE,
                                 overworld.getData().getCurrentMap());
                        }
                        break;

                    case MoveStyle::FOLLOWING:
                        // TODO
                        break;
                }
            }
            // Changes the texture to print, handles the movement itself.
            if(mapPos.isAnim() && !anims &&
               mapPos.getDir() != Side::STAY) { // First part of the animation
                currentFrame =
                    rectangles.begin() + ((int)mapPos.getDir() + ANIM_1);
                animsCounter++;
                anims = animsCounter > 8;
            } else if(mapPos.isAnim() && anims &&
                      mapPos.getDir() !=
                          Side::STAY) { // Second part of the animation
                currentFrame =
                    rectangles.begin() + ((int)mapPos.getDir() + ANIM_2);
                animsCounter++;
                if(animsCounter > 16) {
                    anims = false;
                    animsCounter = 0;
                }
            } else if(!mapPos.isAnim()) { // The NPC is resting. With all these
                                          // movements, maybe they're tired.
                currentFrame =
                    rectangles.begin() + ((int)mapPos.getDir() + STAND_STILL);
            }

            // This part moves the sprite's position
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
                        toMove = sf::Vector2f(-4, 0);
                        break;

                    case Side::TO_RIGHT:
                        toMove = sf::Vector2f(4, 0);
                        break;
                    default:
                        break;
                }
                if(mapPos.isMoving())
                    position += toMove;
                if(frames - startFrames >= 8)
                    mapPos.stopMove();
            }
            if(wantmove && !mapPos.isAnim()) {
                switch(overworld.getCharacter()
                           .getPositionMap()
                           .getDir()) { // Put the character's face in front of
                                        // the player's one
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
                // Put the correct texture to the NPC
                currentFrame =
                    rectangles.begin() + ((int)mapPos.getDir() + STAND_STILL);
                updateFrame();
                wantmove = false;
            }
        }

        bool CharacterEvent::move(Side direction, Map *map) {
            startFrames = frames;
            return mapPos.move(direction, map);
        }

        void CharacterEvent::move(Side direction, Overworld &overworld) {
            move(direction, overworld.getData().getCurrentMap());
        }

        void CharacterEvent::setPredefinedMove(std::vector<Side> moves) {
            this->movements = moves;
        }

        void CharacterEvent::setPosition(sf::Vector2i pos) {
            AbstractEvent::setPosition(pos);
            this->position += sf::Vector2f(16, 0);
        }

    } /* namespace Elements */
} /* namespace OpMon */
