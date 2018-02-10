#include "Data.hpp"
#include <SFML/Audio.hpp>

#include "../objects/Species.hpp"
#include "../sysObjects/Map.hpp"

namespace OpMon {
    namespace Model {
        namespace Data {

            Player player;

            namespace OpMons {
                std::map<unsigned int, Species> listOp;
                std::vector<std::map<int, std::string>> atkOpLvl;
                std::vector<std::vector<Stats>> evs;
            } // namespace OpMons

            namespace World {
                std::map<std::string, Map *> maps;
                sf::Texture tileset;
            } // namespace World

            namespace Elements {
                std::map<std::string, sf::Vector2f> elementsPos;
                std::map<std::string, int> elementsCounter;
                std::map<std::string, std::vector<sf::Texture>> elementsTextures;
                std::map<std::string, sf::Sprite> elementsSprites;
            } // namespace Elements

            namespace Ui {
                std::map<std::string, Map> maps;
                std::vector<sf::Music *> townMusics;
                std::vector<std::vector<sf::Texture>> doorsTextures;
                sf::SoundBuffer doorSoundBuffer;
                sf::SoundBuffer shopDoorSoundBuffer;
                sf::Texture tileset;
                std::map<std::string, std::vector<sf::Texture>> charaTextures;
                sf::Texture texturePP[4];
                sf::Texture walkingPP[4];
                sf::Texture walkingPP2[4];
                sf::Font font;
            } // namespace Ui
            namespace Animations {
                sf::Texture fen[6];
            }

            namespace Sounds {
                sf::SoundBuffer nope;
                sf::SoundBuffer arrow;
                sf::SoundBuffer dialogPass;
	      sf::SoundBuffer push;
            } // namespace Sounds
        }     // namespace Data
    }         // namespace Model
} // namespace OpMon
