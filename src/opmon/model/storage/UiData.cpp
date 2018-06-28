#include "UiData.hpp"

namespace OpMon {
  namespace Model {

    UiData::UiData(){
      jukebox.addMusic("Title", "audio/music/title.ogg", 50);
      jukebox.addMusic("Start", "audio/music/intro.ogg");
      jukebox.addMusic("Fauxbourg", "audio/music/faubourgeuvi.ogg");
      jukebox.addMusic("Route 14", "audio/music/route14.ogg");
      //jukebox.addMusic("OpCenter", "audio/music/opcenter.ogg");
      jukebox.addMusic("Ms", "audio/music/mysterioucity.ogg");
      jukebox.addMusic("Labo", "audio/music/labo.ogg");
      jukebox.addMusic("Wild Battle", "audio/music/wildbattle.ogg");

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
      listOp.emplace(19, new Species(60, 30, 31, 31, 70, 40, "Cridaile", Type::NEUTRAL, Type::SKY, 0, 20, new E_Level(22, 20), std::vector<Stats>{Stats::SPE}, 0.4, 4, "Il chasse les Sautinelles dans les hautes herbes. Ses petites ailes lui permettent de voler très vite.", 58, 1000000, 255, 19));
      listOp.emplace(20, new Species(45, 48, 60, 65, 35, 70, "Chibiro", Type::MAGIC, Type::VEGETAL, 0, -1, new E_Item(21, Item::getItem("Pierre Lune")), std::vector<Stats>{Stats::HP, Stats::HP}, 0.4, 7.5, "Il puise ses ressources dans les forêts, et des fois dans les champs, car on le confond souvent avec un navet", 68, 800000, 150, 20));
      listOp.emplace(21, new Species(70, 73, 95, 90, 60, 95, "Fatoro", Type::MAGIC, Type::VEGETAL, 0, -1, new E_Nope(), std::vector<Stats>{Stats::HP, Stats::HP, Stats::HP}, 2.2, 340, "Il y en a un par forêt, on les considèrent des fois comme des divinités des forêts car il est très rare d'en trouver et que le seul moyen est une forêt.", 129, 8000000, 25, 21));
      listOp.emplace(22, new Species(160, 65, 31, 31, 10, 95, "Himondelle", Type::TOXIC, Type::SKY, 0, -1, nullptr, std::vector<Stats>{Stats::SPE, Stats::SPE}, 1.9, 190, "Cet OPMon plutôt imposant, ne peut plus voler depuis qu'il a évoluer, cela resulte d'un manque de migrations du à l'abondance d'insectes dans cette région", 162, 1000000, 90, 22));
      listOp.emplace(23, new Species(60, 44, 40, 54, 55, 35, "Serpiterre", Type::GROUND, Type::BAD, 0, 24, new E_Level(24, 22), std::vector<Stats>{Stats::SPE}, 2, 6.9, "Plus il est âgé, plus son corps est long. Il se nourrit de spectres nocturnes caché sous terre", 62, 1000000, 255, 23));
      listOp.emplace(24, new Species(85, 69, 65, 79, 80, 60, "Serpenair", Type::SKY, Type::BAD, 0, -1, nullptr, std::vector<Stats>{Stats::SPE, Stats::ATK}, 3.5, 65, "Il adore planer au dessus des ses proies, les fantomes de nuits, pour jouer avec eux, avant de les aspirer.", 147, 1000000, 90, 24));
      listOp.emplace(25, new Species(55, 40, 50, 50, 90, 35, "Nucléage", Type::ELECTRON, Type::NOTHING, 0, -1, new E_Item(26, Item::getItem("Invocation de la foudre")), std::vector<Stats>{Stats::ATK, Stats::ATKSPE}, 7.4, 6, "Ce nuage s'amuse à viser les monuments ou objets très grands, ils sont à l'origine des éclairs aleatoires dans le ciel. Ils aiment se caché parmi les vraies nuages", 82, 1000000, 100, 25));
      listOp.emplace(26, new Species(200, 55, 90, 80, 110, 60, "Cielectrik", Type::ELECTRON, Type::NOTHING, 0, -1, nullptr, std::vector<Stats>{Stats::ATK, Stats::ATKSPE, Stats::ATKSPE}, 0., 30, "Il peut terrasser tout ses en libérant un décharge foudroyante plus de 550 000 V.", 122, 1000000, 65, 26));
      listOp.emplace(30, new Species(62, 67, 55, 55, 26, 90, "NameNotDefined", Type::TOXIC, Type::LIQUID, 0, -1, new E_Item(31, Item::getItem("Pierre Eau")), std::vector<Stats>{Stats::HP, Stats::HP}, 0.9, 20, "Ce mignon petit OpMon asire les âmes de ses ennemis et les recrache pour les attaquer", 117, 1059860, 120, 30));
      listOp.emplace(30, new Species(52, 43, 60, 50, 65, 39, "Titbraise", Type::BURNING, Type::NOTHING, 0, 16, new E_Level(5, 16), std::vector<Stats>{Stats::ATK}, 0.2, 2.3, "C'est l'un des plus petit monstres de ce monde, il est assez inssignifiant mais il fait très mal quand il le veut", 65, 1059860, 45, 30));
      listOp.emplace(31, new Species(92, 87, 75, 85, 76, 90, "Bolderi", Type::TOXIC, Type::GROUND, 0, -1, new E_Nope(), std::vector<Stats>{Stats::HP, Stats::HP, Stats::HP}, 1.3, 60, "Il controle le riz, il est capable de faire le faire voler, et même de faire des formes avec.", 194, 1059860, 45, 31));
      listOp.emplace(32, new Species(57, 40, 40, 40, 50, 46, "Dragonbolderi‚", Type::TOXIC, Type::NOTHING, 0, 16, new E_Level(33, 16), std::vector<Stats>{Stats::ATK}, 0.5, 9, "Ce dragon en riz est capable d'éviter les coups en creant des trous dans son corps, mais à part cela, il peut à peine voler.", 60, 1059860, 235, 32));
      listOp.emplace(33, new Species(72, 57, 55, 55, 65, 61, "Kameosan", Type::TOXIC, Type::NOTHING, 0, -1, new E_Item(34, Item::getItem("Pierre Lune")), std::vector<Stats>{Stats::ATK, Stats::ATK}, 0.9, 19.5, "Cette jarre de saké japonais a pris vie, elle peut aspirer du riz venant de l'exterieur, pour grossir encore son crâne.", 118, 1059860, 120, 33));
      /*_____________________________________________________
	listOp.emplace(56, new Species(80, 35, 35, 45, 70, 40, "Poigno", Type::FIGHT, Type::NOTHING, 0, 28, new E_Level(57, 28), std::vector<Stats>{Stats::ATK}, 0.7, 18, "Il ne peut dissocier ses amis de ses ennemis et a tendance à  enrager lorsqu'on l'approche.", 74, 1000000, 190, 56));

	listOp.emplace(57, new Species(85, 55, 92, 38, 66, 68, "Boxali", Type::FIGHT, Type::NOTHING, 0, -1, new E_Nope(),  std::vector<Stats>{Stats::ATK, Stats::ATK, Stats::ATK}, 1.89, 72, "Boxali peut utiliser sa cape bleue pour planer quelques secondes au dessus du sol et pouvoir faire des figures et des coups aériens.", 149, 1000000, 75, 57));
	________________________________________________________
	listOp.emplace(90, new Species(65, 100, 45, 25, 40, 30, "Tétaflore", Type::LIQUID, Type::VEGETAL, 0, -1, new E_Nope(), std::vector<Stats>{Stats::DEF}, 0.3, 4, "Si vous le regardez dans les yeux, vous serez entourés de d'eau et de fleurs instantanement, le temps qu'ils vous tuent.", 97, 1250000, 190, 90));
	__________________________________________
	listOp.emplace(106, new Species(120, 53, 35, 110, 87, 50, "Philynx", Type::FIGHT, Type::VEGETAL, 0, -1, new E_Nope(), std::vector<Stats>{Stats::ATK, Stats::ATK}, 1.4, 49, "Ils sont toujours là, mais on ne les voient jamais, surtout la nuit, à moins d'avoir l'oeil de Lynx", 139, 1000000, 45, 106));
	listOp.emplace(?, new Species(90, 90, 90, 90, 90, 90, "Clair de Lune", Type::LUMIERE, Type::BAD, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.DEFSPE, Stats.}, 0.4, 5, "Ce chat adorait contempler la lune chaques soirs, mais un jour, la lune a eu raison de lui", 300, 1250000, 3, ?));
	_______________________________________________________________

      */

      //Initializating OpMon Sprites
      //I will use a "for" loop later, I don't use it now to avoid loading errors. I will use it when every sprite will be loaded.
      std::vector<std::vector<sf::Texture>> &opSprites = Model::Data::OpMons::opSprites;
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
#define LOAD_TYPE(type)							\
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
      ResourceLoader::load(Model::Data::Ui::dialogBackground, "backgrounds/dialog/dialog.png");
      ResourceLoader::load(Model::Data::Ui::dialogArrow, "sprites/misc/arrDial.png");
      
    }
  }
}
