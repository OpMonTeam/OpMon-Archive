
#include "Initializer.hpp"
#include "../../utils/OpString.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/log.hpp"
#include "../model/objects/Enums.hpp"
#include "../model/objects/OpMon.hpp"
#include "../model/objects/evolution/evolutions.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"
#include "../model/storage/InternalFiles.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../model/sysObjects/Events.hpp"
#include "../model/sysObjects/Map.hpp"
#include "../view/Window.hpp"
#include "Core.hpp"
#include "i18n/Translator.hpp"
#include <sstream>

using Utils::OpString;
using Utils::Log::oplog;

#pragma GCC diagnostic ignored "-Wcomment"

namespace OpMon {

    namespace Initializer {
        using namespace Model;

        template <typename T>
        void pb(std::vector<T> &vect, T arr[], int sizeArr) {
            for(unsigned int i = 0; i < sizeArr; i++) {
                vect.push_back(arr[i]);
            }
        }

        void initAnims() {
            ResourceLoader::loadTextureArray(Data::Animations::fen, "animations/winChange/animWindowFrame%d.png", 6, 1);
            //Data::Animations::init = true;
        }

        void deleteAnims() {
            //Data::Animations::init = false;
        }

        void initOpMons() {
            
           
      */
        }

        void initMusics() {

        }

        void initAtkLvls() {

            Data::OpMons::atkOpLvl.push_back(std::map<int, std::string>());
            Data::OpMons::atkOpLvl[0][0] = "Charge";
            Data::OpMons::atkOpLvl[0][3] = "Rugissement";
            Data::OpMons::atkOpLvl[0][7] = "Vampigraine";
            Data::OpMons::atkOpLvl[0][9] = "FoutetLianes";
            //etc...
        }

        using namespace Model::Data::Ui;

        void initOpTextures() {
            
        }

        void initTextures() {

            ResourceLoader::load(Data::World::tileset, "tileset/tileset.png");


            std::vector<sf::Texture> basicDoor;
            ResourceLoader::loadTextureArray(basicDoor, "animations/basicdoor/basic_door%d.png", 4, 1);
            doorsTextures.push_back(basicDoor);

            ResourceLoader::load(Model::Data::Ui::doorSoundBuffer, "audio/sounds/door.ogg");
            ResourceLoader::load(Model::Data::Ui::shopDoorSoundBuffer, "audio/sounds/shopdoor.ogg");

            Events::doorSound.setBuffer(Model::Data::Ui::doorSoundBuffer);
            Events::shopdoorSound.setBuffer(Model::Data::Ui::shopDoorSoundBuffer);

            std::vector<sf::Texture> shopDoor;
            ResourceLoader::loadTextureArray(shopDoor, "animations/shopdoor/shop_door%d.png", 4, 1);
            doorsTextures.push_back(shopDoor);

            

            




            initOpTextures();

            initEnumsEvents();
        }

        void initFonts() {
            
        }

        void initSounds() {
            ResourceLoader::load(Model::Data::Sounds::dialogPass, "audio/sounds/dialogChange.ogg");
            ResourceLoader::load(Model::Data::Sounds::nope, "audio/sounds/nope.ogg");
            ResourceLoader::load(Model::Data::Sounds::arrow, "audio/sounds/select.ogg");
            ResourceLoader::load(Model::Data::Sounds::push, "audio/sounds/selectbuttons.ogg");
        }

        void initSprites() {
            oplog("Textures initialization");
            initTextures();
            oplog("Backgrounds initialization");
            initBackgrounds();
            oplog("Animations initialization");
            initAnims();
            oplog("Font initialization");
            initFonts();
            oplog("Maps initialization");
            initMaps();
        }
        
        

        void initMaps() {

        }

        void initBackgrounds() {
        }

        void initKeys() {
            //Sets the language to initialize in the keys

            std::string lang = OptionsSave::getParam("lang").getValue();
            auto &tr = ::OpMon::I18n::Translator::getInstance();

            if(!tr.getAvailableLanguages().count(lang)) {
                lang = "en"; // The lang isn't available. Default to english.
            }
            tr.setLang(lang);
        }

        void init() {
            oplog("Keys initialization");
            initKeys();
            oplog("Items initialization");
            initItems();
            oplog("Attaks by levels initialization");
            initAtkLvls();
            oplog("OPMons initialization");
            initOpMons();
            oplog("Music initialization");
            initMusics();
            oplog("Sound initialisation");
            initSounds();
            oplog("Objects initialization ending");
            initSprites();
            oplog("Player initialization");
            initPlayer();
            oplog("Controls initialization");
            initControls();
        }

        void initPlayer() {

        }



        void initControls() {

	  #define ADDMAP(key) keysMap[(#key)] = sf::Keyboard::key
            std::map<std::string, sf::Keyboard::Key> keysMap;
            ADDMAP(A);
            ADDMAP(Z);
            ADDMAP(E);
            ADDMAP(R);
            ADDMAP(T);
            ADDMAP(Y);
            ADDMAP(U);
            ADDMAP(I);
            ADDMAP(O);
            ADDMAP(P);
            ADDMAP(Q);
            ADDMAP(S);
            ADDMAP(D);
            ADDMAP(F);
            ADDMAP(G);
            ADDMAP(H);
            ADDMAP(J);
            ADDMAP(K);
            ADDMAP(L);
            ADDMAP(M);
            ADDMAP(W);
            ADDMAP(X);
            ADDMAP(C);
            ADDMAP(V);
            ADDMAP(B);
            ADDMAP(N);
            ADDMAP(Num1);
            ADDMAP(Num2);
            ADDMAP(Num3);
            ADDMAP(Num4);
            ADDMAP(Num5);
            ADDMAP(Num6);
            ADDMAP(Num7);
            ADDMAP(Num8);
            ADDMAP(Num9);
            ADDMAP(Num0);
            ADDMAP(LControl);
            ADDMAP(RControl);
            ADDMAP(LShift);
            ADDMAP(RShift);
            ADDMAP(LAlt);
            ADDMAP(RAlt);
            ADDMAP(Space);
            ADDMAP(Return);
            ADDMAP(BackSpace);
            ADDMAP(Tab);
            ADDMAP(Up);
            ADDMAP(Left);
            ADDMAP(Right);
            ADDMAP(Down);
            ADDMAP(Numpad1);
            ADDMAP(Numpad2);
            ADDMAP(Numpad3);
            ADDMAP(Numpad4);
            ADDMAP(Numpad5);
            ADDMAP(Numpad6);
            ADDMAP(Numpad7);
            ADDMAP(Numpad8);
            ADDMAP(Numpad9);
            ADDMAP(Numpad0);
            ADDMAP(Unknown);

#undef ADDMAP
	    
            std::string keyUp = OptionsSave::getParam("control.up").getValue();
            if(keyUp == "NULL") {
                OptionsSave::addParam("control.up", "Up");
                Model::Data::Controls::up = sf::Keyboard::Up;
            } else {
                Model::Data::Controls::up = keysMap[keyUp];
            }
            std::string keyDown = OptionsSave::getParam("control.down").getValue();
            if(keyDown == "NULL") {
                OptionsSave::addParam("control.down", "Down");
                Model::Data::Controls::down = sf::Keyboard::Down;
            } else {
                Model::Data::Controls::down = keysMap[keyDown];
            }
            std::string keyLeft = OptionsSave::getParam("control.left").getValue();
            if(keyLeft == "NULL") {
                OptionsSave::addParam("control.left", "Left");
                Model::Data::Controls::left = sf::Keyboard::Left;
            } else {
                Model::Data::Controls::left = keysMap[keyLeft];
            }
            std::string keyRight = OptionsSave::getParam("control.right").getValue();
            if(keyRight == "NULL") {
                OptionsSave::addParam("control.right", "Right");
                Model::Data::Controls::right = sf::Keyboard::Right;
            } else {
                Model::Data::Controls::right = keysMap[keyRight];
            }
            std::string keyTalk = OptionsSave::getParam("control.talk").getValue();
            if(keyTalk == "NULL") {
                OptionsSave::addParam("control.talk", "Space");
                Model::Data::Controls::talk = sf::Keyboard::Space;
            } else {
                Model::Data::Controls::talk = keysMap[keyTalk];
            }
            std::string keyInteract = OptionsSave::getParam("control.interact").getValue();
            if(keyInteract == "NULL") {
                OptionsSave::addParam("control.interact", "Return");
                Model::Data::Controls::interact = sf::Keyboard::Return;
            } else {
                Model::Data::Controls::interact = keysMap[keyInteract];
            }
        }

    } // namespace Initializer
} // namespace OpMon
