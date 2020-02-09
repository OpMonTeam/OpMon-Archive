/*!
 * \file Overworld.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
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

        /*!
         * \brief The overworld.
         * \details This class prints and manages the camera, the map, the events, the animated elements on the map, and the player's animation.
         * \todo Unify the player animation system and the npc animation system.
         */
        class Overworld {
          public:
            Overworld(const std::string &mapId, Model::OverworldData &data);

            sf::Sprite &getCharacter() {
                return character;
            }

            /*!
             * \brief Returns the map the player is in currently.
             * \todo Rename to getCurrentMap
             */
            Model::Map *getCurrent() {
                return current;
            }

            /*!
             * \brief Updates and draws the overworld on the screen.
             */
            GameStatus operator()(sf::RenderTexture &frame);

            /*!
             * \brief Teleports the player.
             * \param toTp The ID of the map in which teleport the player.
             * \param pos Where to teleport the player in the map.
             */
            void tp(std::string toTp, sf::Vector2i pos);

            /*!
             * \brief Returns a layer of the map the player is currently in.
             * \param number The number of the layer.
             * \returns The layer of the map. Returns nullptr if the number given is not 1, 2 or 3.
             */
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

            /*!
             * \brief Decides which layer is printed.
             */
            bool printlayer[3] = {true, true, true};
            bool printCollisions = false;

            /*!
             * \brief Locks the player's movements for a short time after teleporting.
             */
            bool justTp = false;

            virtual ~Overworld() = default;

            virtual void play();
            virtual void pause();

            /*!
             * \brief Plays the music given in parameter.
             * \deprectated Directly use Jukebox::play.
             */
            void setMusic(std::string const &path);

            Model::Events::TrainerEvent *getBattleDeclared() {
                return trainerToBattle;
            }

            /*!
             * \brief Makes the overworld start a Battle.
             * \details The controller will then start a Battle with the given trainer.
             * \param trainer The trainer to fight.
             */
            void declareBattle(Model::Events::TrainerEvent *trainer) {
                if(trainerToBattle == nullptr) {
                    trainerToBattle = trainer;
                } else {
                    handleError("Trying to set up a battle, but an another is already set up. Recheck the code", true);
                }
            }

            /*!
             * \brief Ends the current Battle.
             */
            void endBattle() {
                if(trainerToBattle == nullptr) {
                    handleError("Warning : ending a battle, but there is no battle.");
                }
                trainerToBattle = nullptr;
            }

            /*!
             * \brief Events can call this method to start a new dialog with the player.
             */
            void startDialog(sf::String const &dialog);

            /*!
             * \brief Animates the player.
             */
            void startPlayerAnimation() {
                initPlayerAnimation = true;
            }

            Model::OverworldData &getData() { return data; }

          private:
            /*!
             * \brief Prints the animated elements on the screen.
             */
            void printElements(sf::RenderTexture &frame);

            /*!
             * \brief Shows the collision layer.
             * \brief The collision layer consists in semi-transparent squares on each tile. You can see it by pressing C while in debug mode ('=' key).
             */
            void printCollisionLayer(sf::RenderTarget &frame);

            /*!
             * \brief Moves the camera to follow the player's position.
             * \todo Change camera to make it always centered on the player, except on the edges of the map
             */
            void updateCamera(sf::RenderTarget &frame);

            /*!
             * \brief Centers the camera on the player.
             */
            void resetCamera();

            Model::Events::TrainerEvent *trainerToBattle = nullptr;

            sf::View camera;
            sf::Sprite character;
            /*!
             * \brief The map the player is currently in.
             */
            Model::Map *current = nullptr;

            std::unique_ptr<MapLayer> layer1;
            std::unique_ptr<MapLayer> layer2;
            std::unique_ptr<MapLayer> layer3;
            std::unique_ptr<Dialog> dialog;
            /*!
             * \brief Indicates the frame of the walking animation that must be used.
             * \details Since the animation has two frames, this variable alternates between `true` and `false` every half of the animation.
             */
            bool anims = false;

            int fpsCounter = 0;
            sf::Text fpsPrint;
            sf::Text coordPrint;
            int oldTicksFps = 0;

            int animsCounter = 0;
            bool initPlayerAnimation = false;
            int startPlayerAnimationTime = 0;

            bool cameraLock = false;

            std::map<std::string, sf::Sprite> elementsSprites;

            Model::OverworldData &data;
        };

    } // namespace View
} // namespace OpMon

#endif // OVERWORLD_HPP
