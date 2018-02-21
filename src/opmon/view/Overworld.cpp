#include "Overworld.hpp"
#include "../model/objects/Enums.hpp"
#include "../start/Initializer.hpp"

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
            jukebox.play(mus);
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

        void Overworld::printElements(sf::RenderTexture &frame) {
            for(std::string const &i : current->getAnimatedElements()) {
                Model::Data::Elements::elementsCounter[i]++;
                if(Model::Data::Elements::elementsCounter[i] >= (int)Model::Data::Elements::elementsTextures[i].size()) {
                    Model::Data::Elements::elementsCounter[i] = 0;
                }
                Model::Data::Elements::elementsSprites[i].setTexture(Model::Data::Elements::elementsTextures[i][Model::Data::Elements::elementsCounter[i]]);
                Model::Data::Elements::elementsSprites[i].setPosition(Model::Data::Elements::elementsPos[i]);
                frame.draw(Model::Data::Elements::elementsSprites[i]);
            }
        }

        void Overworld::tp(std::string toTp, sf::Vector2i pos) {
            Model::Data::player.tp(toTp, pos);
            current = Model::Data::World::maps.at(Model::Data::player.getMapId());
            character.setPosition(pos.x SQUARES - 16, pos.y SQUARES);
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
            jukebox.pause(current->getBg());
        }

        void Overworld::play() {
            jukebox.play(current->getBg());
        }

        Overworld::Overworld(const std::string &mapId) {
            current = Model::Data::World::maps[mapId];
            character.setTexture(Model::Data::Ui::texturePP[(int)Side::TO_DOWN]);
            Model::Data::player.tp(mapId, sf::Vector2i(2, 2));
            character.setPosition(2 SQUARES - 16, 2 SQUARES);
            camera.setCenter(this->getCharacter().getPosition());
            camera.setSize(sf::Vector2f(16 SQUARES, 16 SQUARES));

            setMusic(current->getBg());
            layer1 = new MapLayer(current->getDimensions(), current->getLayer1());
            layer2 = new MapLayer(current->getDimensions(), current->getLayer2());
            layer3 = new MapLayer(current->getDimensions(), current->getLayer3());
            character.setScale(2, 2);
            character.setOrigin(16, 16);

            posArrow = View::frame.mapPixelToCoords(sf::Vector2i(512 - 75, 512 - 30));
            Dialog::arrDial.setPosition(posArrow);

            jukebox.play(current->getBg());

            View::frame.setView(camera);
            window.setKeyRepeatEnabled(true);

            OpMon::I18n::Translator::getInstance().setLang(OpMon::I18n::Translator::getInstance().getLang());
        }

        Overworld::~Overworld() {
            jukebox.stop(current->getBg());
            delete(layer1);
            delete(layer2);
            delete(layer3);
        }

        GameStatus Overworld::operator()(int frames) {
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
            /*
	In the bloc, every commented line must be moved in GameLoop
      */
            if(debugMode) {
                cout << "[FRAME Nｰ" << frames << "]" << endl;
                cout << "Boucle : " << (is_in_dialog ? "Normale" : "Dialog") << endl;
                cout << "Tick: " << Utils::Time::getElapsedMilliseconds() << "ms" << endl;
                cout << "PlayerPosition: " << Model::Data::player.getPosition().getPosition().x << " - " << Model::Data::player.getPosition().getPosition().y << endl;
                cout << "PlayerPositionPx: " << character.getPosition().x << " - " << character.getPosition().y << endl;
                cout << "Moving: " << (Model::Data::player.getPosition().isMoving() ? "true" : "false") << endl;
                cout << "Anim: " << (Model::Data::player.getPosition().isAnim() ? "true" : "false") << endl;
                cout << "PlayerDirection: " << (int)Model::Data::player.getPosition().getDir() << endl;
                cout << "Start Frames : " << startFrames << endl;

                debugText.setString("Debug mode");
                debugText.setPosition(View::frame.mapPixelToCoords(sf::Vector2i(0, 0)));
                debugText.setFont(Model::Data::Ui::font);
                debugText.setColor(sf::Color(127, 127, 127));
                debugText.setCharacterSize(40);
                fpsPrint.setPosition(View::frame.mapPixelToCoords(sf::Vector2i(0, 50)));
                fpsPrint.setFont(Model::Data::Ui::font);
                //fpsPrint.setColor(sf::Color(127, 127, 127));
                fpsPrint.setCharacterSize(48);
                std::ostringstream oss;
                oss << "Position : " << Model::Data::player.getPosition().getPosition().x << " - " << Model::Data::player.getPosition().getPosition().y << endl
                    << "PxPosition : " << character.getPosition().x << " - " << character.getPosition().y << endl;
                coordPrint.setString(oss.str());
                coordPrint.setFont(Model::Data::Ui::font);
                coordPrint.setPosition(View::frame.mapPixelToCoords(sf::Vector2i(0, 100)));
                coordPrint.setColor(sf::Color(127, 127, 127));
                coordPrint.setCharacterSize(30);
            }

            View::frame.clear(sf::Color::Black);
            //Drawing the two first layers
            if((debugMode ? printlayer[0] : true)) {
                View::frame.draw(*layer1);
            }
            if((debugMode ? printlayer[1] : true)) {
                View::frame.draw(*layer2);
            }
            //Drawing events under the player
            for(Model::Event *event : current->getEvents()) {
                const sf::Sprite *sprite = event->getSprite();
                event->updateTexture();
                if(sprite->getPosition().y <= Model::Data::player.getPosition().getPositionPixel().y) {
                    View::frame.draw(*sprite);
                }
            }

            //Sets the character's texture.
            if(Model::Data::player.getPosition().isAnim() && !anims) {
                character.setTexture(Model::Data::Ui::walkingPP[(int)Model::Data::player.getPosition().getDir()]);
                animsCounter++;
                anims = animsCounter > 8;

            } else if(Model::Data::player.getPosition().isAnim() && anims) {
                character.setTexture(Model::Data::Ui::walkingPP2[(int)Model::Data::player.getPosition().getDir()]);
                animsCounter++;
                if(animsCounter > 16) {
                    anims = false;
                    animsCounter = 0;
                }
            } else if(!Model::Data::player.getPosition().isAnim()) {
                character.setTexture(Model::Data::Ui::texturePP[(int)Model::Data::player.getPosition().getDir()]);
            }
            //Drawing character
            View::frame.draw(character);
            //Drawing the events above the player
            for(Model::Event *event : current->getEvents()) {
                const sf::Sprite *sprite = event->getSprite();
                event->updateTexture();
                if(sprite->getPosition().y > Model::Data::player.getPosition().getPositionPixel().y) {
                    View::frame.draw(*sprite);
                }
            }

            //Drawing the third layer
            if((debugMode ? printlayer[2] : true)) {
                View::frame.draw(*layer3);
            }
            if(scrolling && !camUnlock) {
                camera.setCenter(character.getPosition().x + 16, character.getPosition().y + 16);
            }
            View::frame.setView(View::frame.getDefaultView());
            View::frame.setView(camera);
            printElements(View::frame);

            if(is_in_dialog) {
                this->dialog->updateTextAnimation();
                this->dialog->draw(View::frame);
            } else if(Model::Data::player.getPosition().isAnim()) {
                if(Model::Data::player.getPosition().isMoving()) {
                    switch(Model::Data::player.getPosition().getDir()) {
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
                    Model::Data::player.getPosition().stopMove();
                }
            }

            if(debugMode) {
                if(printCollisions) {
                    printCollisionLayer(View::frame);
                }
                View::frame.draw(debugText);
                View::frame.draw(fpsPrint);
                View::frame.draw(coordPrint);
            }

            //Refresh to do in GameLoop

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
              {5, sf::Color(255, 255, 255, 128)},
              {5, sf::Color(255, 255, 255, 128)},
              {5, sf::Color(255, 255, 255, 128)}};

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

            // `&dialogs[0]` converts the std::vector into a regular array.
            this->dialog = new Dialog(&dialogs[0], dialogs.size());
        }
    } // namespace View

} // namespace OpMon
