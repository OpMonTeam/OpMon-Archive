/*
  Overworld.cpp
  Author : Cyrielle
  Contributors : BAKFR, torq, Navet56
  File under GNU GPL v3.0 license
*/

#define FPS_TICKS 33

#include "Overworld.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

#include "Enums.hpp"
#include "defines.hpp"
#include "log.hpp"
#include "time.hpp"
#include "Translator.hpp"
#include "Dialog.hpp"
#include "GameStatus.hpp"
#include "Player.hpp"
#include "GameData.hpp"
#include "OverworldData.hpp"
#include "Map.hpp"
#include "Position.hpp"
#include "Elements.hpp"
#include "Jukebox.hpp"

namespace OpMon {

    void Overworld::setMusic(std::string const &mus) {
        data.getGameDataPtr()->getJukebox().play(mus);
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

    void Overworld::updateCamera() {
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
    }

    void Overworld::updateElements() {
        //"i" is the element's id
        for(std::string const &i : current->getAnimatedElements()) {
            data.incrementElementCounter(i);
            if(data.getElementCounter(i) >= data.getElementTextures(i).size()) {
                data.resetElementCounter(i);
            }
            elementsSprites[i].setTexture(data.getCurrentElementTexture(i));
            elementsSprites[i].setPosition(data.getElementPos(i));
        }
    }

    void Overworld::printElements(sf::RenderTarget &frame) const {
        //"i" is the element's id
        for(std::string const &i : current->getAnimatedElements()) {
            frame.draw(elementsSprites.at(i));
        }
    }

    void Overworld::tp(std::string toTp, sf::Vector2i pos) {
        data.getPlayer().tp(toTp, pos);
        current = data.getCurrentMap();
        character.setPosition(pos.x SQUARES - 16, pos.y SQUARES);
        resetCamera();
        setMusic(current->getBg());

        //Recreates the layers
        layer1 = std::make_unique<Ui::MapLayer>(current->getDimensions(), current->getLayer1(), data.getTileset(current->getTileset()));
        layer2 = std::make_unique<Ui::MapLayer>(current->getDimensions(), current->getLayer2(), data.getTileset(current->getTileset()));
        layer3 = std::make_unique<Ui::MapLayer>(current->getDimensions(), current->getLayer3(), data.getTileset(current->getTileset()));
    }

    void Overworld::pause() {
        data.getGameDataPtr()->getJukebox().pause();
    }

    void Overworld::play() {
        data.getGameDataPtr()->getJukebox().play(current->getBg());
    }

    Overworld::Overworld(const std::string &mapId, OverworldData &data)
        : data(data) {
        current = data.getMap(mapId);
        character.setTexture(data.getTexturePP());
        character.setTextureRect(data.getTexturePPRect((unsigned int)Side::TO_DOWN));
        data.getPlayer().tp(mapId, sf::Vector2i(2, 4)); //TODO : Add a parameter to configure the default player's position
        character.setPosition(2 SQUARES - 16, 4 SQUARES);
        camera.setSize(sf::Vector2f(30 SQUARES, 16.875 SQUARES));
        resetCamera();

        setMusic(current->getBg());
        layer1 = std::make_unique<Ui::MapLayer>(current->getDimensions(), current->getLayer1(), data.getTileset(current->getTileset()));
        layer2 = std::make_unique<Ui::MapLayer>(current->getDimensions(), current->getLayer2(), data.getTileset(current->getTileset()));
        layer3 = std::make_unique<Ui::MapLayer>(current->getDimensions(), current->getLayer3(), data.getTileset(current->getTileset()));
        character.setScale(2, 2);
        character.setOrigin(16, 16);

        data.getGameDataPtr()->getJukebox().play(current->getBg());

        Utils::I18n::Translator::getInstance().setLang(Utils::I18n::Translator::getInstance().getLang());
    }

    void Overworld::draw(sf::RenderTarget &frame, sf::RenderStates states) const {
        bool is_in_dialog = this->dialog && !this->dialog->isDialogOver();
        frame.setView(camera);
        frame.clear(sf::Color::Black);

        //Drawing the two first layers
        if((debugMode ? printlayer[0] : true)) {
            frame.draw(*layer1);
        }
        if((debugMode ? printlayer[1] : true)) {
            frame.draw(*layer2);
        }
        //Drawing events under the player
        for(const Elements::AbstractEvent *event : current->getEvents()) {
            const sf::Sprite *sprite = event->getSprite();
            if(sprite->getPosition().y <= data.getPlayer().getPosition().getPositionPixel().y) {
                frame.draw(*sprite);
            }
        }

        frame.draw(character);

        //Drawing the events above the player
        for(const Elements::AbstractEvent *event : current->getEvents()) {
            const sf::Sprite *sprite = event->getSprite();
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
            frame.draw(*this->dialog);
        }

        if(debugMode) {
            frame.draw(debugText);
            frame.draw(fpsPrint);
            frame.draw(coordPrint);
        }
    }

    GameStatus Overworld::update() {
        bool is_in_dialog = this->dialog && !this->dialog->isDialogOver();

        if(initPlayerAnimation) {
            startPlayerAnimationTime = Utils::Time::getElapsedMilliseconds();
            initPlayerAnimation = false;
        }

        fpsCounter++;
        if(Utils::Time::getElapsedMilliseconds() - oldTicksFps >= 1000) {
            fpsPrint.setString(std::to_string(fpsCounter));
            fpsCounter = 0;
            oldTicksFps = Utils::Time::getElapsedMilliseconds();
        }

        if(debugMode) {
            std::cout << "Elapsed Time: " << Utils::Time::getElapsedSeconds() << "s" << std::endl;
            std::cout << "Loop : " << (is_in_dialog ? "Dialog" : "Normal") << std::endl;
            std::cout << "PlayerPosition: " << data.getPlayer().getPosition().getPosition().x << " - " << data.getPlayer().getPosition().getPosition().y << std::endl;
            std::cout << "PlayerPositionPx: " << character.getPosition().x << " - " << character.getPosition().y << std::endl;
            std::cout << "Moving: " << (data.getPlayer().getPosition().isMoving() ? "true" : "false") << std::endl;
            std::cout << "Anim: " << (data.getPlayer().getPosition().isAnim() ? "true" : "false") << std::endl;
            std::cout << "PlayerDirection: " << (int)data.getPlayer().getPosition().getDir() << std::endl;
            std::cout << "Start player Animation Time: " << (double)startPlayerAnimationTime / 1000 << std::endl;

            debugText.setString("Debug mode");
            debugText.setPosition(0, 0);
            debugText.setFont(data.getGameDataPtr()->getFont());
            debugText.setSfmlColor(sf::Color(127, 127, 127));
            debugText.setCharacterSize(40);
            fpsPrint.setPosition(0, 50);
            fpsPrint.setFont(data.getGameDataPtr()->getFont());
            fpsPrint.setCharacterSize(48);
            std::ostringstream oss;
            oss << "Position : " << data.getPlayer().getPosition().getPosition().x << " - " << data.getPlayer().getPosition().getPosition().y << std::endl
                << "PxPosition : " << character.getPosition().x << " - " << character.getPosition().y << std::endl;
            coordPrint.setString(oss.str());
            coordPrint.setFont(data.getGameDataPtr()->getFont());
            coordPrint.setPosition(0, 100);
            coordPrint.setSfmlColor(sf::Color(127, 127, 127));
            coordPrint.setCharacterSize(30);
        }

        if(is_in_dialog) {
            this->dialog->updateTextAnimation();
        }

        updateCamera();

        //Drawing events under the player
        for(Elements::AbstractEvent *event : current->getEvents()) {
            event->updateTexture();
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
        }

        //Sets the character's texture.
        if(data.getPlayer().getPosition().isAnim() && !anims) {
            character.setTextureRect(data.getWalkingPPRect((unsigned int)data.getPlayer().getPosition().getDir()));
            anims = animsCounter >= 8;
            if(anims) {
                //Stops the caracter's movement every 8 frames
                data.getPlayer().getPosition().stopMove();
                animsCounter = 0;
            }
            animsCounter++;

        } else if(data.getPlayer().getPosition().isAnim() && anims) {
            character.setTextureRect(data.getWalkingPP2Rect((unsigned int)data.getPlayer().getPosition().getDir()));
            if(animsCounter >= 8) {
                //Stops the caracter's movement every 8 frames
                data.getPlayer().getPosition().stopMove();
                anims = false;
                animsCounter = 0;
            }
            animsCounter++;
        } else if(!data.getPlayer().getPosition().isAnim()) {
            character.setTextureRect(data.getTexturePPRect((unsigned int)data.getPlayer().getPosition().getDir()));
        }

        //Drawing the events above the player
        for(Elements::AbstractEvent *event : current->getEvents()) {
            event->updateTexture();
        }

        updateElements();

        return GameStatus::CONTINUE;
    }

    void Overworld::printCollisionLayer(sf::RenderTarget &frame) const {
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
    void Overworld::startDialog(sf::String const &dialog) {
        if(this->dialog) {
            if(!this->dialog->isDialogOver()) {
                Utils::Log::oplog("WARNING: We create a new dialog ... but the last one isn't finished yet!", true);
            }
            this->dialog = nullptr;
        }

        this->dialog = std::make_unique<Ui::Dialog>(dialog, data.getGameDataPtr());
    }

} // namespace OpMon
