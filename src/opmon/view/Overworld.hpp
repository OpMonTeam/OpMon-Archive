/*
  Overworld.hpp
  Author : Jlppc
  File under the license GPL-3.0
  http://opmon-game.ga
  Contains Overworld namespace
*/
#ifndef OVERWORLD_HPP
#define OVERWORLD_HPP

#include "../model/objects/Enums.hpp"
#include "../model/sysObjects/Map.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../start/GameStatus.hpp"
#include "Dialog.hpp"
#include "Elements.hpp"

namespace OpMon {
    namespace View {

        class Overworld {
          public:
            Overworld(const std::string &mapId);

            sf::View &getCamera() {
                return camera;
            }

            sf::Sprite &getCharacter() {
                return character;
            }

            Model::Map *getCurrent() {
                return current;
            }

            GameStatus operator()(int frame);

            void tp(std::string toTp, sf::Vector2i pos);

            MapLayer *getMapLayer(int number) {
                switch(number) {
                case 1:
                    return layer1;
                case 2:
                    return layer2;
                case 3:
                    return layer3;
                default:
                    return nullptr;
                }
            }

            Dialog *getDialog() {
                return dialog;
            }

            void moveCamera(Model::Side dir);

            bool printlayer[3] = {true, true, true};
            bool printCollisions = false;

            bool justTp = false;

            virtual ~Overworld();

            virtual void play();
            virtual void pause();

            void setMusic(std::string const &path);

            /**
       * Events can call this method to start a new dialog with the player.
       */
            void startDialog(std::vector<sf::String> const &dialogs);

            void setStartFrames() {
                recordFrames = true;
            }

          private:
            void printElements(sf::RenderTexture &frame);

            void printCollisionLayer(sf::RenderTarget &frame);

            sf::View camera;
            sf::Sprite character;
            Model::Map *current = nullptr;

            std::string musicPath = "";

            MapLayer *layer1 = nullptr;
            MapLayer *layer2 = nullptr;
            MapLayer *layer3 = nullptr;
            sf::Vector2f posArrow;
            Dialog *dialog = nullptr;
            //Indicate the frame of the walking animation that must be used.
            bool anims = false;

            int fpsCounter;
            sf::Text fpsPrint;
            sf::Text coordPrint;
            int oldTicksFps;

            int tpCount = 0;

            int startFrames = 0;
            int animsCounter = 0;
            bool recordFrames = false;

            bool movementLock = false;

            bool scrolling = true;
        };

    } // namespace View
} // namespace OpMon

#endif // OVERWORLD_HPP
