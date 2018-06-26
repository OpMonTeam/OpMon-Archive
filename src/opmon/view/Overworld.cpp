
#include "Overworld.hpp"
#include "../model/objects/Enums.hpp"
#include "../start/Initializer.hpp"
#include <algorithm>

#define FPS_TICKS 33
#include "../../utils/defines.hpp"
#include "../../utils/log.hpp"
#include "../../utils/time.hpp"
#include "../model/storage/Data.hpp"
#include "../model/sysObjects/Events.hpp"
#include "../start/Core.hpp"
#include "../start/i18n/Translator.hpp"
#include "Dialog.hpp"
#include "Window.hpp"
#include <cmath>
#include <map>
#include <sstream>
#ifndef _WIN32

//#define DEBUG_REPORT

#endif

UNS using OpMon::Model::Side;

namespace OpMon {
    namespace View {

        void Overworld::setMusic(std::string const &mus) {
            data.getUiDataPtr()->getJukebox().play(mus);
        }

        bool Overworld::isCameraLocked() {
            return cameraLock;
        }

        void Overworld::setCameraLock(bool locked) {
            cameraLock = locked;
        }

        void Overworld::moveCamera(Side dir) {
            switch(dir) {
            case Side::TO_UP:
                camera.move(0, -4);
                break;
            case Side::TO_DOWN:
                camera.move(0, 4);
                break;
            case Side::TO_LEFT:
                camera.move(-4, 0);
                break;
            case Side::TO_RIGHT:
                camera.move(4, 0);
                break;
            default:
                break;
            }
        }

        void Overworld::updateCamera(sf::RenderTarget &frame) {
            frame.setView(camera);
            if(cameraLock)
                return;

            // Note: character is already center on itself:
            // character.getPosition() returns the center of the player's sprite
            const sf::Vector2f &playerPos = character.getPosition();
            const sf::Vector2f &cameraSize = camera.getSize();
            const sf::Vector2i mapSize = current->getDimensions() * 32;

            sf::Vector2f center = camera.getCenter();

            // Only move the camera when the player moves away from the center. "coef" determines the liberty given to
            // the player. a coefficient of 0 means the camera is always centered on the player. a coefficient of 1
            // allows the player to reach the screen borders.
            float coef = 0.25;

            // Prevent the camera to display too much void outside the map dimensions. 0 has no restriction; 1 means
            // the camera never display any black zone. A value of 0.7 means the camera can't display more than 30% of
            // out-of-map zone.
            float nearBorderCoef = current->isIndoor() ? 0.7f : 1;

            if(cameraSize.x * 0.9 > mapSize.x) {
                center.x = (float)mapSize.x / 2;
            } else {
                // center around the player
                center.x = std::max(center.x, playerPos.x - (cameraSize.x * coef / 2.f));
                center.x = std::min(center.x, playerPos.x + (cameraSize.x * coef / 2.f));

                // avoid displaying too much out-of-map zone.
                center.x = std::max(center.x, cameraSize.x * nearBorderCoef / 2.f);
                center.x = std::min(center.x, (float)mapSize.x - (cameraSize.x * nearBorderCoef / 2.f));
            }
            if(cameraSize.y * 0.9 > mapSize.y) {
                center.y = (float)mapSize.y / 2;
            } else {
                // center around the player
                center.y = std::max(center.y, playerPos.y - (cameraSize.y * coef / 2.f));
                center.y = std::min(center.y, playerPos.y + (cameraSize.y * coef / 2.f));

                // avoid displaying too much out-of-map zone.
                center.y = std::max(center.y, cameraSize.y * nearBorderCoef / 2.f);
                center.y = std::min(center.y, (float)mapSize.y - (cameraSize.y * nearBorderCoef / 2.f));
            }
            camera.setCenter(center);
        }

        void Overworld::resetCamera() {
            camera.setCenter(character.getPosition());
            updateCamera(frame);
        }

        void Overworld::printElements(sf::RenderTexture &frame) {
            for(std::string const &i : current->getAnimatedElements()) {
	      data.incrementElementCounter(i);
	      if(data.getElementCounter(i) >= data.getElementTextures(i).size()) {
		data.resetElementCounter(i);
	      }
	      elementsSprites[i].setTexture(data.getCurrentElementTexture(i));
	      elementsSprites[i].setPosition(data.getElementPos(i));
	      frame.draw(elementsSprites[i]);
            }
        }

        void Overworld::tp(std::string toTp, sf::Vector2i pos) {
	  data.getPlayer().tp(toTp, pos);
	  current = data.getCurrentMap();
            character.setPosition(pos.x SQUARES - 16, pos.y SQUARES);
            resetCamera();
            if(musicPath != current->getBg()) {
                setMusic(current->getBg());
            }

            delete(layer1);
            delete(layer2);
            delete(layer3);
            layer1 = new MapLayer(current->getDimensions(), current->getLayer1());
            layer2 = new MapLayer(current->getDimensions(), current->getLayer2());
            layer3 = new MapLayer(current->getDimensions(), current->getLayer3());
            tpCount = 0;

            /*
      for(auto itor = current->getEvents().begin(); itor != current->getEvents().end(); ++itor){
        eventsSprites.try_emplace(itor, new sf::Sprite());
        eventsSprites[itor].setPosition();
        eventsSprites[itor].setTexture(itor->getTexture());
      }
       */
        }

        void Overworld::pause() {
            data.getUiDataPtr()->getJukebox().pause(current->getBg());
        }

        void Overworld::play() {
	  data.getUiDataPtr()->getJukebox().play(current->getBg());
        }

      Overworld::Overworld(const std::string &mapId, Model::OverworldData& data)
	: data(data) {
	current = data.getMap(mapId);
	character.setTexture(data.getTexturePP((unsigned int)Side::TO_DOWN));
	data.getPlayer().tp(mapId, sf::Vector2i(2, 4));
            character.setPosition(2 SQUARES - 16, 4 SQUARES);
            camera.setSize(sf::Vector2f(16 SQUARES, 16 SQUARES));
            resetCamera();

            setMusic(current->getBg());
            layer1 = new MapLayer(current->getDimensions(), current->getLayer1());
            layer2 = new MapLayer(current->getDimensions(), current->getLayer2());
            layer3 = new MapLayer(current->getDimensions(), current->getLayer3());
            character.setScale(2, 2);
            character.setOrigin(16, 16);

            data.getUiDataPtr()->getJukebox().play(current->getBg());

            OpMon::I18n::Translator::getInstance().setLang(OpMon::I18n::Translator::getInstance().getLang());
        }

        Overworld::~Overworld() {
            data.getUiDataPtr()->getJukebox().stop(current->getBg());
            delete(layer1);
            delete(layer2);
            delete(layer3);
        }
      GameStatus Overworld::operator()(int frames, sf::RenderTexture& frame) {
            bool is_in_dialog = this->dialog && !this->dialog->isDialogOver();

            if(recordFrames) {
                recordFrames = false;
                startFrames = frames;
            }

            fpsCounter++;
            if(Utils::Time::getElapsedMilliseconds() - oldTicksFps >= 1000) {
                fpsPrint.setString(std::to_string(fpsCounter));
                fpsCounter = 0;
                oldTicksFps = Utils::Time::getElapsedMilliseconds();
            }

            sf::Text debugText;
            if(debugMode) {
                cout << "[FRAME Nｰ" << frames << "]" << endl;
                cout << "Loop : " << (is_in_dialog ? "Dialog" : "Normal") << endl;
                cout << "Tick: " << Utils::Time::getElapsedMilliseconds() << "ms" << endl;
                cout << "PlayerPosition: " << data.getPlayer().getPosition().getPosition().x << " - " << data.getPlayer().getPosition().getPosition().y << endl;
                cout << "PlayerPositionPx: " << character.getPosition().x << " - " << character.getPosition().y << endl;
                cout << "Moving: " << (data.getPlayer().getPosition().isMoving() ? "true" : "false") << endl;
                cout << "Anim: " << (data.getPlayer().getPosition().isAnim() ? "true" : "false") << endl;
                cout << "PlayerDirection: " << (int)data.getPlayer().getPosition().getDir() << endl;
                cout << "Start Frames : " << startFrames << endl;

                debugText.setString("Debug mode");
                debugText.setPosition(0, 0);
                debugText.setFont(data.getUiData()->getFont());
                debugText.setColor(sf::Color(127, 127, 127));
                debugText.setCharacterSize(40);
                fpsPrint.setPosition(0, 50);
                fpsPrint.setFont(data.getUiData()->getFont());
                //fpsPrint.setColor(sf::Color(127, 127, 127));
                fpsPrint.setCharacterSize(48);
                std::ostringstream oss;
                oss << "Position : " << data.getPlayer().getPosition().getPosition().x << " - " << data.getPlayer().getPosition().getPosition().y << endl
                    << "PxPosition : " << character.getPosition().x << " - " << character.getPosition().y << endl;
                coordPrint.setString(oss.str());
                coordPrint.setFont(data.getUiData()->getFont());
                coordPrint.setPosition(0, 100);
                coordPrint.setColor(sf::Color(127, 127, 127));
                coordPrint.setCharacterSize(30);
            }

            if(is_in_dialog) {
                this->dialog->updateTextAnimation();
            }

            /**** draw ****/

            updateCamera(frame);
            frame.clear(sf::Color::Black);

            //Drawing the two first layers
            if((debugMode ? printlayer[0] : true)) {
                frame.draw(*layer1);
            }
            if((debugMode ? printlayer[1] : true)) {
                frame.draw(*layer2);
            }
            //Drawing events under the player
            for(Model::Event *event : current->getEvents()) {
                const sf::Sprite *sprite = event->getSprite();
                event->updateTexture();
                if(sprite->getPosition().y <= data.getPlayer().getPosition().getPositionPixel().y) {
                    frame.draw(*sprite);
                }
            }

            //Sets the character's texture.
            if(data.getPlayer().getPosition().isAnim() && !anims) {
	      character.setTexture(data.getWalkingPP((unsigned int)data.getPlayer().getPosition().getDir()));
                animsCounter++;
                anims = animsCounter > 8;

            } else if(data.getPlayer().getPosition().isAnim() && anims) {
	      character.setTexture(data.getWalkingPP2((unsigned int)data.getPlayer().getPosition().getDir()));
                animsCounter++;
                if(animsCounter > 16) {
                    anims = false;
                    animsCounter = 0;
                }
            } else if(!data.getPlayer().getPosition().isAnim()) {
	      character.setTexture(data.getTexturePP((unsigned int)data.getPlayer().getPosition().getDir()));
            }

            if(!is_in_dialog && data.getPlayer().getPosition().isAnim()) {
                if(data.getPlayer().getPosition().isMoving()) {
                    switch(data.getPlayer().getPosition().getDir()) {
                    case Side::TO_UP:
                        character.move(0, -4);
                        break;
                    case Side::TO_DOWN:
                        character.move(0, 4);
                        break;
                    case Side::TO_LEFT:
                        character.move(-4, 0);
                        break;
                    case Side::TO_RIGHT:
                        character.move(4, 0);
                        break;
                    default:
                        break;
                    }
                }
                if(frames - startFrames >= 7) {
                    data.getPlayer().getPosition().stopMove();
                }
            }

            //Drawing character
            frame.draw(character);
            //Drawing the events above the player
            for(Model::Event *event : current->getEvents()) {
                const sf::Sprite *sprite = event->getSprite();
                event->updateTexture();
                if(sprite->getPosition().y > data.getPlayer().getPosition().getPositionPixel().y) {
                    frame.draw(*sprite);
                }
            }

            if(debugMode && printCollisions) {
                printCollisionLayer(frame);
            }

            //Drawing the third layer
            if((debugMode ? printlayer[2] : true)) {
                frame.draw(*layer3);
            }

            printElements(frame);

            /***** draw GUI *****/
            frame.setView(frame.getDefaultView());

            if(is_in_dialog) {
                this->dialog->draw(frame);
            }

            if(debugMode) {
                frame.draw(debugText);
                frame.draw(fpsPrint);
                frame.draw(coordPrint);
            }

            return GameStatus::CONTINUE;
        }

        void Overworld::printCollisionLayer(sf::RenderTarget &frame) {
            sf::Vector2i pos;
            sf::RectangleShape tile({32, 32});
            std::map<int, sf::Color> collision2Color{
              {1, sf::Color(255, 0, 0, 128)},
              {2, sf::Color(0, 0, 255, 128)},
              {3, sf::Color(255, 255, 0, 128)},
              {4, sf::Color(255, 0, 255, 128)},
              {5, sf::Color(255, 255, 255, 128)},
              {6, sf::Color(255, 50, 0, 128)},
              {7, sf::Color(255, 50, 0, 128)},
              {8, sf::Color(255, 50, 0, 128)}};

            for(pos.x = 0; pos.x < current->getW(); ++pos.x) {
                for(pos.y = 0; pos.y < current->getH(); ++pos.y) {
                    int collision = current->getCollision(pos);
                    if(collision != 0) {
                        tile.setFillColor(collision2Color[collision]);
                        tile.setPosition(pos.x SQUARES, pos.y SQUARES);
                        frame.draw(tile);
                    }
                }
            }
        }

        /**
     * Events can call this method to start a new dialog with the player.
     */
        void Overworld::startDialog(std::vector<sf::String> const &dialogs) {
            if(this->dialog) {
                if(!this->dialog->isDialogOver()) {
                    Utils::Log::oplog("WARNING: We create a new dialog ... but the last one isn't finished yet!", true);
                }
                delete(this->dialog);
            }

            this->dialog = new Dialog(dialogs);
        }
    } // namespace View

} // namespace OpMon
