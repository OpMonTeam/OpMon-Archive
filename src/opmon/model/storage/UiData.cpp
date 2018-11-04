/*
  UiData.cpp
  Author : Cyrion
  Contributors : BAKFR, Navet56
  File under GNU GPL v3.0 license
*/
#include "UiData.hpp"
#include "../../../utils/log.hpp"
#include "../objects/evolution/evolutions.hpp"
#include "../save/OptionsSave.hpp"
#include "ResourceLoader.hpp"

namespace OpMon {
    namespace Model {

        UiData::UiData() {

            Utils::Log::oplog("Initializating UiData");

            jukebox.addMusic("Title", "audio/music/title.ogg", 50);
            jukebox.addMusic("Start", "audio/music/intro.ogg");
            jukebox.addMusic("Fauxbourg", "audio/music/faubourgeuvi.ogg");
            jukebox.addMusic("Road 14", "audio/music/route14.ogg");
            //jukebox.addMusic("OpCenter", "audio/music/opcenter.ogg");
            jukebox.addMusic("Ms", "audio/music/mysterioucity.ogg");
            jukebox.addMusic("Labo", "audio/music/labo.ogg");
            jukebox.addMusic("Wild Battle", "audio/music/wildbattle.ogg");

            //Loading sounds
            jukebox.addSound("door sound", "audio/sounds/door.ogg");
            jukebox.addSound("shop door sound", "audio/sounds/shopdoor.ogg");
            jukebox.addSound("dialog pass", "audio/sounds/dialogChange.ogg");
            jukebox.addSound("nope", "audio/sounds/nope.ogg");
            jukebox.addSound("arrow", "audio/sounds/select.ogg");
            jukebox.addSound("push", "audio/sounds/selectbuttons.ogg");
            jukebox.addSound("hit", "audio/sounds/hit.ogg");

            ResourceLoader::load(font, "fonts/Default.ttf", true);

            //Loading OpMons
            using namespace Evolutions;
            listOp.emplace(0, new Species(136, 0, 1, 1, 29, 33, "MissingNo.", Type::NEUTRAL, Type::SKY, 0, 80, new E_Level(0, 80), std::vector<Stats>{Stats::ATK}, 0, 0, "ERROR : MISSINGNO.", 0, 1250000, 3, 0));
            listOp.emplace(1, new Species(49, 49, 65, 65, 45, 45, "Rosarin", Type::VEGETAL, Type::NOTHING, 0, 16, new E_Level(2, 16), std::vector<Stats>{Stats::ATKSPE}, 0.7, 6.9, "L'amour de cet OpMon est incroyable, il ne demande que d'affection.", 64, 1059860, 45, 1));
            listOp.emplace(2, new Species(62, 63, 80, 80, 60, 60, "Toxiris", Type::VEGETAL, Type::TOXIC, 0, 32, new E_Level(3, 32), std::vector<Stats>{Stats::ATKSPE, Stats::ATKSPE}, 1, 13, "Cet OpMon est extrememnt puissant, il empoisonne de façon violente tout ce qui passe sur son chemin.", 141, 1059860, 45, 2));
            listOp.emplace(3, new Species(82, 83, 100, 100, 80, 80, "Ninjasmine", Type::VEGETAL, Type::TOXIC, 0, -1, nullptr, std::vector<Stats>{Stats::ATKSPE, Stats::ATKSPE, Stats::ATKSPE}, 2, 100, "Cet OpMon empoisonne ses adversaires rapidement grâce à ses 2 épées de poisons", 236, 1059860, 45, 3));
            listOp.emplace(4, new Species(60, 58, 30, 52, 33, 65, "Oursiflamme", Type::BURNING, Type::NOTHING, 0, 28, new E_Level(19, 28), std::vector<Stats>{Stats::ATK}, 0.5, 20, "Un si gentil ourson qui est tout feu tout flamme.", 93, 1000000, 45, 4));
            listOp.emplace(5, new Species(80, 75, 60, 59, 54, 78, "Boudabrun", Type::BURNING, Type::NOTHING, 0, 29, new E_Level(37, 29), std::vector<Stats>{Stats::ATK, Stats::ATK}, 1.9, 130.5, "Cet ours est colérique, un rien peut lui mettre le feu au poudre.", 122, 1000000, 60, 5));
            listOp.emplace(6, new Species(110, 96, 92, 74, 72, 84, "Calcinours", Type::BURNING, Type::FIGHT, 0, -1, nullptr, std::vector<Stats>{Stats::ATK, Stats::ATK, Stats::HP}, 2.6, 588, "Cet ours serait capable de mettre à feu et à sang n'importe quoi.", 172, 1250000, 172, 6));
            listOp.emplace(7, new Species(25, 35, 50, 54, 73, 44, "Nanolphin", Type::LIQUID, Type::NOTHING, 0, 16, new E_Level(8, 16), std::vector<Stats>{Stats::DEF}, 0.5, 9, "Il adore nager en compagnie d'autres Nanolphins", 66, 1059860, 45, 7));
            listOp.emplace(8, new Species(63, 80, 65, 80, 110, 59, "Deaulfin", Type::LIQUID, Type::NOTHING, 0, 36, new E_Level(9, 36), std::vector<Stats>{Stats::DEF, Stats::DEFSPE}, 1, 22.5, "Il peut cracher de l'eau grâce à sa queue, le jet est tellement puissant qu'il peut se déplacer sur terre", 143, 1059860, 45, 8));
            listOp.emplace(9, new Species(120, 80, 75, 105, 30, 109, "Roileine", Type::LIQUID, Type::NOTHING, 0, -1, nullptr, std::vector<Stats>{Stats::DEF, Stats::DEFSPE, Stats::DEFSPE}, 1.6, 85.5, "Il est le roi des océans de la région, il est capable de manger n'importe quoi, n'importe ou.", 210, 1059860, 45, 9));
            listOp.emplace(10, new Species(30, 35, 20, 20, 45, 45, "Verpomme", Type::BUG, Type::MINERAL, 0, 7, new E_Level(11, 19), std::vector<Stats>{Stats::HP}, 0.3, 2.9, "Les Verpommes adorent aller dans les arbres pour faire semblant d'être des pommes, pour manger des sautinelles.", 53, 1000000, 255, 10));
            listOp.emplace(11, new Species(20, 55, 25, 25, 30, 50, "Terrapatte", Type::BUG, Type::MINERAL, 0, 10, new E_Level(12, 25), std::vector<Stats>{Stats::HP, Stats::DEF}, 0.7, 9.9, "Les Terrapattes detestent qu'on ls prennent pour des Serpiterre", 72, 1000000, 120, 11));
            listOp.emplace(12, new Species(105, 40, 70, 80, 75, 55, "Millepaterre", Type::MINERAL, Type::FIGHT, 0, -1, nullptr, std::vector<Stats>{Stats::DEF, Stats::DEF, Stats::DEFSPE}, 1.1, 32, "Cet OPMon contient plus d'un millier de petits pattes collantes, ce qui lui permet de se déplacer partout", 160, 1000000, 45, 12));
            listOp.emplace(13, new Species(56, 35, 25, 35, 72, 30, "Ornitaupe", Type::NEUTRAL, Type::LIQUID, 0, 20, new E_Level(20, 27), std::vector<Stats>{Stats::ATKSPE}, 1.2, 7.5, "Cet OpMon creuse des tunnels à l'aide de sa queue plate, grâce à cela, son espece a developper dans cette queue une grande force.", 57, 1000000, 255, 13));
            listOp.emplace(14, new Species(81, 60, 50, 70, 97, 55, "Ornitank", Type::NEUTRAL, Type::LIQUID, 0, -1, nullptr, std::vector<Stats>{Stats::ATKSPE, Stats::HP}, 1.5, 38.5, "Il tire des balles grâce à son ventre, cela peut transpercer une montagne.", 127, 1000000, 127, 14));
            listOp.emplace(15, new Species(35, 30, 20, 20, 50, 40, "Sautinelle", Type::BUG, Type::NOTHING, 0, 7, new E_Level(14, 7), std::vector<Stats>{Stats::SPE}, 0.3, 3.2, "Son aiguillon empoisonné est très dangereux. Son corps est coloré afin de repousser ses ennemis.", 52, 1000000, 255, 15));
            listOp.emplace(16, new Species(25, 50, 25, 25, 35, 45, "Invavore", Type::BUG, Type::FIGHT, 0, 10, new E_Level(15, 10), std::vector<Stats>{Stats::SPE, Stats::DEF}, 0.6, 10, "Incapable de se déplacer de lui-même, il se défend en durcissant sa carapace.", 71, 1000000, 120, 16));
            listOp.emplace(17, new Species(80, 40, 45, 80, 75, 65, "Assautrèle", Type::BUG, Type::FIGHT, 0, -1, nullptr, std::vector<Stats>{Stats::DEF, Stats::DEF, Stats::DEFSPE}, 1, 29.5, "Il se sert de ses trois aiguillons empoisonnés pour attaquer sans relâche ses adversaires.", 159, 1000000, 45, 17));
            listOp.emplace(18, new Species(62, 67, 55, 55, 26, 90, "Calame", Type::TOXIC, Type::LIQUID, 0, -1, new E_Item(31, Item::getItem("Pierre Eau")), std::vector<Stats>{Stats::HP, Stats::HP}, 0.9, 20, "Ce mignon petit OpMon asire les âmes de ses ennemis et les recrache pour les attaquer", 117, 1059860, 120, 18));
            listOp.emplace(20, new Species(45, 48, 60, 65, 35, 70, "Chibiro", Type::MAGIC, Type::VEGETAL, 0, -1, new E_Item(21, Item::getItem("Pierre Lune")), std::vector<Stats>{Stats::HP, Stats::HP}, 0.4, 7.5, "Il puise ses ressources dans les forêts, et des fois dans les champs, car on le confond souvent avec un navet", 68, 800000, 150, 20));
            listOp.emplace(21, new Species(70, 73, 95, 90, 60, 95, "Fatoro", Type::MAGIC, Type::VEGETAL, 0, -1, new E_Nope(), std::vector<Stats>{Stats::HP, Stats::HP, Stats::HP}, 2.2, 340, "Il y en a un par forêt, on les considèrent des fois comme des divinités des forêts car il est très rare d'en trouver et que le seul moyen est une forêt.", 129, 8000000, 25, 21));
            listOp.emplace(22, new Species(55, 53, 31, 48, 37, 69, "Graffiki", Type::ELECTRON, Type::NOTHING, 0, 29, new E_Level(26, 29), std::vector<Stats>{Stats::SPE, Stats::SPE}, 7.4, 6, "Gouachtiti a un sacré coup de crayon !", 82, 1000000, 100, 22));
            listOp.emplace(25, new Species(56, 35, 25, 35, 72, 30, "Circephant", Type::MAGIC, Type::SKY, 0, 26, new E_Level(18, 26), std::vector<Stats>{Stats::ATKSPE}, 0.4, 6, "Circéphant utilise sa queue comme baguette magique, il peut réaliser différents tours dont certains peuvent être fatales à ses adversaires.", 117, 1059860, 120, 25));
            listOp.emplace(26, new Species(80, 39, 61, 43, 79, 38, "Elheka", Type::MAGIC, Type::SKY, 0, 26, new E_Level(29, 27), std::vector<Stats>{Stats::ATKSPE, Stats::ATKSPE}, 1.8, 69, "Son comble c'est que c'est un éléphant qui sait voler grâce au pouvoir de sa queue.", 180, 1059860, 45, 26));
            listOp.emplace(27, new Species(101, 65, 84, 56, 89, 50, "Ganestar", Type::MAGIC, Type::GROUND, 0, -1, nullptr, std::vector<Stats>{Stats::ATKSPE, Stats::ATKSPE, Stats::ATKSPE}, 1.7, 256, "Il lui arrive de marcher sur des sautinelles sans le vouloir.", 220, 1059860, 30, 27));
            listOp.emplace(30, new Species(62, 67, 55, 55, 26, 90, "NameNotDefined", Type::TOXIC, Type::LIQUID, 0, -1, new E_Item(31, Item::getItem("Pierre Eau")), std::vector<Stats>{Stats::HP, Stats::HP}, 0.9, 20, "Ce mignon petit OpMon asire les âmes de ses ennemis et les recrache pour les attaquer", 117, 1059860, 120, 30));
            listOp.emplace(30, new Species(52, 43, 60, 50, 65, 39, "Titbraise", Type::BURNING, Type::NOTHING, 0, 16, new E_Level(5, 16), std::vector<Stats>{Stats::ATK}, 0.2, 2.3, "C'est l'un des plus petit monstres de ce monde, il est assez inssignifiant mais il fait très mal quand il le veut", 65, 1059860, 45, 30));
            listOp.emplace(31, new Species(92, 87, 75, 85, 76, 90, "Bolderi", Type::TOXIC, Type::GROUND, 0, -1, new E_Nope(), std::vector<Stats>{Stats::HP, Stats::HP, Stats::HP}, 1.3, 60, "Il controle le riz, il est capable de faire le faire voler, et même de faire des formes avec.", 194, 1059860, 45, 31));
            listOp.emplace(33, new Species(57, 40, 40, 40, 50, 46, "Dragonbolderi‚", Type::TOXIC, Type::NOTHING, 0, 16, new E_Level(33, 16), std::vector<Stats>{Stats::ATK}, 0.5, 9, "Ce dragon en riz est capable d'éviter les coups en creant des trous dans son corps, mais à part cela, il peut à peine voler.", 60, 1059860, 235, 33));
            listOp.emplace(33, new Species(72, 57, 55, 55, 65, 61, "Kameosan", Type::TOXIC, Type::NOTHING, 0, -1, new E_Item(34, Item::getItem("Pierre Lune")), std::vector<Stats>{Stats::ATK, Stats::ATK}, 0.9, 19.5, "Cette jarre de saké japonais a pris vie, elle peut aspirer du riz venant de l'exterieur, pour grossir encore son crâne.", 118, 1059860, 120, 33));
            listOp.emplace(34, new Species(80, 35, 35, 45, 70, 8, "Champoing", Type::FIGHT, Type::NOTHING, 0, 28, new E_Level(35, 23), std::vector<Stats>{Stats::ATK}, 0.7, 18, "Champoing est très fort pour envoyer des patates, moins pour se déplacer...", 74, 1000000, 190, 34));
            listOp.emplace(35, new Species(85, 55, 92, 38, 66, 68, "Boxali", Type::FIGHT, Type::NOTHING, 0, -1, nullptr, std::vector<Stats>{Stats::ATK, Stats::ATK, Stats::ATK}, 1.89, 72, "Boxali peut utiliser sa cape bleue pour planer quelques secondes au dessus du sol et pouvoir faire des figures et des coups aériens.", 149, 1000000, 75, 35));
            listOp.emplace(36, new Species(81, 36, 17, 89, 17, 48, "Nebulba", Type::MAGIC, Type::DRAGON, 0, 19, new E_Level(37, 19), std::vector<Stats>{Stats::ATKSPE}, 0.19, 6.8, "On ne connait pas la date d'apparition de cet OPMon, certains disent qu'il serait plus vieux que notre planète.", 57, 1059860, 30, 36));
            listOp.emplace(37, new Species(83, 40, 33, 100, 46, 127, "Draquasar", Type::MAGIC, Type::DRAGON, 0, -1, nullptr, std::vector<Stats>{Stats::ATKSPE, Stats::ATKSPE, Stats::ATKSPE}, 2.07, 180.4, "Il communique avec les planêtes, même venant d'autres systèmes.", 118, 1250000, 2, 37));
            listOp.emplace(44, new Species(44, 100, 45, 25, 40, 30, "Tétaflore", Type::LIQUID, Type::VEGETAL, 0, -1, nullptr, std::vector<Stats>{Stats::DEF}, 0.3, 4, "Si vous le regardez dans les yeux, vous serez entourés d'eau et de fleurs instantanement, le temps qu'ils vous tuent.", 97, 1250000, 190, 44));
            listOp.emplace(43, new Species(120, 53, 35, 110, 87, 50, "Philynx", Type::FIGHT, Type::VEGETAL, 0, -1, nullptr, std::vector<Stats>{Stats::ATK, Stats::ATK}, 1.4, 49, "Ils sont toujours là, mais on ne les voient jamais, surtout la nuit, à moins d'avoir l'oeil de Lynx", 139, 1000000, 45, 43));
            listOp.emplace(46, new Species(76, 54, 89, 48, 60, 150, "MagMortis", Type::BURNING, Type::MINERAL, 0, -1, nullptr, std::vector<Stats>{Stats::DEF, Stats::DEF}, 3.64, 532, "Cet OpMon oublié au fil du temps est à l'origine de la disparition d'une ancienne génération de monstres combattants.", 200, 1850000, 10, 46));
            listOp.emplace(50, new Species(90, 90, 90, 90, 90, 90, "Clair de Lune", Type::MAGIC, Type::BAD, 0, -1, nullptr, std::vector<Stats>{Stats::ATKSPE, Stats::DEFSPE, Stats::DEFSPE}, 0.4, 5, "Ce chat adorait contempler la lune chaques soirs, mais un soir, la lune a eu raison du chat", 300, 1250000, 3, 50));

            //Initializating OpMon Sprites
            //I will use a "for" loop later, I don't use it now to avoid loading errors. I will use it when every sprite will be loaded.
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[1], "sprites/opmons/1-%d.png", 2);
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[2], "sprites/opmons/2-%d.png", 2);
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[4], "sprites/opmons/4-%d.png", 2);
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[7], "sprites/opmons/7-%d.png", 2);

            //Intializing types sprites
#define LOAD_TYPE(type)                                                                            \
    ResourceLoader::load(tempTx, (std::string("sprites/battle/types/") + #type + ".png").c_str()); \
    typesTextures.emplace(Type::type, sf::Texture(tempTx))

            sf::Texture tempTx;
            LOAD_TYPE(BAD);
            LOAD_TYPE(BUG);
            LOAD_TYPE(BURNING);
            LOAD_TYPE(COLD);
            LOAD_TYPE(DRAGON);
            LOAD_TYPE(ELECTRON);
            LOAD_TYPE(FIGHT);
            LOAD_TYPE(GHOST);
            LOAD_TYPE(GROUND);
            LOAD_TYPE(LIQUID);
            LOAD_TYPE(MAGIC);
            LOAD_TYPE(MENTAL);
            LOAD_TYPE(METAL);
            LOAD_TYPE(MINERAL);
            LOAD_TYPE(NEUTRAL);
            LOAD_TYPE(SKY);
            LOAD_TYPE(TOXIC);
            LOAD_TYPE(VEGETAL);

#undef LOAD_TYPE

            //Loading dialogs
            ResourceLoader::load(dialogBackground, "backgrounds/dialog/dialog.png");
            ResourceLoader::load(dialogArrow, "sprites/misc/arrDial.png");

            //Loading volume
            if(!OptionsSave::checkParam("volume")) {
                OptionsSave::addParam("volume", "100");
            }

            int volume = std::stoi(OptionsSave::getParam("volume").getValue());
            jukebox.setGlobalVolume(volume);

            //Loading controls
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
                up = sf::Keyboard::Up;
            } else {
                up = keysMap[keyUp];
            }
            std::string keyDown = OptionsSave::getParam("control.down").getValue();
            if(keyDown == "NULL") {
                OptionsSave::addParam("control.down", "Down");
                down = sf::Keyboard::Down;
            } else {
                down = keysMap[keyDown];
            }
            std::string keyLeft = OptionsSave::getParam("control.left").getValue();
            if(keyLeft == "NULL") {
                OptionsSave::addParam("control.left", "Left");
                left = sf::Keyboard::Left;
            } else {
                left = keysMap[keyLeft];
            }
            std::string keyRight = OptionsSave::getParam("control.right").getValue();
            if(keyRight == "NULL") {
                OptionsSave::addParam("control.right", "Right");
                right = sf::Keyboard::Right;
            } else {
                right = keysMap[keyRight];
            }
            std::string keyTalk = OptionsSave::getParam("control.talk").getValue();
            if(keyTalk == "NULL") {
                OptionsSave::addParam("control.talk", "Space");
                talk = sf::Keyboard::Space;
            } else {
                talk = keysMap[keyTalk];
            }
            std::string keyInteract = OptionsSave::getParam("control.interact").getValue();
            if(keyInteract == "NULL") {
                OptionsSave::addParam("control.interact", "Return");
                interact = sf::Keyboard::Return;
            } else {
                interact = keysMap[keyInteract];
            }
        }

        UiData::~UiData() {
            for(auto spe : listOp) {
                delete(spe.second);
            }
            Utils::Log::oplog("Deleted UiData");
        }
    } // namespace Model
} // namespace OpMon
