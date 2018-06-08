#include "Data.hpp"
#include <SFML/Audio.hpp>

#include "../objects/Species.hpp"
#include "../sysObjects/Map.hpp"

namespace OpMon {
    namespace Model {
        namespace Data {

            Player player;

            namespace OpMons {
                std::map<unsigned int, Species *> listOp;
                std::vector<std::map<int, std::string>> atkOpLvl;
                std::vector<std::vector<Stats>> evs;
                std::vector<std::vector<sf::Texture>> opSprites;
                std::map<Type, sf::Texture> typesTextures;
            } // namespace OpMons

            namespace World {
                std::map<std::string, Map *> maps;
                sf::Texture tileset;
            } // namespace World

            namespace Battle {
                std::map<std::string, sf::Texture> backgrounds;
                sf::Texture dialog;
                sf::Texture attackDialog;
                sf::Texture cursor;
                std::vector<sf::Texture> choices;
                std::map<std::string, std::vector<sf::Texture>> charaBattleTextures;
                std::list<sf::Texture> battlePlayerAnim;
                sf::Texture infoboxPlayer;
                sf::Texture infoboxTrainer;
                sf::Texture healthbar1;
                sf::Texture healthbar2;
                sf::Texture shadowPlayer;
                sf::Texture shadowTrainer;
            } // namespace Battle

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
                sf::Texture dialogBackground;
                sf::Texture dialogArrow;
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

            namespace Controls {
                sf::Keyboard::Key up;
                sf::Keyboard::Key down;
                sf::Keyboard::Key left;
                sf::Keyboard::Key right;
                sf::Keyboard::Key interact;
                sf::Keyboard::Key talk;
            } // namespace Controls
        }     // namespace Data
    }         // namespace Model
} // namespace OpMon
