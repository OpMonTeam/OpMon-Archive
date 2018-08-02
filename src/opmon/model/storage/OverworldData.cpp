#include "OverworldData.hpp"
#include "../../../utils/OpString.hpp"
#include "../objects/Attacks.hpp"
#include "InternalFiles.hpp"
#include "ResourceLoader.hpp"

namespace OpMon {
    namespace Model {

        OverworldData::OverworldData(UiData *uidata, Player *player)
          : uidata(uidata)
          , player(player) {

            using namespace Utils;

	    player->addOpToOpTeam(new Model::OpMon("", uidata->getOp(4), 5, {Model::Attacks::newAtk("Charge"), Model::Attacks::newAtk("Brouillard"), nullptr, nullptr}, Model::Nature::QUIET));
	    
            //PP textures loading
            ResourceLoader::load(texturePP[(unsigned int)Side::TO_DOWN], "sprites/chara/pp/pp0.png");
            ResourceLoader::load(texturePP[(unsigned int)Side::TO_RIGHT], "sprites/chara/pp/pp1.png");
            ResourceLoader::load(texturePP[(unsigned int)Side::TO_LEFT], "sprites/chara/pp/pp2.png");
            ResourceLoader::load(texturePP[(unsigned int)Side::TO_UP], "sprites/chara/pp/pp3.png");
            ResourceLoader::load(walkingPP[(unsigned int)Side::TO_DOWN], "sprites/chara/pp/mpp0.png");
            ResourceLoader::load(walkingPP[(unsigned int)Side::TO_RIGHT], "sprites/chara/pp/mpp1.png");
            ResourceLoader::load(walkingPP[(unsigned int)Side::TO_LEFT], "sprites/chara/pp/mpp2.png");
            ResourceLoader::load(walkingPP[(unsigned int)Side::TO_UP], "sprites/chara/pp/mpp3.png");
            ResourceLoader::load(walkingPP2[(unsigned int)Side::TO_DOWN], "sprites/chara/pp/mpp20.png");
            ResourceLoader::load(walkingPP2[(unsigned int)Side::TO_RIGHT], "sprites/chara/pp/mpp21.png");
            ResourceLoader::load(walkingPP2[(unsigned int)Side::TO_LEFT], "sprites/chara/pp/mpp22.png");
            ResourceLoader::load(walkingPP2[(unsigned int)Side::TO_UP], "sprites/chara/pp/mpp23.png");

            //Characters' textures initialization
            ResourceLoader::loadTextureArray(charaTextures["kid"], "sprites/chara/kid/kid%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["fisherman"], "sprites/chara/fisherman/fisherman%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["kiwai"], "sprites/chara/prof/prof%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["playermom"], "sprites/chara/mom/mom%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["sk"], "sprites/chara/rival/sk%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["inferm"], "sprites/chara/inferm/inferm%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["|_| -|- |-| |= |_| N"], "sprites/chara/beta/alphabeta/otheon%d.png", 12);
	    ResourceLoader::loadTextureArray(charaTextures["beta"], "sprites/chara/beta/beta%d.png", 12);

            //Doors' textures initialization
            ResourceLoader::loadTextureArray(doorsTextures["shop"], "animations/shopdoor/shop_door%d.png", 4, 1);
            ResourceLoader::loadTextureArray(doorsTextures["normal"], "animations/basicdoor/basic_door%d.png", 4, 1);

            //Elements initialization
            elementsCounter["windturbine"] = 0;
            elementsPos["windturbine"] = sf::Vector2f(8 * 32 + 25 * 32 - 8, 3 * 32 + 8);

            ResourceLoader::loadTextureArray(elementsTextures["windturbine"], "animations/windturbine/blade_%d.png", 16, 1);

            elementsCounter["smoke"] = 0;
            elementsPos["smoke"] = sf::Vector2f(8 * 32 + 18 * 32, 11 * 32);

            ResourceLoader::loadTextureArray(elementsTextures["smoke"], "animations/chimneysmoke/chimneysmoke_%d.png", 32, 1);

            //Maps initialization

            using namespace std;

            //Fauxbourg Euvi loading
            std::vector<sf::Vector2f> feEPos;

            Map *mapFauxbourgEuvi = maps.emplace("Fauxbourg Euvi", new Map(Maps::feLayer1, Maps::feLayer2, Maps::feLayer3, 48, 48, false, "Fauxbourg", std::vector<std::string>{"windturbine", "smoke"})).first->second;
            mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(19, 10), {OpString("fedesc.1"), OpString("fedesc.2"), OpString("fedesc.3")}, SIDE_UP));
            mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(29, 16), {OpString("ppHouse", player->getNameP()), OpString::voidStr, OpString::voidStr}, SIDE_UP));
            mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(33, 16), {OpString("rivalHouse"), OpString::voidStr, OpString::voidStr}, SIDE_UP));
            mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(22, 28), {OpString("labo"), OpString::voidStr, OpString::voidStr}, SIDE_UP));
            mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(31, 28), {OpString("weirdsign.1"), OpString("weirdsign.2"), OpString::voidStr}, SIDE_UP));
            mapFauxbourgEuvi->addEvent(new Events::DoorEvent(doorsTextures["normal"], "door", sf::Vector2f(27, 16), sf::Vector2i(8, 15), "Player's home"));
            mapFauxbourgEuvi->addEvent(new Events::DoorEvent(doorsTextures["normal"], "door", sf::Vector2f(35, 16), sf::Vector2i(9, 15), "Rival's house"));
            mapFauxbourgEuvi->addEvent(new Events::DoorEvent(doorsTextures["shop"], "shop door", sf::Vector2f(27, 28), sf::Vector2i(16, 15), "Laboratory"));
            mapFauxbourgEuvi->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(39, 17), sf::Vector2i(4, 38), "Road 14", Side::TO_RIGHT, SIDE_RIGHT));
            mapFauxbourgEuvi->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(39, 18), sf::Vector2i(4, 39), "Road 14", Side::TO_RIGHT, SIDE_RIGHT));
            mapFauxbourgEuvi->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(39, 19), sf::Vector2i(4, 40), "Road 14", Side::TO_RIGHT, SIDE_RIGHT));
            mapFauxbourgEuvi->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(39, 20), sf::Vector2i(4, 41), "Road 14", Side::TO_RIGHT, SIDE_RIGHT));
            /*Character 1*/
            std::vector<Side> pathChara1;
            for(int i = 0; i < 10; i++)
                pathChara1.push_back(Side::TO_RIGHT);

            pathChara1.push_back(Side::NO_MOVE);

            for(int i = 0; i < 10; i++)
                pathChara1.push_back(Side::TO_LEFT);

            pathChara1.push_back(Side::NO_MOVE);

            mapFauxbourgEuvi->addEvent(new Events::TalkingCharaEvent(charaTextures["kid"], sf::Vector2f(25, 21), {OpString("kid"), OpString::voidStr, OpString::voidStr}, Side::TO_RIGHT, Events::EventTrigger::PRESS, Events::MoveStyle::PREDEFINED, pathChara1));

            mapFauxbourgEuvi->addEvent(new Events::TalkingCharaEvent(charaTextures["fisherman"], sf::Vector2f(16, 16), {OpString("fe.fisherman.1"), OpString("fe.fisherman.2"), OpString("fe.fisherman.3"), OpString("fe.fisherman.4"), OpString("fe.fisherman.5"), OpString("fe.fisherman.6"), OpString("fe.fisherman.7"), OpString("fe.fisherman.8"), OpString("fe.fisherman.9")}, Side::TO_LEFT));

            Map *mapPlayersHome = maps.emplace("Player's home", new Map(Maps::pphomeLayer1, Maps::pphomeLayer2, Maps::pphomeLayer3, 16, 16, true, "Fauxbourg")).first->second;
            mapPlayersHome->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(7, 15), sf::Vector2i(28, 17), "Fauxbourg Euvi", Side::TO_DOWN, SIDE_DOWN));
            mapPlayersHome->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(15, 2), sf::Vector2i(9, 7), "Player's room", Side::TO_LEFT, SIDE_RIGHT));
            mapPlayersHome->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(0, 11), sf::Vector2i(6, 3), "Mom's room", Side::TO_LEFT, SIDE_LEFT));
            std::vector<OpString> phomE1{OpString("playerhome.tv.1"), OpString("playerhome.tv.2"), OpString("playerhome.tv.3")};
            mapPlayersHome->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(3, 8), phomE1, SIDE_UP));
            mapPlayersHome->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(2, 8), phomE1, SIDE_UP));
            mapPlayersHome->addEvent(new Events::TalkingCharaEvent(charaTextures["playermom"], sf::Vector2f(9, 9), {OpString("playermom.dialog.1"), OpString("playermom.dialog.2"), OpString("playermom.dialog.3")}, Side::TO_DOWN));
            Map *mapLaboratory = maps.emplace("Laboratory", new Map(Maps::laboLayer1, Maps::laboLayer2, Maps::laboLayer3, 32, 16, true, "Labo")).first->second;
            mapLaboratory->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(15, 15), sf::Vector2i(28, 29), "Fauxbourg Euvi", Side::TO_DOWN, SIDE_DOWN));

            mapLaboratory->addEvent(new Events::TalkingCharaEvent(charaTextures["kiwai"], sf::Vector2f(15, 4), {OpString("prof.dialog.1"), OpString("prof.dialog.2"), OpString("prof.dialog.3")}, Side::TO_DOWN));

            Map *mapRivalsHouse = maps.emplace("Rival's house", new Map(Maps::rivalhomeLayer1, Maps::rivalhomeLayer2, Maps::rivalhomeLayer3, 16, 16, true, "Fauxbourg")).first->second;
            mapRivalsHouse->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(8, 15), sf::Vector2i(36, 17), "Fauxbourg Euvi", Side::TO_DOWN, SIDE_DOWN));

            Map *mapMomsRoom = maps.emplace("Mom's room", new Map(Maps::momroomLayer1, Maps::momroomLayer2, Maps::momroomLayer3, 6, 6, true, "Fauxbourg")).first->second;
            mapMomsRoom->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(5, 3), sf::Vector2i(1, 11), "Player's home", Side::TO_RIGHT, SIDE_RIGHT));

            Map *mapPlayersRoom = maps.emplace("Player's room", new Map(Maps::pproomLayer1, Maps::pproomLayer2, Maps::pproomLayer3, 9, 8, true, "Fauxbourg")).first->second;
            mapPlayersRoom->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(8, 7), sf::Vector2i(16, 2), "Player's home", Side::TO_LEFT, SIDE_RIGHT));
            std::vector<OpString> phoE1{OpString("pcRunLinux"), OpString::voidStr, OpString::voidStr};
            mapPlayersRoom->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(1, 3), phoE1, SIDE_UP));

            //Road 14 loading
            Map *mapRoad14 = maps.emplace("Road 14", new Map(Maps::route14Layer1, Maps::route14Layer2, Maps::route14Layer3, 86, 57, false, "Road 14")).first->second;
            mapRoad14->addEvent(new Events::TalkingCharaEvent(charaTextures["sk"], sf::Vector2f(16, 39), {OpString("rt14.sk.1"), OpString("rt14.sk.2"), OpString("rt14.sk.3")}, Side::TO_LEFT));
            mapRoad14->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(4, 38), sf::Vector2i(39, 17), "Fauxbourg Euvi", Side::TO_LEFT, SIDE_LEFT));
            mapRoad14->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(4, 39), sf::Vector2i(39, 18), "Fauxbourg Euvi", Side::TO_LEFT, SIDE_LEFT));
            mapRoad14->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(4, 40), sf::Vector2i(39, 19), "Fauxbourg Euvi", Side::TO_LEFT, SIDE_LEFT));
            mapRoad14->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(4, 41), sf::Vector2i(39, 20), "Fauxbourg Euvi", Side::TO_LEFT, SIDE_LEFT));

	    OpTeam betaTeam = Model::OpTeam("Beta");
	    betaTeam.addOpMon(new Model::OpMon("", uidata->getOp(1), 5, {Model::Attacks::newAtk("Charge"), Model::Attacks::newAtk("Brouillard"), nullptr, nullptr}, Model::Nature::QUIET));
	    
	    mapRoad14->addEvent(new Events::TrainerEvent(charaTextures["beta"], sf::Vector2f(11, 32), betaTeam, {OpString("rt14.beta.pre.1"), OpString("rt14.beta.pre.2"), OpString("rt14.beta.pre.3"), OpString("rt14.beta.pre.4"), OpString("rt14.beta.pre.5"), OpString("rt14.beta.pre.6"), OpString("rt14.beta.pre.7")}, {OpString("rt14.beta.post.1"), OpString("rt14.beta.post.2"), OpString("rt14.beta.post.3")}, Side::TO_LEFT));
	    
            //MysteriouCity loading
            Map *mapMs = maps.emplace("MysteriouCity", new Map(Maps::myciLayer1, Maps::myciLayer2, Maps::myciLayer3, 35, 35, false, "Ms")).first->second;
            mapMs->addEvent(new Events::TalkingCharaEvent(charaTextures["|_| -|- |-| |= |_| N"], sf::Vector2f(15, 30), {}));
            mapMs->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(15, 12), sf::Vector2i(10, 17), "OpCenter", Side::TO_UP, SIDE_UP));
            //OpMon Center loading
            Map *mapOpCenter = maps.emplace("OpCenter", new Map(Maps::opcenterLayer1, Maps::opcenterLayer2, Maps::opcenterLayer3, 18, 18, true, "Start")).first->second;
            mapOpCenter->addEvent(new Events::TalkingCharaEvent(charaTextures["inferm"], sf::Vector2f(9, 10), {OpString("inferm.dialog.1"), OpString("inferm.dialog.2"), OpString("inferm.dialog.3")}, Side::TO_DOWN));
            std::vector<OpString> opcE1{OpString("inferm.dialog.1"), OpString("inferm.dialog.2"), OpString("inferm.dialog.3")};
            mapOpCenter->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(9, 11), opcE1, SIDE_UP));
            mapOpCenter->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(9, 17), sf::Vector2i(16, 13), "MysteriouCity", Side::TO_DOWN, SIDE_DOWN));
            mapOpCenter->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(8, 17), sf::Vector2i(16, 13), "MysteriouCity", Side::TO_DOWN, SIDE_DOWN));
        }

        OverworldData::~OverworldData() {
            for(auto &map : maps) {
                delete(map.second);
            }
        }

    } // namespace Model
} // namespace OpMon
