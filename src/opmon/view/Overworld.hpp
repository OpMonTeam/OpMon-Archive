/*
  Overworld.hpp
  Author : Cyriel
  Contributor : BAKFR
  File under GNU GPL v3.0 license
*/
#ifndef OVERWORLD_HPP
#define OVERWORLD_HPP

#include <memory>

#include "../model/objects/Enums.hpp"
#include "../model/storage/OverworldData.hpp"
#include "../model/sysObjects/Map.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../start/Core.hpp"
#include "../start/GameStatus.hpp"
#include "Dialog.hpp"
#include "Elements.hpp"

namespace OpMon {
    namespace View {

        class Overworld {
          public:
            Overworld(const std::string &mapId, Model::OverworldData &data);

            sf::Sprite &getCharacter() {
                return character;
            }

            Model::Map *getCurrent() {
                return current;
            }

            GameStatus operator()(sf::RenderWindow &frame);

            void tp(std::string toTp, sf::Vector2i pos);

            MapLayer *getMapLayer(int number) {
                switch(number) {
                case 1:
                    return layer1.get();
                case 2:
                    return layer2.get();
                case 3:
                    return layer3.get();
                default:
                    return nullptr;
                }
            }

            Dialog *getDialog() {
                return dialog.get();
            }

            void moveCamera(Model::Side dir);
            bool isCameraLocked();
            void setCameraLock(bool locked);

            bool printlayer[3] = {true, true, true};
            bool printCollisions = false;

            bool justTp = false;

            virtual ~Overworld() = default;

            virtual void play();
            virtual void pause();

            void setMusic(std::string const &path);

            Model::Events::TrainerEvent *getBattleDeclared() {
                return trainerToBattle;
            }

            void declareBattle(Model::Events::TrainerEvent *trainer) {
                if(trainerToBattle == nullptr) {
                    trainerToBattle = trainer;
                } else {
                    handleError("Trying to set up a battle, but an another is already set up. Recheck the code", true);
                }
            }

            void endBattle() {
                if(trainerToBattle == nullptr) {
                    handleError("Warning : ending a battle, but there is no battle.");
                }
                trainerToBattle = nullptr;
            }

            /**
	     * Events can call this method to start a new dialog with the player.
	     */
            void startDialog(std::vector<sf::String> const &dialogs);

            void startPlayerAnimation() {
                initPlayerAnimation = true;
            }

          private:
            void printElements(sf::RenderWindow &frame);

            void printCollisionLayer(sf::RenderTarget &frame);

            /* Move the camera to follow the player's moves. */
            void updateCamera(sf::RenderTarget &frame);

            /* Center the camera on the player. */
            void resetCamera();

            Model::Events::TrainerEvent *trainerToBattle = nullptr;

            sf::View camera;
            sf::Sprite character;
            sf::Vector2f charaStartPos;
            Model::Map *current = nullptr;

            std::string musicPath = "";

            std::unique_ptr<MapLayer> layer1;
            std::unique_ptr<MapLayer> layer2;
            std::unique_ptr<MapLayer> layer3;
            std::unique_ptr<Dialog> dialog;
            //Indicate the frame of the walking animation that must be used. (The animation has two frames)
            bool anims = false;

            int fpsCounter = 0;
            sf::Text fpsPrint;
            sf::Text coordPrint;
            int oldTicksFps = 0;

            int tpCount = 0;

            int animsCounter = 0;
            bool initPlayerAnimation = false;
            int startPlayerAnimationTime = 0;

            bool cameraLock = false;

            std::map<std::string, sf::Sprite> elementsSprites;

            Model::OverworldData &data;

          public:
            Model::OverworldData &getData() { return data; }
        };

    } // namespace View
} // namespace OpMon

#endif // OVERWORLD_HPP
