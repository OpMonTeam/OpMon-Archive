
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
            
            doorsTextures.push_back(basicDoor);

            ResourceLoader::load(Model::Data::Ui::doorSoundBuffer, "audio/sounds/door.ogg");
            ResourceLoader::load(Model::Data::Ui::shopDoorSoundBuffer, "audio/sounds/shopdoor.ogg");

            Events::doorSound.setBuffer(Model::Data::Ui::doorSoundBuffer);
            Events::shopdoorSound.setBuffer(Model::Data::Ui::shopDoorSoundBuffer);

            

            

            




            initOpTextures();

        }

        void initFonts() {
            
        }

        void initSounds() {
	  
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

	  
        }

    } // namespace Initializer
} // namespace OpMon
