
#include <sstream>
#include "Initializer.hpp"
#include "../../utils/OpString.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/log.hpp"
#include "../../utils/fs.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"
#include "../model/storage/InternalFiles.hpp"
#include "../model/objects/Enums.hpp"
#include "../model/objects/evolution/evolutions.hpp"
#include "../model/sysObjects/Events.hpp"
#include "../model/sysObjects/Map.hpp"
#include "i18n/Translator.hpp"
#include "Core.hpp"


using Utils::Fs::getPath;
using Utils::OpString;
using Utils::Log::oplog;


namespace OpMon{

  namespace Initializer {
    using namespace Model;
  
    template<typename T>void pb(std::vector<T> &vect, T arr[], int sizeArr) {
      for (unsigned int i = 0; i < sizeArr; i++) {
	vect.push_back(arr[i]);
      }
    }

    void initAnims() {
      for(int i = 0; i < 6; i++) {
	std::ostringstream oss;
	oss << getPath(RESSOURCES_PATH + "animations/winChange/animWindowFrame") << i + 1 << ".png";
	Data::Animations::fen[i].loadFromFile(oss.str());
      }
      //Data::Animations::init = true;
    }

    void deleteAnims() {
      //Data::Animations::init = false;
    }

    
    void initOpMons() {
      using namespace Evolutions;
      Data::OpMons::listOp.try_emplace(0, 136, 0, 1, 1, 29, 33, "MissingNo.", Type::NORMAL, Type::VOL, 0, 80, new E_Level(0, 80), std::vector<Stats>{Stats::ATK}, 0, 0, "ERROR : MISSINGNO.", 0, 1250000, 3, 0);
      Data::OpMons::listOp.try_emplace(1, 49, 49, 65, 65, 45, 45, "Rosarin", Type::PLANTE, Type::NOTHING, 0, 16, new E_Level(2, 16), Model::Data::OpMon::evs[1], 0.7, 6.9, "L'amour de cet OpMon est incroyable, il ne demande que d'affection.", 64, 1059860, 45, 1);
      Data::OpMons::listOp.try_emplace(2, 62, 63, 80, 80, 60, 60, "Toxiris",Type::PLANTE, Type::POISON, 0, 32, new E_Level(3, 32), Model::Data::OpMon::evs[2], 1, 13, "Cet OpMon est extrememnt puissant, il empoisonne de façon violente tout ce qui passe sur son chemin.", 141, 1059860, 45, 2);
      Data::OpMons::listOp.try_emplace(3, 82, 83, 100, 100, 80, 80, "Ninjasmine", Type::PLANTE, Type::POISON, 0, -1, nullptr, Model::Data::OpMon::evs[3], 2, 100, "Cet OpMon empoisonne ses adversaires rapidement grâce à ses 2 épées de poisons", 236, 1059860, 45, 3);
      Data::OpMons::listOp.try_emplace(4, 52, 43, 60, 50, 65, 39, "Titbraise", Type::FEU, Type::NOTHING, 0, 16, new E_Level(5, 16), Model::Data::OpMon::evs[4], 0.2, 2.3, "C'est l'un des plus petit monstres de ce monde, il est assez inssignifiant mais il fait très mal quand il le veut", 65, 1059860, 45, 4);
      Data::OpMons::listOp.try_emplace(5, 64, 58, 80, 65, 80, 58, "Rouxiflamme", Type::FEU, Type::NOTHING, 0, 36, new E_Level(6, 36), Model::Data::OpMon::evs[5], 1.1, 19, "Quand cette créature attaque, elle rougit de toute ses forces pour bruler son adversaire", 142, 1059860, 45, 5);
      Data::OpMons::listOp.try_emplace(6, 84, 78, 109, 85, 100, 78, "Enflammatorche", Type::FEU, Type::VOL, 0, -1, nullptr, Model::Data::OpMon::evs[6], 3.7, 90.5, "Le feu qui sort de son crâne peu très vite detruire tout sur son passage", 209, 1059860, 45, 6);
      Data::OpMons::listOp.try_emplace(7, 25, 35, 50, 54, 73, 44, "Nanolphin", Type::EAU, Type::NOTHING, 0, 16, new E_Level(8, 16), Model::Data::OpMon::evs[7], 0.5, 9, "Il adore nager en compagnie d'autres Nanolphins", 66, 1059860, 45, 7);
      Data::OpMons::listOp.try_emplace(8, 63, 80, 65, 80, 110, 59, "Deaulfin", Type::EAU, Type::NOTHING, 0, 36, new E_Level(9, 36), Model::Data::OpMon::evs[8], 1, 22.5,"Il peut cracher de l'eau grâce à sa queue, le jet est tellement puissant qu'il peut se déplacer sur terre", 143, 1059860, 45, 8);
      Data::OpMons::listOp.try_emplace(9, 120, 80, 75, 105, 30, 109, "Roileine", Type::EAU, Type::NOTHING, 0, -1,nullptr, Model::Data::OpMon::evs[9], 1.6, 85.5, "Il est le roi des océans de la région, il est capable de manger n'importe quoi, n'importe ou.", 210, 1059860, 45, 9);
      Data::OpMons::listOp.try_emplace(10, 30, 35, 20, 20, 45, 45, "Verpomme", Type::INSECTE, Type::ROCHE, 0, 7, new E_Level(11, 19), Model::Data::OpMon::evs[10], 0.3, 2.9, "Les Verpommes adorent aller dans les arbres pour faire semblant d'être des pommes, pour manger des sautinelles.", 53, 1000000, 255, 10);
      Data::OpMons::listOp.try_emplace(11, 20, 55, 25, 25, 30, 50, "Terrapatte", Type::INSECTE, Type::ROCHE, 0, 10, new E_Level(12, 25), Model::Data::OpMon::evs[11], 0.7, 9.9, "Les Terrapattes detestent qu'on ls prennent pour des Serpiterre", 72, 1000000, 120, 11);
      Data::OpMons::listOp.try_emplace(12, 105, 40, 70, 80, 75, 55, "Millepaterre", Type::ROCHE, Type::COMBAT, 0, -1, nullptr, Model::Data::OpMon::evs[12], 1.1, 32, "Cet OPMon contient plus d'un millier de petits pattes collantes, ce qui lui permet de se déplacer partout", 160, 1000000, 45, 12);
      Data::OpMons::listOp.try_emplace(13, 35, 30, 20, 20, 50, 40, "Sautinelle", Type::INSECTE, Type::NOTHING, 0, 7, new E_Level(14, 7),Model::Data::OpMon::evs[13], 0.3, 3.2, "Son aiguillon empoisonné est très dangereux. Son corps est coloré afin de repousser ses ennemis.", 52, 1000000, 255, 13);
      Data::OpMons::listOp.try_emplace(14, 25, 50, 25, 25, 35, 45, "Invavore", Type::INSECTE, Type::COMBAT, 0, 10, new E_Level(15, 10), Model::Data::OpMon::evs[14], 0.6, 10, "Incapable de se déplacer de lui-même, il se défend en durcissant sa carapace.", 71, 1000000, 120, 14);
      Data::OpMons::listOp.try_emplace(15, 80, 40, 45, 80, 75, 65, "Assautrèle", Type::INSECTE, Type::COMBAT, 0, -1, nullptr, Model::Data::OpMon::evs[15], 1, 29.5, "Il se sert de ses trois aiguillons empoisonnés pour attaquer sans relâche ses adversaires.", 159, 1000000, 45, 15);
      Data::OpMons::listOp.try_emplace(16, 45, 40, 35, 35, 56, 40, "Pelicamp", Type::NORMAL, Type::VOL, 0, 18, new E_Level(17, 18), Model::Data::OpMon::evs[16], 0.3, 1., "Cet OpMon adore voler seul, le problème, c'est qu'il n'est pas le seul dans le ciel...", 55, 1059860, 255, 16);
      Data::OpMons::listOp.try_emplace(17, 60, 55, 50, 50, 71, 63, "Grand-Bec", Type::NORMAL, Type::VOL, 0, 36, new E_Level(18, 36), Model::Data::OpMon::evs[17], 1.1, 30, "Il protège son territoire avec ardeur et repousse à  coup de bec tout intrus.", 113, 1059860, 120, 17);
      Data::OpMons::listOp.try_emplace(18, 80, 75, 50, 40, 190, 85, "Majelanion", Type::NORMAL, Type::VOL, 0, -1, nullptr, Model::Data::OpMon::evs[18], 1.5, 39.5, "Il adore attrapper des Ornitaupes en vol, sa vitesse et tellement forte que son corp siffle pednant son vol", 172, 1059860, 45, 18);
      Data::OpMons::listOp.try_emplace(19, 56, 35, 25, 35, 72, 30, "Ornitaupe", Type::NORMAL, Type::EAU, 0, 20, new E_Level(20, 27), Model::Data::OpMon::evs[19], 1.2, 7.5, "Cet OpMon creuse des tunnels à l'aide de sa queue plate, grâce à cela, son espece a developper dans cette queue une grande force.", 57, 1000000, 255, 19);
      Data::OpMons::listOp.try_emplace(20, 81, 60, 50, 70, 97, 55, "Ornitank", Type::NORMAL, Type::EAU, 0, -1, nullptr, Model::Data::OpMon::evs[20], 1.5, 38.5, "Il tire des balles grâce à son ventre, cela peut transpercer une montagne.", 127, 1000000, 127, 20);
      Data::OpMons::listOp.try_emplace(21, 60, 30, 31, 31, 70, 40, "Cridaile", Type::NORMAL, Type::VOL, 0, 20, new E_Level(22, 20), Model::Data::OpMon::evs[21], 0.4, 4, "Il chasse les Sautinelles dans les hautes herbes. Ses petites ailes lui permettent de voler très vite.", 58, 1000000, 255, 21);
      Data::OpMons::listOp.try_emplace(22, 160, 65, 31, 31, 10, 95, "Himondelle", Type::POISON, Type::VOL, 0, -1, nullptr, Model::Data::OpMon::evs[22], 1.9, 190, "Cet OPMon plutôt imposant, ne peut plus voler depuis qu'il a évoluer, cela resulte d'un manque de migrations du à l'abondance d'insectes dans cette région", 162, 1000000, 90, 22);
      Data::OpMons::listOp.try_emplace(23, 60, 44, 40, 54, 55, 35, "Serpiterre", Type::SOL, Type::TENEBRES, 0, 24, new E_Level(24, 22), Model::Data::OpMon::evs[23], 2, 6.9, "Plus il est âgé, plus son corps est long. Il se nourrit de spectres nocturnes caché sous terre", 62, 1000000, 255, 23);
      Data::OpMons::listOp.try_emplace(24, 85, 69, 65, 79, 80, 60, "Serpenair", Type::VOL, Type::TENEBRES, 0, -1, nullptr, Model::Data::OpMon::evs[24], 3.5, 65, "Il adore planer au dessus des ses proies, les fantomes de nuits, pour jouer avec eux, avant de les aspirer.", 147, 1000000, 90, 24);
      Data::OpMons::listOp.try_emplace(25, 55, 40, 50, 50, 90, 35, "Nucléage", Type::ELECTRIQUE, Type::NOTHING, 0, -1, new E_Item(26, Item::getItem("Invocation de la foudre")), Model::Data::OpMon::evs[25], 7.4, 6, "Ce nuage s'amuse à viser les monuments ou objets très grands, ils sont à l'origine des éclairs aleatoires dans le ciel. Ils aiment se caché parmi les vraies nuages", 82, 1000000, 100, 25);
      Data::OpMons::listOp.try_emplace(26, 200, 55, 90, 80, 110, 60, "Cielectrik", Type::ELECTRIQUE, Type::NOTHING, 0, -1, nullptr, Model::Data::OpMon::evs[26], 0., 30, "Il peut terrasser tout ses en libérant un décharge foudroyante plus de 550 000 V.", 122, 1000000, 65, 26);
      Data::OpMons::listOp.try_emplace(27, 60, 58, 30, 52, 33, 65, "Oursiflamme", Type::FEU, Type::NOTHING, 0, 28, new E_Level(19, 28),Model::Data::OpMon::evs[27], 0.5, 20, "Un si gentil ourson qui est tout feu tout flamme.", 93, 1000000, 45, 27);
      Data::OpMons::listOp.try_emplace(28, 80, 75, 60, 59, 54, 78, "Boudabrun", Type::FEU, Type::NOTHING, 0, 29, new E_Level(37,29), Model::Data::OpMon::evs[28], 1.9, 130.5, "Cet ours est colérique, un rien peut lui mettre le feu au poudre.", 122, 1000000, 60, 28);
      Data::OpMons::listOp.try_emplace(29, 110, 96, 92, 74, 72, 84, "Calcinours", Type::FEU, Type::COMBAT, 0, -1, nullptr, Model::Data::OpMon::evs[29], 2.6, 588, "Cet ours serait capable de mettre à feu et à sang n'importe quoi.", 172, 1250000, 172, 29);
      Data::OpMons::listOp.try_emplace(30, 62, 67, 55, 55, 26, 90, "Calame", Type::POISON, Type::EAU, 0, -1, new E_Item(31, Item::getItem("Pierre Eau")), Model::Data::OpMon::evs[30], 0.9, 20, "Ce mignon petit OpMon asire les âmes de ses ennemis et les recrache pour les attaquer", 117, 1059860, 120, 30);
      Data::OpMons::listOp.try_emplace(31, 92, 87, 75, 85, 76, 90, "Bolderi", Type::POISON, Type::SOL, 0, -1, new E_Nope(), Model::Data::OpMon::evs[31], 1.3, 60, "Il controle le riz, il est capable de faire le faire voler, et même de faire des formes avec.", 194, 1059860, 45, 31);
      Data::OpMons::listOp.try_emplace(32, 57, 40, 40, 40, 50, 46, "Dragonbolderi‚", Type::POISON, Type::NOTHING, 0, 16, new E_Level(33, 16), Model::Data::OpMon::evs[32], 0.5, 9, "Ce dragon en riz est capable d'éviter les coups en creant des trous dans son corps, mais à part cela, il peut à peine voler.", 60, 1059860, 235, 32);
      Data::OpMons::listOp.try_emplace(33, 72, 57, 55, 55, 65, 61, "Kameosan", Type::POISON, Type::NOTHING, 0, -1,new E_Item(34, Item::getItem("Pierre Lune")), Model::Data::OpMon::evs[33], 0.9, 19.5, "Cette jarre de saké japonais a pris vie, elle peut aspirer du riz venant de l'exterieur, pour grossir encore son crâne.", 118, 1059860, 120, 33);
      /*Data::OpMons::listOp.try_emplace(34, 102, 77, 85, 75, 85, 81, "Nidoking", Type::POISON, Type::SOL, 0, -1, new E_Nope(), Model::Data::OpMon::evs[34], 1.4, 62, "Un coup de sa puissante queue peut briser un poteau téléphonique comme une allumette.", 195, 1059860, 45, 34);
	Data::OpMons::listOp.try_emplace(35, 45, 48, 60, 65, 35, 70, "Mélofée", Type::FEE, Type::NOTHING, 0, -1, new E_Item(36, Item::getItem("Pierre Lune")), Model::Data::OpMon::evs[35], 06, 7.5, "La lumière de la lune qu'il emmagasine dans ses ailes dorsales lui permet de flotter dans les airs.", 68, 800000, 150, 35);
	Data::OpMons::listOp.try_emplace(36, 70, 73, 95, 90, 60, 95, "Mélodelfe", Type::FEE, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[36], 1.3, 40, "Il aime le calme des montagnes. Son ouà¯e exceptionnelle entendrait une aiguille tomber à  1km.", 129, 8000000, 25, 36);
	Data::OpMons::listOp.try_emplace(37, 41, 40, 50, 65, 65, 38, "Goupix", Type::FEU, Type::NOTHING, 0, -1, new E_Item(38, Item::getItem("Pierre Feu")), Model::Data::OpMon::evs[37], 0.6, 9.9, "Avec l'âge, la fourrure de ses six queues devient de plus en plus belle et soyeuse. Elle est chaude au toucher.",63, 1000000, 190, 37);//TROP KAWAII!!!!
	Data::OpMons::listOp.try_emplace(38, 76, 75, 81, 100, 100, 73, "Feunard", Type::FEU, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[38], 1.1, 19.9, "Il a neuf longues queues et une fourrure qui brille comme de l'or. On dit qu'il peut vivre 1 000 ans.", 178, 1000000, 75, 38);
	Data::OpMons::listOp.try_emplace(39, 45, 20, 45, 25, 20, 115, "Rondoudou", Type::NORMAL, Type::FEE, 0, -1, new E_Item(40, Item::getItem("Pierre Lune")), {Model::Data::OpMon::evs[39], 0.5, 5.5, "En se gonflant, il peut chanter une longue berceuse qui endort inévitablement ses adversaires.", 76, 800000, 170, 39);
	Data::OpMons::listOp.try_emplace(40, 70, 45, 85, 50, 45, 140, "Grodoudou", Type::NORMAL, Type::FEE, 0, -1, new E_Nope(), Model::Data::OpMon::evs[40], 1, 12, "En cas de danger, il gonfle d'air son corps doux et potelé dans des proportions gigantesques.", 109, 800000, 50, 40);
	Data::OpMons::listOp.try_emplace(41, 45, 35, 30, 40, 55, 40, "Nosferapti", Type::POISON, Type::VOL, 0, 22, new E_Level(42, 22), Model::Data::OpMon::evs[41], 0., 7.5, "Ce pokemon est détesté en raison de sa forte présence dans les grottes. Malgré le fait qu'il n'aie pas d'yeux, ce pokemon arrive a voir avec des utltrasons.", 54, 1000000, 255, 41);
	Data::OpMons::listOp.try_emplace(42, 80, 70, 65, 75, 90, 75, "Nosferalto", Type::POISON, Type::VOL, 0, -1, new E_Love(0), Model::Data::OpMon::evs[42], 1.6, 55, "Quand il se met à  sucer du sang, il ne s'arrÃªte qu'une fois rassasié. C'est un chasseur nocturne.", 171, 1000000, 90, 42);
	Data::OpMons::listOp.try_emplace(43, 50, 55, 75, 65, 30, 45, "Mystherbe", Type::PLANTE, Type::POISON, 0, 21, new E_Level(44, 21), Model::Data::OpMon::evs[43], 0.5, 5.4, "Le jour, il reste en sous-sol et évite le soleil. Il grandit en se baignant au clair de lune.", 78, 1059860, 255, 43);
	Data::OpMons::listOp.try_emplace(44, 65, 70, 85, 75, 40, 60, "Ortide", Type::PLANTE, Type::POISON, 0, -1, new E_Item(45, Item::getItem("Pierre Plante")) , Model::Data::OpMon::evs[44], 0., 8.6, "Il sent très mauvais ! Mais une personne sur 1 000 aime la puanteur de son corps nauséabond.", 132, 1059860, 120, 44);
	Data::OpMons::listOp.try_emplace(45, 80, 85, 110, 90, 50, 75, "Rafflesia", Type::PLANTE, Type::POISON, 0, -1, new E_Nope(), Model::Data::OpMon::evs[45], 1.2, 18.6, "Il possède des pétales énormes. à chaque pas, ils sèment d'épais nuages de pollen toxique.", 184, 1059860, 45, 45);
	Data::OpMons::listOp.try_emplace(46, 70, 55, 45, 55, 25, 35, "Paras", Type::INSECTE, Type::PLANTE, 0, 24, new E_Level(47, 24), Model::Data::OpMon::evs[46], 0.3, 5.4, "Il s'enfouit sous terre pour ronger des racines afin de nourrir les champignons sur son dos.", 70, 1000000, 190, 46);
	Data::OpMons::listOp.try_emplace(47, 95, 80, 60, 80, 30, 60, "Parasect", Type::INSECTE, Type::PLANTE, 0, -1, new E_Nope(), Model::Data::OpMon::evs[47], 1, 29.5, "Un champignon parasite plus gros que Parasect contrôle son corps. Il répand des spores empoisonnées.", 128, 1000000, 75, 47);
	Data::OpMons::listOp.try_emplace(48, 55, 50, 40, 55, 45, 60, "Mimitoss", Type::INSECTE, Type::POISON, 0, 31, new E_Level(49, 31), Model::Data::OpMon::evs[48], 1, 30, "Il vit à  l'ombre des grands arbres où il se nourrit d'insectes. Il est attiré par la lumière.", 75, 1000000, 190, 48);
	Data::OpMons::listOp.try_emplace(49, 65, 60, 90, 75, 90, 70, "Aéromite", Type::INSECTE, Type::POISON,0, -1, new E_Nope(), Model::Data::OpMon::evs[49], 1.5, 12.5, "Les écailles qu'il sème ont le pouvoir de paralyser totalement un ennemi.", 138, 1000000, 75, 49);
	Data::OpMons::listOp.try_emplace(50, 55, 25, 35, 45, 95, 10, "Taupiqueur", Type::SOL, Type::NOTHING, 0, 26, new E_Level(51, 26), Model::Data::OpMon::evs[50], 0.2, 0., "Son épiderme est très fin. S'il est exposé au soleil, son sang se réchauffe, ce qui l'affaiblit.", 81, 1000000, 255, 50);
	Data::OpMons::listOp.try_emplace(51, 80, 50, 50, 70, 120, 35, "Triopikeur", Type::SOL, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[51], 0.7, 33.3, "Terriblement puissants, ils peuvent creuser un tunnel dans tout type de sol et jusqu'à  100 km de profondeur.", 153, 1000000, 50, 51);
      */Data::OpMons::listOp.try_emplace(52, 45, 35, 40, 40, 90, 40, "Chagnon", Type::NORMAL, Type::PSY, 0, 28, new E_Level(53, 28), Model::Data::OpMon::evs[52], 0.4, 4.2, "Les Chagnons adorent dormir près des arbres, en esperant qu'un Verpomme tombe pour pouvoir le manger", 69, 1000000, 10, 52);
      /*Data::OpMons::listOp.try_emplace(53, 70, 60, 65, 65, 115, 65, "Persian", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[53], 1, 32, "Un Pokémon très snob. La taille du joyau qui orne son front alimente bien des débats parmi ses fans.", 148, 1000000, 90, 53);
	Data::OpMons::listOp.try_emplace(54, 52, 48, 65, 50, 55, 50, "Psykokwak", Type::EAU, Type::NOTHING, 0, 33, new E_Level(55, 33), Model::Data::OpMon::evs[54], 0., 19.6, "Il ne se souvient pas qu'il a des pouvoirs psy. C'est pour cela qu'il a l'air si confus.", 80, 1000000, 190, 54);
	Data::OpMons::listOp.try_emplace(55, 82, 78, 95, 80, 85, 80, "Akwakwak", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[55], 1.7, 76.6, "Il apparaà®t dans les étendues d'eau au crépuscule. Si son front brille, il se sert de sa télékinésie.", 174, 1000000, 75, 55);
	Data::OpMons::listOp.try_emplace(56, 80, 35, 35, 45, 70, 40, "Férosinge", Type::COMBAT, Type::NOTHING, 0, 28, new E_Level(57, 28),Model::Data::OpMon::evs[56], 0.5, 2, "Il ne peut dissocier ses amis de ses ennemis et a tendance à  enrager lorsqu'on l'approche.", 74, 1000000, 190, 56);
	Data::OpMons::listOp.try_emplace(57, 105, 60, 60, 70, 95, 65, "Colossinge", Type::COMBAT, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[57], 1, 32, "Sa fureur prend fin quand il n'a plus personne à  frapper. Il est difficile d'en Ãªtre témoin.", 149, 1000000, 75, 57);
	Data::OpMons::listOp.try_emplace(58, 70, 45, 70, 50, 60, 55, "Caninos", Type::FEU, Type::NOTHING, 0, -1, new E_Item(59, Item::getItem("Pierre Feu")),Model::Data::OpMon::evs[58], 0.7, 19, "Il est courageux et fier. Il se dresse vaillamment devant ses ennemis mÃªme s'ils sont plus _puissants.", 91, 1250000, 190, 58);
	Data::OpMons::listOp.try_emplace(59, 110, 80, 100, 80 , 95, 90, "Arcanin", Type::FEU, Type::NOTHING, 0, -1, new E_Nope(),Model::Data::OpMon::evs[59], 1.9, 155, "Son aboiement est tout simplement majestueux. On ne peut que ramper à  ses pieds après l'avoir entendu.", 213, 1250000, 75, 59);
	Data::OpMons::listOp.try_emplace(60, 50, 40, 40, 40, 90, 40, "Ptitard", Type::EAU, Type::NOTHING, 0, 25, new E_Level(61, 25), Model::Data::OpMon::evs[60], 0.6, 12.4, "Sa peau est si mince qu'on voit ses organes internes. Il tient à  peine sur ses nouveaux pieds.", 77, 1059860, 255, 60);
	Data::OpMons::listOp.try_emplace(61, 65, 65, 50, 50, 90, 65, "TÃªtarte", Type::EAU, Type::NOTHING, 0, -1, new E_Item(62, Item::getItem("Pierre Eau")), Model::Data::OpMon::evs[61], 1, 20, " Ce Pokémon amphibie transpire continuellement quand il est hors de l'eau afin d'hydrater son corps.", 131, 1059860, 120, 61);
	Data::OpMons::listOp.try_emplace(62, 95, 95, 70, 90, 70, 90, "Tartard", Type::EAU, Type::COMBAT, 0, -1, new E_Nope(), Model::Data::OpMon::evs[62], 1.3, 54, "Il possède de sacrés biscoteaux. Il peut parcourir sans relâche l'Océan Pacifique.", 185, 1059860, 45, 62);
	Data::OpMons::listOp.try_emplace(63, 20, 15, 105, 55, 90, 25, "Abra", Type::PSY, Type::NOTHING, 0, 16, new E_Level(64, 16), Model::Data::OpMon::evs[63], 0.9, 19.5, "Il prévoit les attaques futures et se téléporte pour se mettre à  l'abri et éviter le combat.", 75, 1059860, 200, 63);
	Data::OpMons::listOp.try_emplace(64, 35, 30, 120, 70, 105, 40, "Kadabra", Type::PSY, Type::NOTHING, 0, -1, new E_Trade(65), Model::Data::OpMon::evs[64], 1.3, 56.5, "En utilisant ses pouvoirs, il émet des ondes alphas et cause des distorsions électroniques.", 145, 1059860, 100, 64);
	Data::OpMons::listOp.try_emplace(65, 50, 45, 135, 95, 120, 55, "Alakazam", Type::PSY, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[65], 1.5, 4, "Son cerveau hors du commun peut effectuer des opérations à  la vitesse d'un ordinateur. Il a un QI de 5 000.", 186, 1059860, 50, 65);
	Data::OpMons::listOp.try_emplace(66, 80, 50, 35, 35, 35, 70, "Machoc", Type::COMBAT, Type::NOTHING, 0, 28, new E_Level(67, 28), Model::Data::OpMon::evs[66], 0., 19.5, "Son corps est essentiellement composé de muscles. MÃªme s'il a la taille d'un petit enfant, il peut soulever 100 adultes avec ses bras.", 75, 1059860, 180, 66);
	Data::OpMons::listOp.try_emplace(67, 100, 70, 50, 60, 45, 80, "Machopeur", Type::COMBAT, Type::NOTHING, 0, -1, new E_Trade(68), Model::Data::OpMon::evs[67], 1.5, 70.5, "Son corps est si puissant qu'il lui faut une ceinture de force pour équilibrer ses mouvements.", 146, 1059860, 90, 67);
	Data::OpMons::listOp.try_emplace(68, 130, 80, 65, 85, 55, 90, "Mackogneur", Type::COMBAT, Type::NOTHING, 0, -1, new E_Nope(),Model::Data::OpMon::evs[68], 1.6, 130, "Ses deux paires de bras permettent à  Mackogneur d'envoyer une série de 1000 coups de poing en 2s.", 193, 1059860, 45, 68);
	Data::OpMons::listOp.try_emplace(69, 75, 35, 70, 30, 40, 50, "Chétiflor", Type::PLANTE, Type::POISON, 0, 21, new E_Level(70, 21), Model::Data::OpMon::evs[69], 0.7, 4, "Son bourgeon ressemble à  un visage humain. Selon la légende, Chétiflor serait un type de mandragore légendaire.", 84, 1059860, 255, 69);
	Data::OpMons::listOp.try_emplace(70, 90, 50, 85, 45, 55, 65, "Boustiflor", Type::PLANTE, Type::POISON, 0, -1, new E_Item(71, Item::getItem("Pierre Plante")), Model::Data::OpMon::evs[70], 1, 6.4, "Il crache de la Poudre Toxik pour immobiliser sa proie et il l'achève avec de l'Acide.", 151, 1059860, 120, 70);
	Data::OpMons::listOp.try_emplace(71, 105, 65, 100, 70, 70, 80, "Empiflor", Type::PLANTE, Type::POISON, 0, -1, new E_Nope(), Model::Data::OpMon::evs[71], 1.7, 15.5, "Tout corps ingéré par ce Pokémon est systématiquement dissout en bouillie.", 191, 1059860, 45, 71);
      */Data::OpMons::listOp.try_emplace(72, 40, 35, 50, 100, 70, 40, "Coassdethé", Type::EAU, Type::POISON, 0, 30, new E_Level(73, 30),Model::Data::OpMon::evs[72], 0.4, 4, "La tasse dans laquelle il vit est comme une carapace. Lorsqu'il s'énerve, celle ci dégage une vapeur brulante.", 105, 1250000, 190, 72);
      Data::OpMons::listOp.try_emplace(73, 70, 65, 80, 120, 100, 80, "Ebouillanthé", Type::EAU, Type::FEU, 0, -1, new E_Nope(), Model::Data::OpMon::evs[73], 1.6, 55, "Il vit dans les sources d'eau chaude. Les tâches rouges sur son corps dégagent constamment de la vapeur brulante, son dos a le même effet qu'un grill.", 205, 1250000, 60, 73);
      /*Data::OpMons::listOp.try_emplace(74, 80, 100, 30, 30, 20, 40, "Racaillou", Type::ROCHE, Type::SOL, 0, 25, new E_Level(75, 25),Model::Data::OpMon::evs[74], 0.4, 20, "Il vit dans les plaines ou les montagnes. On le confond souvent avec un petit caillou.", 73, 1059860, 255, 74);
	Data::OpMons::listOp.try_emplace(75, 95, 115, 45, 45, 35, 55, "Gravalanch", Type::ROCHE, Type::SOL, 0, -1, new E_Trade(76), Model::Data::OpMon::evs[75], 1, 105, "D'une nature téméraire, il se moque de perdre des parties de son corps quand il dévale les pentes.", 134, 1059860, 120, 75);
	Data::OpMons::listOp.try_emplace(76, 120, 130, 55, 65, 45, 80, "Grolem", Type::ROCHE, Type::SOL, 0, -1, new E_Nope(), Model::Data::OpMon::evs[76], 1.4, 300, "Aucun explosif ne pourrait entamer sa carapace de pierre. Il mue une fois par an.", 177, 1059860, 45, 76);
	Data::OpMons::listOp.try_emplace(77, 85, 55, 65, 65, 90, 50, "Ponyta", Type::FEU, Type::NOTHING, 0, 40, new E_Level(48, 40),Model::Data::OpMon::evs[77], 1, 30, "    Chancelantes à  la naissance, ses pattes deviennent très vite sà»res et solides à  force de galoper.", 152, 1000000, 190, 77);
	Data::OpMons::listOp.try_emplace(78, 100, 70, 80, 80, 105, 65, "Galopa", Type::FEU, Type::NOTHING, 0, -1, new E_Nope(), Model::Data::OpMon::evs[78], 1.7, 95, "Au grand galop, sa crinière de feu disperse au vent une myriade d'étincelles ardentes.", 192, 1000000, 60, 78);
	Data::OpMons::listOp.try_emplace(79, 65, 65, 40, 40, 15, 90, "Ramoloss", Type::EAU, Type::PSY, 0, 37, new E_Level(80, 37), Model::Data::OpMon::evs[79], 1.2, 36, "Il est tellement paresseux qu'il lui faut une journée pour remarquer qu'on lui mord la queue.", 99, 1000000, 190, 79);
	Data::OpMons::listOp.try_emplace(80, 75, 110, 100, 80, 30, 95, "Flagadoss", Type::EAU, Type::PSY, 0, -1, new E_Nope(), Model::Data::OpMon::evs[80], 1.6, 78.5, "Le Kokiyas accroché à  sa queue est friand de ce qu'il dévore et ne veut pas lâcher prise.", 164, 1000000, 75, 80);
	Data::OpMons::listOp.try_emplace(81, 35, 70, 95, 55, 45, 25, "Magneti", Type::ELECTRIQUE, Type::ACIER, 0, 30, new E_Level(81, 30), Model::Data::OpMon::evs[81],0.3, 6, "Les parties sur les côtés de son corps génèrent une énergie lui permettant de léviter.", 89, 1000000, 190, 81);
	Data::OpMons::listOp.try_emplace(82, 60, 95, 120, 70, 70, 50, "Magnéton", Type::ELECTRIQUE, Type::ACIER, 0, -1, new E_Land(0, "Grotte Electrac"), Model::Data::OpMon::evs[82], 1, 60, "Des groupes apparaissent si des taches solaires couvrent le soleil. Il brouillent les télévisions.", 161, 1000000, 60, 82);
	Data::OpMons::listOp.try_emplace(83, 65, 55, 58, 62, 52, 52, "Canarticho", Type::NORMAL, Type::VOL, 0, -1, new E_Nope(), Model::Data::OpMon::evs[83], 0., 15, "Il utilise le légume qu'il tient comme s'il s'agissait d'une épée.", 94, 1000000, 45, 83);
	Data::OpMons::listOp.try_emplace(84, 85, 45, 35, 35, 75, 35, "Doduo", Type::NORMAL, Type::VOL, 0, 31, new E_Level(31, 85), Model::Data::OpMon::evs[84], 1.4, 39.2, "Ses deux cerveaux semblent communiquer leurs émotions grâce à  un lien télépathique.", 96, 1000000, 190, 84);
	Data::OpMons::listOp.try_emplace(85, 110, 70, 60, 60, 110, 60, "Dodrio", Type::NORMAL, Type::VOL, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1., 85.2, "Un ennemi ne faisant pas attention à  l'une des trois tÃªtes pendant une seconde se fait picorer.", 158, 1000000, 45, 85);
	Data::OpMons::listOp.try_emplace(86, 45, 55, 45, 70, 45, 65, "Otaria", Type::EAU, Type::NOTHING, 0, 34, new E_Level(34, 87), {Stats.DEFSPE}, 1.1, 90, "Un habitant des icebergs. En mer, il utilise la corne sur sa tÃªte pour briser la banquise.", 100, 1000000, 190, 86);
	Data::OpMons::listOp.try_emplace(87, 70, 80, 70, 95, 70, 90, "Lamantine", Type::EAU, Type::GLACE, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE}, 1.7, 120, "Son corps hydrodynamique glisse dans l'eau. Plus l'eau est froide plus il se sent à  l'aise.", 176, 1000000, 75, 87);
	Data::OpMons::listOp.try_emplace(88, 80, 50, 40, 50, 25, 80, "Tadmorv", Type::POISON, Type::NOTHING, 0, 38, new E_Level(38, 89), {Stats.HP}, 0.9, 30, "Vivant dans des tas d'ordures, il se nourrit des déchets polluants rejetés par les usines.", 90, 1000000, 190, 88);
	Data::OpMons::listOp.try_emplace(89, 105, 75, 65, 100, 50, 105, "Grotadmorv", Type::POISON, Type::NOTHING, 0, -1, new E_Nope(), {Stats.HP, Stats.ATK}, 1.2, 30, "Son corps exsude un fluide toxique qui tue instantanément les plantes et les arbres au contact.", 157, 1000000, 75, 89);
	*/Data::OpMons::listOp.try_emplace(90, 65, 100, 45, 25, 40, 30, "Tétaflore", Type::EAU, Type::PLANTE, 0, -1, new E_Nope(), {Stats::DEF}, 0.3, 4, "Si vous le regardez dans les yeux, vous serez entourés de d'eau et de fleurs instantanement, le temps qu'ils vous tuent.", 97, 1250000, 190, 90);
	/*Data::OpMons::listOp.try_emplace(91, 95, 180, 85, 45, 70, 50, "Crustabri", Type::EAU, Type::GLACE, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEF}, 1.5, 132.5, "Sa coquille est extrÃªmement résistante. Rien ne peut la détruire, pas mÃªme une bombe. Il ne l'ouvre que lorsqu'il attaque.", 203, 1250000, 60, 91);
	Data::OpMons::listOp.try_emplace(92, 35, 30, 100, 35, 80, 30, "Fantominus", Type::SPECTRE, Type::POISON, 0, 25,new E_Level(93, 25), {Stats.ATKSPE}, 1.3, 0.1, "Son corps composé de gaz toxique pourrait asphyxier n'importe qui en quelques secondes.", 95, 1059860, 190, 92);
	Data::OpMons::listOp.try_emplace(93, 50, 45, 115, 55, 95, 45, "Spectrum", Type::SPECTRE, Type::POISON, 0, -1, new E_Trade(94), {Stats.ATK, Stats.ATK}, 1.6, 0.2, "Il vole l'énergie vitale de l'ennemi d'un coup de langue gazeuse. Il aime chasser dans l'ombre.", 126, 1059860, 90, 93);
	Data::OpMons::listOp.try_emplace(94, 65, 60, 130, 75, 110, 60, "Ectoplasma", Type::SPECTRE, Type::POISON, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.5, 40.5, "Si vous frissonnez soudainement, c'est qu'un Ectoplasma en veut à  votre vie. Vous ne pouvez y échapper. Abandonnez toute espérance.", 190, 1059860, 45, 94);
	Data::OpMons::listOp.try_emplace(95, 45, 160, 30, 45, 70, 35, "Onix", Type::ROCHE, Type::SOL, 0, -1, new E_Nope(), {Stats.DEF}, 8., 210, "Onix vit généralement sous terre. Il cherche de la nourriture en creusant à  plus de 80km/h.", 108, 1000000, 45, 95);
	Data::OpMons::listOp.try_emplace(96, 48, 45, 43, 90, 42, 60, "Soporifik", Type::PSY, Type::NOTHING, 0, 26,new E_Level(97, 26), {Stats.DEFSPE}, 1, 32, "Si vous pensez avoir rÃªvé mais que vous ne vous en souvenez pas, c'est que Soporifik a tout mangé.", 102, 1000000, 190, 96);
	Data::OpMons::listOp.try_emplace(97, 73, 70, 73, 115, 67, 85, "Hypnomade", Type::PSY, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE}, 1, 75, "La vue de son pendule oscillant endort en trois secondes, même quand on vient de se réveiller.", 165, 1000000, 75, 97);
	Data::OpMons::listOp.try_emplace(98, 105, 90, 25, 25, 50, 30, "Krabby", Type::EAU, Type::NOTHING, 0, 28,new E_Level(99, 28), {Stats.ATK}, 0.4, 6.5, "Il creuse son terrier sur des plages sablonneuses. Ses pinces repoussent si on les brise.", 115, 1000000, 255, 98);
	Data::OpMons::listOp.try_emplace(99, 130, 115, 50, 50, 75, 55, "Kraboss", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1.3, 60, "Sa pince devient énorme. S'il la soulève trop vite, il risque de perdre l'équilibre.", 206, 1000000, 60, 99);
	Data::OpMons::listOp.try_emplace(100, 76, 54, 89, 48, 60, 150, "MagMortis", Type::FEU, Type::ROCHE, 0, -1,nullptr, Model::Data::OpMon::evs[100], 3.64, 532, "Cet Opmon oublié au fil du temps est à l'origine de la disparition d'une ancienne génération de monstres combattants.", 200, 1850000, 4, 100);
	Data::OpMons::listOp.try_emplace(101, 50, 70, 80, 80, 140, 60, "Electrode", Type::ELECTRIQUE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE}, 1.2, 66.6, "Il stocke tellement d'énergie dans son corps qu'une simple secousse peut le faire exploser.", 150, 1000000, 60, 101);
	Data::OpMons::listOp.try_emplace(102, 40, 80, 60, 45, 140, 60, "Noeunoeuf", Type::PLANTE, Type::PSY, 0, -1, new E_Item(103, Item::getItem("Pierre Plante")), {Stats.DEF}, 0.4, 2.5, "Il stocke tellement d'énergie dans son corps qu'une simple secousse peut le faire exploser.", 98, 1250000, 90, 102);
	Data::OpMons::listOp.try_emplace(103, 95, 85, 125, 65, 55, 95, "Noadkoko", Type::PLANTE, Type::PSY, 0, -1, new E_Nope(), {Stats.DEF}, 2, 120, "Il stocke tellement d'énergie dans son corps qu'une simple secousse peut le faire exploser.", 215, 1250000, 45, 103);
	Data::OpMons::listOp.try_emplace(104, 50, 95, 40, 50, 35, 50, "Osselait", Type::SOL, Type::NOTHING, 0, 28,new E_Level(105, 28), {Stats.DEF}, 0.4, 6.5, "Il porte constamment le crâne de sa mère. Personne ne sait à  quoi il ressemble sans ce crâne.", 87, 1000000, 190, 104);
	Data::OpMons::listOp.try_emplace(105, 80, 110, 50, 80, 45, 60, "Ossatueur", Type::SOL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEF}, 1, 45, "Il porte constamment le crâne de sa mère. Personne ne sait à  quoi il ressemble sans ce crâne.", 124, 1000000, 75, 105);
	*/Data::OpMons::listOp.try_emplace(106, 120, 53, 35, 110, 87, 50, "Philynx", Type::COMBAT, Type::PLANTE, 0, -1, new E_Nope(), {Stats::ATK, Stats::ATK}, 1.4, 49, "Ils sont toujours là, mais on ne les voient jamais, surtout la nuit, à moins d'avoir l'oeil de Lynx", 139, 1000000, 45, 106);
	/*Data::OpMons::listOp.try_emplace(107, 105, 79, 35, 110, 76, 50, "Tygnon", Type::COMBAT, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE}, 1.4, 50.2, "MÃªme le béton cède sous ses poings dévastateurs. Au combat, il s'essouffle au bout de 3 minutes.", 140, 1000000, 45, 107);
	Data::OpMons::listOp.try_emplace(108, 55, 75, 60, 75, 30, 90, "Excelangue", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.HP, Stats.HP}, 1.2, 65.5, "Chaque fois qu'Excelangue découvre quelque chose de nouveau, il le lèche. Sa mémoire est basée sur le goà»t et la texture des objets. Il n'aime pas les choses acides.", 127, 1000000, 45, 108);
	Data::OpMons::listOp.try_emplace(109, 65, 95, 60, 45, 35, 40, "Smogo", Type::POISON, Type::NOTHING, 0, 35,new E_Level(110, 35), {Stats.DEF}, 0.6, 1, "Son corps très fin en forme de ballon est rempli d'un horrible gaz toxique. L'air est nauséabond à  proximité de ce Pokémon.", 114, 1000000, 190, 109);
	Data::OpMons::listOp.try_emplace(110, 90, 120, 85, 70, 60, 65, "Smogogo", Type::POISON, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEF}, 1.2, 9.5, "Il peut arriver que deux Smogo mutent et s'associent pour former un Smogogo, mais c'est très rare.", 173, 1000000, 60, 110);
	Data::OpMons::listOp.try_emplace(111, 85, 95,  30, 30, 25, 30, "Rhinocorne", Type::SOL, Type::ROCHE,0, 42, new E_Level(112, 42), {Stats.DEF}, 1, 115, "Ses petites jambes ne lui permettent pas de tourner facilement. Il ne peut charger que tout droit.", 135, 1250000, 120, 111);
	Data::OpMons::listOp.try_emplace(112, 130, 120, 45, 45, 40, 105, "Rhinoféros", Type::SOL, Type::ROCHE,0, -1, new E_TradeItem(0, Item::getItem("Protecteur")), {Stats.ATK, Stats.ATK}, 1.9, 120, "Son épiderme très épais lui permet de survivre dans un environnement où il fait plus de 2000Ã‚Â°c.", 204, 1250000, 60, 112);
	Data::OpMons::listOp.try_emplace(113, 5, 5, 35, 105, 50, 250, "Leveinard", Type::NORMAL, Type::NOTHING,0, -1, new E_Nope(), {Stats.HP, Stats.HP}, 1.1, 34.6, "Il est censé apporter la joie. Ce Pokémon charitable offre ses oeufs aux blessés.", 395, 800000, 30, 113);
	Data::OpMons::listOp.try_emplace(114, 55, 115, 100, 40, 60, 65, "Saquedeneu", Type::PLANTE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEF}, 1, 35, "Il paralyse tout ce qui bouge avec ses lianes. Elles vous chatouillent si vous Ãªtes capturé.", 166, 1000000, 45, 114);
	Data::OpMons::listOp.try_emplace(115, 95, 80, 40, 80, 90, 105, "Kangourex", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.HP, Stats.HP}, 2.2, 80, "Il élève ses petits dans sa poche ventrale. Il attend d'être en lieu sà»r pour les laisser jouer dehors.", 175, 1000000, 45, 115);
	Data::OpMons::listOp.try_emplace(116, 40, 70, 70, 25, 60, 30, "Hypotrempe", Type::EAU, Type::NOTHING, 0, 32, new E_Level(117, 32), {Stats.ATKSPE}, 0.4, 8, "Il abat les insectes volants en leur tirant un jet d'encre depuis la surface de l'eau. Ses tirs sont toujours précis.", 83, 1059860, 255, 116);
	Data::OpMons::listOp.try_emplace(117, 65, 95, 95, 45, 85, 55, "Hypocéan", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEF, Stats.ATKSPE}, 1.2, 25, "Il peut nager à  l'envers en agitant ses petites nageoires pectorales.", 155, 1000000, 75, 117);
	Data::OpMons::listOp.try_emplace(118, 67, 60, 35, 50, 63, 45, "Poissirène", Type::EAU, Type::NOTHING, 0, 33, new E_Level(119, 33), {Stats.ATK}, 0.6, 15, "Ses nageoires dorsales et pectorales bougent avec élégance. Il est surnommé le danseur des flots", 111, 1000000, 225, 118);
	Data::OpMons::listOp.try_emplace(119, 92, 65, 65, 80, 68, 80, "Poissoroy", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1.3, 39, "Il niche dans les rochers du ruisseau qu'il évide avec sa corne. Il donnerait sa vie pour ses Ã…Â’ufs.", 170, 1000000, 60, 119);
	Data::OpMons::listOp.try_emplace(120, 45, 55, 70, 55, 85, 30, "Stari", Type::EAU, Type::NOTHING, 0, -1, new E_Item(121, Item::getItem("Pierre Eau")), {Stats.SPE}, 0., 34.5, "MÃªme si son corps est détruit, il peut se régénérer aussi longtemps que son coeur est en bon état.", 106, 1250000, 225, 120);
	Data::OpMons::listOp.try_emplace(121, 75, 85, 100, 85, 115, 60, "Staross", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE}, 1.1, 80, "Son cÃ…Â“ur brille des couleurs de l'arc-en-ciel. On raconte que c'est une pierre précieuse.", 207, 1250000, 60, 121);
	Data::OpMons::listOp.try_emplace(122, 45, 65, 100, 120, 90, 40, "M.Mime", Type::PSY, Type::FEE, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE}, 1.3, 54.5, "Il adore imiter les gens. On le dit capable de créer de véritables murs pour les migrants juste en les mimant.", 136, 10000000, 45, 122);
	Data::OpMons::listOp.try_emplace(123, 110, 80, 55, 80, 105, 70, "Insecateur", Type::INSECTE, Type::VOL, 0, -1, new E_Nope(), {Stats.ATK}, 1.5, 56, "Il fauche les herbes avec ses lames acérées. Il bouge si vite qu'on ne peut le voir à  l'Ã…Â“il nu.", 187, 1000000, 45, 123);//TODO evolution a completer
	Data::OpMons::listOp.try_emplace(124, 50, 35, 115, 95, 95, 65, "Lippoutou", Type::GLACE, Type::PSY, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE}, 1.4, 40.6, "Elle communique en utilisant un langage qui semble Ãªtre humain. Des recherches sont en cours pour déterminer ce qu'elle dit.", 137, 1000000, 45, 124);
	Data::OpMons::listOp.try_emplace(125, 83, 87, 95, 85, 105, 65, "Elektek", Type::ELECTRIQUE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE}, 1.1, 30, "Il adore se nourrir d'électricité. Il apparaà®t occasionnellement près des grandes centrales électriques.", 156, 1000000, 45, 125);
	Data::OpMons::listOp.try_emplace(126, 95, 57, 100, 85, 93, 65, "Magmar", Type::FEU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE}, 1.3, 44.5, "On trouve ce Pokémon près des bouches de volcans. Son corps incandescent atteint 1 200 Ã‚Â°C.", 127, 1000000, 45, 126);
	Data::OpMons::listOp.try_emplace(127, 125, 100, 55, 70, 85, 65, "Scarabrute", Type::INSECTE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1.5, 55, "Il attaque sauvagement avec ses cornes. En hiver, il se cache au plus profond des forÃªts.", 200, 1250000, 45, 127);
	Data::OpMons::listOp.try_emplace(128, 100, 95, 40, 70, 110, 75, "Tauros", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.SPE}, 1.4, 88.4, "Juste avant d'utiliser Charge, ce Pokémon agite frénétiquement ses trois grandes queues.", 211, 1250000, 45, 128);
	Data::OpMons::listOp.try_emplace(129, 10, 55, 15, 20, 80, 20, "Magicarpe", Type::EAU, Type::NOTHING, 0, 20, new E_Level(130, 20), {Stats.SPE}, 0.9, 10, "Ce pokémon ne mérite mÃªme pas  de description tellement il respire l'inutilité", 20, 1250000, 255, 129);
	Data::OpMons::listOp.try_emplace(130, 95, 125, 79, 60, 100, 81, "Léviator", Type::EAU, Type::VOL, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE}, 6.5, 235, "La littérature ancienne fait état d'un Léviator qui aurait rasé un village sous le coup de la colère.", 214, 1250000, 40, 130);
	Data::OpMons::listOp.try_emplace(131, 85, 80, 85, 95, 60, 130, "Lokhlass", Type::EAU, Type::GLACE, 0, -1, new E_Nope(), {Stats.HP, Stats.HP}, 2.5, 220, "Ils sont d'une nature gentille. Comme ils se défendent rarement, ils sont en voie d'extinction.", 219, 1250000, 45, 131);
	Data::OpMons::listOp.try_emplace(132, 48, 48, 48, 48, 48, 48, "Métamorph", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.HP}, 0.3, 4, "Métamorph peut modifier sa structure moléculaire pour prendre d'autres formes. Lorsqu'il essaie de se transformer de mémoire, il lui arrive de se tromper sur certains détails.", 61, 1000000, 35, 132);
	Data::OpMons::listOp.try_emplace(133, 55, 50, 45, 65, 55, 55, "Evoli", Type::NORMAL, Type::NOTHING, 0, -1, new E_Item(134, Item::getItem("Pierre Eau")), {Stats.DEFSPE}, 0.3, 6.5, "L'ADN de ce Pokémon très particulier recèle de nombreuses possibilités d'évolution.", 92, 1000000, 45, 133);
	Data::OpMons::listOp.try_emplace(134, 65, 60, 110, 95, 65, 130, "Aquali", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.HP, Stats.HP}, 1, 29, "Il a évolué pour s'adapter au milieu aquatique. Il peut se fondre et disparaà®tre dans l'élément liquide.",  196, 1000000, 45, 134);
	Data::OpMons::listOp.try_emplace(135, 65, 60, 110, 95, 130, 65, "Voltali", Type::ELECTRIQUE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE}, 0., 24.5, "Chaque poil sur son corps se dresse quand il se charge en électricité.", 197, 1000000, 45, 135);
	Data::OpMons::listOp.try_emplace(136, 130, 60, 95, 110, 65, 65, "Pyroli", Type::FEU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 0.9, 25.9, "Son corps contient une glande enflammée. Sa température monte à  900Ã‚Â°C avant le combat.", 198, 1000000, 45, 136);
	Data::OpMons::listOp.try_emplace(137, 60, 70, 85, 75, 40, 65, "Porygon", Type::NORMAL, Type::NOTHING, 0, -1, new E_TradeItem(0, Item::getItem("Ameliorator")), {Stats.ATK}, 0., 36.5, "Ce Pokémon a été développé en Java, il adore se fofiler dans les programmes pour tout modifier.", 133, 1000000, 45, 137);
	Data::OpMons::listOp.try_emplace(138, 40, 100, 90, 55, 35, 35, "Amonita", Type::ROCHE, Type::EAU, 0, 40,new E_Level(138, 40), {Stats.DEF}, 0.4, 7.5, "Recréé à  partir d'un fossile, il utilise l'air dans sa coquille pour s'enfoncer dans l'eau ou faire surface.", 99, 1000000, 45, 138);
	Data::OpMons::listOp.try_emplace(139, 60, 125, 115, 70, 55, 70, "Amonistar", Type::ROCHE, Type::EAU, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEF}, 1, 35, "Une fois enroulé autour de sa proie, il ne la laisse pas repartir et la dévore avec ses crocs.", 199, 1000000, 45, 139);
	Data::OpMons::listOp.try_emplace(140, 80, 90, 55, 45, 55, 30, "Kabuto", Type::ROCHE, Type::EAU, 0, 40,new E_Level(140, 40), {Stats.DEF}, 0.5, 11.5, "Ce Pokémon a été reconstitué à  partir du fossile d'une ancienne créature. Il se protège à  l'aide de sa carapace.", 99, 1000000, 45, 140);
	Data::OpMons::listOp.try_emplace(141, 115, 105, 65, 70, 80, 60, "Kabutops", Type::ROCHE, Type::EAU, 0, -1,new E_Level(140, 40), {Stats.ATK, Stats.ATK}, 1.3, 40.5, "C'est un très bon nageur. Il lacère sa proie de ses longues griffes et en absorbe les fluides corporels.", 199, 1000000, 45, 141);
	Data::OpMons::listOp.try_emplace(142, 105, 65, 60, 75, 130, 80, "Ptéra", Type::ROCHE, Type::VOL, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE}, 1., 59, "Ce terrible Pokémon a dominé les cieux d'une autre époque, terrorisant ses ennemis.", 202, 1250000, 45, 142);
	Data::OpMons::listOp.try_emplace(143, 110, 65, 65, 110, 30, 160, "Ronflex", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.HP, Stats.HP}, 2.1, 460, "Les journées de Ronflex se résument aux repas et aux siestes. IL est tellement gentil que les enfants n'hésitent pas à  jouer sur son énorme ventre.", 154, 1250000, 25, 143);
	Data::OpMons::listOp.try_emplace(144, 85, 100, 95, 125, 85, 90, "Artikodin", Type::ELECTRIQUE, Type::VOL, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 1.7, 55.4, "Le légendaire oiseau des glaces. On dit qu'il apparaà®t aux gens perdus dans les sommets.", 215, 1250000, 3, 144);
	Data::OpMons::listOp.try_emplace(145, 90, 85, 125, 90, 100, 90, "Electhor", Type::ELECTRIQUE, Type::VOL, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.6, 52.6, "Un Pokémon Oiseau légendaire dont on dit qu'il vit dans les nuages d'orage. Il contrôle la foudre.", 216, 1250000, 3, 145);
	Data::OpMons::listOp.try_emplace(146, 100, 90, 125, 85, 90, 90, "Sulfura", Type::FEU, Type::VOL, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 2, 60, "C'est un Pokémon oiseau légendaire capable de contrôler le feu. On raconte que lorsqu'il est blessé, il se baigne dans le magma d'un volcan pour se soigner.", 217, 1250000, 3, 146);
	Data::OpMons::listOp.try_emplace(147, 64, 45, 50, 50, 50, 41, "Minidraco", Type::DRAGON, Type::NOTHING, 0, 0,new E_Level(148, 30), {Stats.ATK}, 1., 3.3, "Minidraco mue constamment, renouvelant sans arrÃªt sa peau. En effet, l'énergie vitale de son corps augmente régulièrement et sa mue lui permet d'éviter d'atteindre des niveaux incontrôlables.", 67, 1250000, 45, 147);
	Data::OpMons::listOp.try_emplace(148, 84, 65, 70, 70, 70, 61, "Draco", Type::DRAGON, Type::NOTHING, 0, 1,new E_Level(149, 55), {Stats.ATK, Stats.ATK}, 4, 16.5, "Draco stocke une quantité d'énergie considérable dans son corps. On raconte qu'il peut modifier les conditions climatiques autour de lui en déchargeant l'énergie contenue dans les cristaux de son cou et de sa queue.", 144, 1250000, 45, 148);
	Data::OpMons::listOp.try_emplace(149, 134, 95, 100, 100, 80, 91, "Dracoloss", Type::DRAGON, Type::VOL, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK, Stats.ATK}, 2.2, 210, "On raconte qu'il vit quelque part en mer. Il guide les équipages naufragés jusqu'à  la terre ferme.", 218, 1250000, 45, 149);
	Data::OpMons::listOp.try_emplace(150, 110, 90, 154, 90, 130, 106, "Mewtwo", Type::PSY, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 2, 122, "Il est le fruit de nombreuses expériences génétiques horribles et malsaines.", 220, 1250000, 3, 150);
	Data::OpMons::listOp.try_emplace(151, 100, 100, 100, 100, 100, 100, "Mew",  Type::PSY, Type::NOTHING, 0, -1, new E_Nope(), {Stats.PV, Stats.PV, Stats.PV}, 0.4, 4, "Nombre de scientifiques voient en lui l'ancÃªtre des Pokémon car il maà®trise toutes leurs capacités.", 64, 1059860, 45, 151);
	Data::OpMons::listOp.try_emplace(152, 49, 65, 45, 69, 45, 45, "Germignon", Type::PLANTE, Type::NOTHING, 0, 16, new E_Level(153, 16), {Stats.DEFSPE}, 0.9, 6.4, "Un doux parfum émane de la feuille placée sur sa tÃªte. Il est très gentil et aime dormir au soleil.", 64, 1059860, 45, 152);
	Data::OpMons::listOp.try_emplace(153, 62, 80, 63, 80, 60, 60, "Macronium", Type::PLANTE, Type::NOTHING, 0, 32, new E_Level(154, 32), {Stats.DEF, Stats.DEFSPE}, 1.2, 15.,  "Le collier de bourgeons Ã  son cou répand un arÃ´me épicé qui vous donne du tonus", 141, 1059860, 45, 153);
	Data::OpMons::listOp.try_emplace(154, 82, 100, 83, 100, 80, 80 , "Méganium", Type::PLANTE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEFSPE,Stats.DEFSPE}, 1., 100.5, "L'arÃ´me qui émane de ses pétales contient une substance qui calme les pulsions sexuelles.", 208, 1059860, 45, 154);
	Data::OpMons::listOp.try_emplace(155, 52, 43, 60, 50, 65, 39 , "Héricendre", Type::FEU, Type::NOTHING, 0, 14, new E_Level(156, 14), {Stats.SPE}, 0.5, 7.9, " Il est timide et se roule en boule pour se protéger. Attaqué, il s'enflamme le dos pour riposter.", 65, 1059860, 45, 155);
	Data::OpMons::listOp.try_emplace(156, 64, 58, 80, 65, 80, 58 ,"Feurisson", Type::FEU, Type::NOTHING, 0, 36, new E_Level(157, 36), {Stats.ATKSPE, Stats.SPE}, 0.9, 19, "Avant chaque combat, il tourne le dos et montre la puissance de sa queue", 142, 1059860, 45, 156);
	Data::OpMons::listOp.try_emplace(157, 84, 78, 109, 85, 100, 78, "Typlosion", Type::FEU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.7, 79.5, "Il a un coup secret dévastateur. En frottant sa fourrure ardente, il crée une forte explosion.", 209, 1059860, 45, 157);
	Data::OpMons::listOp.try_emplace(158, 65, 64, 44, 48, 43, 50, "Kaiminus", Type::EAU, Type::NOTHING, 0, 18, new E_Level(158, 18), {Stats.ATK}, 9,5, "Petit mais costaud, il n'hésite pas Ã  mordre tout ce qui passe Ã  portée de ses dents.", 66, 1059860, 45, 158);
	Data::OpMons::listOp.try_emplace(159, 80, 80, 59, 63, 58, 65, "Crocrodil", Type::EAU, Type::NOTHING, 0, 30, new E_Level(159, 30), {Stats.ATK, Stats.DEF}, 1.1, 25, "Quand il perd un croc, il en repousse un autre. Sa bouche est en permanence composée de 48 dents.", 143, 1059860, 45, 159);
	Data::OpMons::listOp.try_emplace(160, 105, 100, 79, 83, 78, 85, "Aligatueur", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK, Stats.DEF}, 2.3, 88., "Ce Pokémon Ã  l'air pataud est capable d'attaquer Ã  la vitesse de l'éclair pour mordre sa proie.", 210, 1059860, 45, 160);
	Data::OpMons::listOp.try_emplace(161, 46, 34, 35, 45, 20, 35, "Fouinette", Type::NORMAL, Type::NOTHING, 0, 15, new E_Level(162, 15), {Stats.ATK}, 0., 6, "S'il fait le guet, il prévient les autres d'un danger en criant et en frappant avec sa queue le sol.", 57, 1000000, 255, 161);
	Data::OpMons::listOp.try_emplace(162, 76, 64, 45, 55, 90, 85, "Fouinar", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE}, 1., 32.5, "Il fabrique un nid qui convient Ã  son corps très fin, et oÃ¹ lui seul peut entrer.", 116, 1000000, 90, 162);
	Data::OpMons::listOp.try_emplace(163, 30, 30, 36, 56, 50, 60, "Hoothoot", Type::NORMAL, Type::VOL, 0, 20, new E_Level(164, 20), {Stats.PV}, 0.7, 21.2, "Il a un sens du timing parfait. Il reste toujours en rythme en balanÃ§ant la tÃªte.", 58, 1000000, 255, 163);
	Data::OpMons::listOp.try_emplace(164, 50, 50, 86, 96, 70, 100, "Noarfang", Type::NORMAL, Type::VOL, 0, -1, new E_Nope(), {Stats.PV, Stats.PV}, 1.6, 40., "Quand il réfléchit, il tourne sa tête sur 180° pour optimiser son mode de pensée.", 162, 1000000, 90, 164);
	Data::OpMons::listOp.try_emplace(165, 20, 30, 40, 80, 55, 40, "Coxy", Type::INSECTE, Type::VOL, 0, 18, new E_Level(166, 18), {Stats.DEFSPE}, 1, 10., "Il est timide et reste près de ses semblables. Il a un sens du toucher très développé.", 54, 1000000, 255, 165);
	Data::OpMons::listOp.try_emplace(166, 35, 50, 55, 110, 85, 55, "Coxyclaque", Type::INSECTE, Type::VOL, 0, -1, new E_Nope(), {Stats.DEFSPE}, 1.4, 35.6, "Les points sur son dos deviennent plus grands ou plus petits selon le nombre d'étoiles dans le ciel.", 134, 800000, 90, 166);
	Data::OpMons::listOp.try_emplace(167, 60, 40, 40, 40, 30, 40, "Mimigal", Type::INSECTE, Type::POISON, 0, 22, new E_Level(168, 22), {Stats.ATK}, 0.5, 8.5, "Il tisse une toile en utilisant un fil fin mais solide, puis il attend tranquillement sa proie.", 54, 800000, 255, 167);
	Data::OpMons::listOp.try_emplace(168, 90, 70, 60, 70, 40, 70, "Migalos", Type::INSECTE, Type::POISON, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1.1, 33.5, "Il attache un fil à sa proie avant de la libérer. Il s'en servira pour la retrouver, elle et ses amis.", 134, 800000, 90, 168);
	Data::OpMons::listOp.try_emplace(169, 90, 80, 70, 80, 130, 85, "Nostenfer", Type::POISON, Type::VOL, 0, -1, ne , {Stats.SPE ,Stats.SPE, Stats.SPE}, 1., 75, "Ses quatre ailes lui permettent de voler furtivement pour approcher ses proies sans les effrayer.", 204, 1000000, 90, 169);
	Data::OpMons::listOp.try_emplace(170, 38, 38, 56, 56, 67, 75, "Loupio", Type::EAU, Type::ELECTRIQUE, 0, 27, new E_Level(171, 27), {Stats.PV}, 0.5, 12, "Il émet avec ses antennes des impulsions positives et négatives qui peuvent électrocuter ses ennemis.", 90, 1250000, 190, 170);
	Data::OpMons::listOp.try_emplace(171, 58, 58, 76, 76, 67, 125, "Lanturn", Type::EAU, Type::ELECTRIQUE, 0, -1, new E_Nope(), {Stats.PV, Stats.PV}, 1.2, 22.5, "La lumière de Lanturn surgit des profondeurs. On le surnomme « étoile des profondeurs ».", 156, 1250000, 75, 171);
	Data::OpMons::listOp.try_emplace(172, 40, 15, 35, 35, 60, 20, "Pichu", Type::ELECTRIQUE, Type::NOTHING, 0, -1, new E_Love(0), {Stats.SPE}, 0.3, 2, "Il ne sait pas encore stocker l'électricité. Il envoie des décharges par jeu ou par peur.", 42,1000000, 190, 172);
	Data::OpMons::listOp.try_emplace(173, 25, 28, 45, 55, 15, 50, "Mélo", Type::FEE, Type::NORMAL, 0, -1, new E_Love(35), {Stats.DEFSPE}, 0.3, 3, "On en voit beaucoup lorsque le ciel se remplit d'étoiles filantes. Ils s'éclipsent au lever du soleil.", 37, 800000, 150, 173);
	Data::OpMons::listOp.try_emplace(174, 90, 30, 15, 40, 20, 15, "Toudoudou", Type::FEE, Type::NOTHING, 0, -1, new E_Love(0), {Stats.PV}, 0.3, 1, "Son corps est très doux. Quand il commence à rebondir, il est impossible de l'arrêter.", 45, 800000, 39, 174);
	Data::OpMons::listOp.try_emplace(175, 20, 65, 40, 65, 20, 35, "Togepi", Type::FEE, Type::NOTHING, 0, -1, new E_Item(175, Item::getItem("Bonheur")), {Stats.DEFSPE}, 0.3, 1.5, "Sa coquille est remplie de joie. On dit que s’il est bien traité, il porte chance.", 74, 800000, 190, 175);
	Data::OpMons::listOp.try_emplace(176, 40, 85, 80, 105, 40, 55, "Togetic", Type::FEE, Type::VOL, 0, -1, new E_Item(176, Item::getItem("Pierre Eclat")), {Stats.SPE, Stats.SPE}, 0.6, 3.2, "Il se démoralise vite s'il n'est pas avec des gens sympathiques. Il peut léviter sans battre des ailes.", 114, 800000, 75, 176);
	Data::OpMons::listOp.try_emplace(177, 50, 45, 70, 45, 70, 40, "Natu", Type::VOL, Type::PSY, 0, 25, new E_Level(178, 25), {Stats.ATKSPE}, 0.2, 2, "Ses ailes ne sont pas assez développées et il ne peut que planer péniblement. Il fixe toujours quelque chose.", 73, 1000000, 190, 177);
	Data::OpMons::listOp.try_emplace(178, 75, 70, 95, 70, 95, 65, "Xatu", Type::PSY, Type::VOL, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.SPE}, 1.5, 15, "On dit qu'il est calme et tranquille car il peut voir en permanence le passé et le futur grâce à ses yeux en forme de tétons.", 171, 1000000, 75, 178);
	Data::OpMons::listOp.try_emplace(179, 55, 40, 40, 65, 45, 35, "Wattouat", Type::ELECTRIQUE, Type::NOTHING, 0, 15, new E_Level(180, 15), {Stats.ATKSPE}, 0.6, 7., "Sa laine fournie enfle lorsqu'il accumule de l'électricité statique. Son contact peut choquer.", 235, 1059860, 59, 179);
	Data::OpMons::listOp.try_emplace(180, 55, 55, 80, 60, 45, 70, "Lainergie", Type::ELECTRIQUE, Type::NOTHING, 0, 30, new E_Level (181, 30), {Stats.ATKSPE, Stats.ATKSPE}, 0., 13.3, "Sa queue s'allume lorsque sa laine se charge d'électricité. Il projette des poils électrifiés.", 117, 1059860, 120, 180);
	Data::OpMons::listOp.try_emplace(181, 75, 85, 115, 90, 55, 90, "Pharamp", Type::ELECTRIQUE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.4, 61.5, "Le bout de sa queue brille si fort qu'il peut être vu de très loin. Il sert de balise aux gens.", 196, 1059860, 45, 181);
	Data::OpMons::listOp.try_emplace(182, 80, 85, 90, 100, 50, 75, "Joliflor", Type::PLANTE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 0.4, 5., "Les Joliflor se réunissent souvent pour danser. On pense que c'est un rituel pour appeler le soleil", 184, 1059860, 45, 182);
	Data::OpMons::listOp.try_emplace(183, 20, 50, 20, 50, 40, 70, "Marill", Type::EAU, Type::FEE, 0, 18, new E_Level(184, 18), {Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 0.4, 8.5, "Sa fourrure est imperméable, si bien qu'il reste sec même en jouant dans l'eau", 58, 800000, 190, 183);
	Data::OpMons::listOp.try_emplace(184, 100, 50, 80, 80, 50, 105, "Azumarill", Type::EAU, Type::FEE, 0, -1, new E_Nope(), {Stats.PV, Stats.PV, Stats.PV}, 0., 28.5, "Ses longues oreilles font un radar efficace. Elles décèlent les mouvements dans le lit des rivières.", 153, 800000, 75, 184);
	Data::OpMons::listOp.try_emplace(185, 100, 115, 30, 65, 30, 70, "Simularbre", Type::ROCHE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEF}, 1.4, 61.5, "Il se déguise en arbre pour éviter les problèmes. Il déteste l'eau et se cache par temps de pluie.", 135, 1059860, 65, 185);
	Data::OpMons::listOp.try_emplace(186, 75, 75, 90, 100, 70, 90, "Tarpaud", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEFSPE}, 1.1, 33.9, "Si Ptitard et Têtarte entendent son cri, ils se rassemblent pour venir le rencontrer.", 185, 1059860, 45, 186);
	Data::OpMons::listOp.try_emplace(187, 35, 40, 35, 55, 50, 35, "Granivol", Type::PLANTE, Type::VOL, 0, 18, new E_Level(188, 18), {Stats.DEFSPE}, 0.4, 0.5, "Il dérive avec le vent. Sa présence en nombre dans les champs et les montagnes annonce le printemps.", 74, 1059860, 255, 187);
	Data::OpMons::listOp.try_emplace(188, 45, 50, 45, 65, 80, 55, "Floravol", Type::PLANTE, Type::VOL, 0, 18, new E_Level(189, 27), {Stats.SPE, Stats.SPE}, 0.6, 1, "Il étend ses pétales pour absorber la lumière du soleil. Il flotte pour se rapprocher du soleil.", 136, 1059860, 120, 188);
	Data::OpMons::listOp.try_emplace(189, 75, 55, 70, 55, 95, 110, "Cotovol", Type::PLANTE, Type::VOL, 0, -1, new E_Nope(), {Stats.SPE, Stats.SPE, Stats.SPE},0., 3, "Même sous un vent très violent, il contrôle sa destination en bougeant ses appendices.", 136, 1059860, 45, 189);
	Data::OpMons::listOp.try_emplace(190, 70, 55, 40, 55, 85, 55, "Capumain", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE}, 0., 11.5, "Sa queue est si forte qu'il peut l'utiliser pour se suspendre aux branches des arbres.", 94, 800000, 45, 190);
	Data::OpMons::listOp.try_emplace(191, 30, 30, 30, 30, 30, 30, "Tournegrin", Type::PLANTE, Type::NOTHING, 0, -1, new E_Item(192, Item::getItem("Pierre Soleil")), {Stats.ATKSPE}, 0.3, 1., "Il tombe du ciel soudainement. S'il est attaqué par un Piafabec, il secoue violemment ses feuilles.", 52, 1059860, 235, 191);// ajoutez la pierre soleil
	Data::OpMons::listOp.try_emplace(192, 75, 55, 105, 85, 30, 75, "Héliatronc", Type::PLANTE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE}, 0., 8.5, "À l'approche des beaux jours, les pétales entourant sa tête deviennent plus chatoyants.", 146, 1059860, 120, 192);
	Data::OpMons::listOp.try_emplace(193, 65, 45, 75, 45, 95, 65, "Yanma", Type::INSECTE, Type::VOL, 0, -1, new E_Nope(), {Stats.PV, Stats.SPE}, 1.2, 3, "Il voit à 360° sans avoir à tourner la tête. Il ne loupe jamais une proie, même dans son dos.", 147, 1000000, 75, 193);
	Data::OpMons::listOp.try_emplace(194, 100, 50, 80, 80, 50, 105, "Axoloto", Type::EAU, Type::FEE, 0, 20, new E_Level(195,20), {Stats.PV}, 0.4, 8.5, "Il émerge de l'eau lorsque l'air se rafraîchit pour partir chasser sur les berges.", 52, 1000000, 255, 194);
	Data::OpMons::listOp.try_emplace(195, 85, 85, 65, 65, 35, 95, "Maraiste", Type::EAU, Type::FEE, 0, -1, new E_Nope(), {Stats.PV, Stats.PV}, 0., 28.5, "Ce Pokémon est très insouciant. Quand il nage, il fonce tête première dans la coque des bateaux", 137, 1000000, 90, 195);
	Data::OpMons::listOp.try_emplace(196, 65, 60, 130, 95, 110, 65, "Mentali", Type::PSY, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE}, 0.9, 26.5, "Sa fourrure ultraswagg détecte les vibrations de l'air. Il peut ainsi prédire le temps ou lire les pensées adverses.", 197, 1000000, 45, 196);
	Data::OpMons::listOp.try_emplace(197, 65, 110, 60, 130, 65, 95, "Noctali", Type::TENEBRES, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE}, 1, 27, "Quand il s'énerve, ses pores sécrètent une sueur empoisonnée qu'il envoie dans les yeux de ses ennemis.", 197, 1000000, 45, 197);
	Data::OpMons::listOp.try_emplace(198, 85, 42, 85, 42, 91, 60, "Cornèbre ", Type::TENEBRES, Type::VOL, 0, -1, new E_Item(0, Item::getItem("Pierre Lune")), {Stats.SPE}, 0.5, 2.1, "Jadis, Cornèbre était craint et détesté, car on disait qu'il portait malheur. Ce Pokémon est attiré par tout ce qui brille. Parfois, il essaye de voler les bagues des filles.", 107, 1059860, 45, 198);
	Data::OpMons::listOp.try_emplace(199, 75, 90, 100, 110, 30, 95, "Roigada", Type::EAU, Type::PSY, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 2, 80, "Tous les jours, Roigada entreprend des recherches pour résoudre les mystères du monde. Cependant, ce Pokémon oublie tout ce qu'il a appris si le Kokiyas qui se trouve sur sa tête s'en va.", 164, 1000000, 70, 199);
	Data::OpMons::listOp.try_emplace(200, 60, 60, 85, 85, 85, 60, "Feuforêve", Type::SPECTRE, Type::NOTHING, 0, -1, new E_Item(0, Item::getItem("Pierre Nuit")), {Stats.ATKSPE, Stats.DEFSPE}, 0.7, 1.0, "Il pousse des hurlements la nuit pour effrayer les gens.", 147, 800000, 45, 200);//Ajoutez la pierre nuit
	Data::OpMons::listOp.try_emplace(201, 72, 48, 72, 48, 48, 48, "Zarbi", Type::FEE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATKSPE}, 0.5, 5, "Son corps plat et fin est toujours collé aux murs. On pense que sa forme a une signification.", 61, 1000000, 225, 201);
	Data::OpMons::listOp.try_emplace(202, 33, 58, 33, 58, 33, 190, "Qulbutoké", Type::PSY, Type::NOTHING, 0, -1, new E_Nope(), {Stats.PV, Stats.PV}, 1.3, 28.5, "Pour cacher sa queue imposante, il vit discrètement dans l'obscurité. Il n'attaque jamais le premier.", 177, 1000000, 45, 202);
	Data::OpMons::listOp.try_emplace(203, 80, 65, 90, 65, 85, 70, "Girafarig", Type::NORMAL, Type::PSY, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE}, 1.5, 41.5, "Sa queue possède un cerveau. Si vous vous en approchez, elle vous sentira et vous mordra.", 149, 1000000, 60, 203);
	Data::OpMons::listOp.try_emplace(204, 65, 90, 35, 35, 15, 50, "Pomdepik", Type::INSECTE, Type::NOTHING, 0, 31, new E_Level(205, 31), {Stats.DEF}, 0.6, 7.2, "Il renforce sa carapace en y ajoutant des écorces d'arbre. Il devient alors plus lourd.", 60, 1000000, 190, 204);
	Data::OpMons::listOp.try_emplace(205, 90, 140, 60, 60, 40, 75, "Foretress", Type::INSECTE, Type::ACIER, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEF}, 1.2, 125., "Il est totalement fixé à son arbre. Il lance des morceaux de sa carapace pour faire fuir son ennemi, comme un gros lâche", 118, 1000000, 75, 205);
	Data::OpMons::listOp.try_emplace(206, 70, 70, 65, 65,  45, 100, "Insolourdo", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.PV}, 1.5, 14, "Ce Pokemon mérite t'il vraiment une description ?", 125, 1000000, 190, 206);
	Data::OpMons::listOp.try_emplace(207, 75, 105, 35, 65, 85, 65, "Scorplane", Type::VOL, Type::SOL, 0, -1, new E_Nope(), {Stats.DEF}, 1.1, 64., "Il vole droit vers le visage de sa cible effrayée et s'y accroche pour lui injecter son poison.", 220, 1059860, 60, 207);//EVOLUTION A CORRIGER
	Data::OpMons::listOp.try_emplace(208, 85, 200, 55, 65, 30, 75, "Steelix", Type::ACIER, Type::SOL, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEF}, 9.2, 400, "Grâce à la température élevée et à la haute pression souterraines, son corps est plus dur que le métal.", 196, 1000000, 25, 208);
	Data::OpMons::listOp.try_emplace(209, 80, 50, 40, 40, 30, 60, "Snubbull", Type::FEE, Type::NOTHING, 0, 23, new E_Level(210, 23), {Stats.PV}, 0.6, 7., "Il est d'une nature joviale. De nombreuses femmes l'apprécient pour sa gentillesse.", 63, 800000, 190, 209);
	Data::OpMons::listOp.try_emplace(210, 120, 75, 60, 60, 45, 90, "Granbull", Type::NOTHING, Type::FEE, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1.4, 48.7, "Il peut faire fuir presque tous les Pokémon en ouvrant très largement sa mâchoire.", 178, 800000, 75, 210);
	Data::OpMons::listOp.try_emplace(211, 95, 85, 55, 55, 85, 65, "Qwilfish", Type::EAU, Type::FEE, 0, -1, new E_Nope(), {Stats.ATK},  0.5, 3.9, "Pour tirer ses dards empoisonnés, il gonfle son corps en buvant 10 L d'eau subitement.", 100, 800000, 45, 211);
	Data::OpMons::listOp.try_emplace(212, 130, 100, 55, 80, 65, 70, "Cizayox", Type::INSECTE, Type::ACIER, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1., 11, "Les pinces de ce Pokémon contiennent de l'acier et peuvent réduire en miettes quasiment n'importe quoi.", 200, 1000000, 25, 212);
	Data::OpMons::listOp.try_emplace(213, 10, 230, 10, 230, 5, 20, "Caratroc", Type::INSECTE, Type::ROCHE, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEFSPE}, 0.6, 20.5, "Il garde des Baies dans sa coquille. Pour éviter les attaques, il s'immobilise sous les rochers.", 80, 1059860, 190, 213);
	Data::OpMons::listOp.try_emplace(214, 125, 75, 40, 95, 85, 80, "Scarhino", Type::INSECTE, Type::COMBAT, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1.5, 54, "Sa force herculéenne lui permet de soulever et de jeter plus de 100 fois son poids.", 200, 1250000, 45, 214);
	Data::OpMons::listOp.try_emplace(215, 95, 55, 35, 75, 115, 55, "Farfuret", Type::TENEBRES, Type::GLACE, 0, -1, new E_Nope(), {Stats.PV, Stats.PV, Stats.PV}, 0.9, 2, "Il se nourrit d'œufs volés dans des nids. Ses griffes crochues percent les défenses de l'ennemi.", 132, 1059860, 60, 215);//EVOLUTION A CORRIGER
	Data::OpMons::listOp.try_emplace(216, 80, 50, 50, 50, 40, 60, "Teddiursa", Type::NORMAL, Type::NOTHING, 0, 30, new E_Level(217,30), {Stats.SPE}, 0.6, 8., "Il se fait des réserves de nourriture dans des cachettes avant l'arrivée de l'hiver.", 70, 1000000, 120, 216);
	Data::OpMons::listOp.try_emplace(217, 130, 75, 75, 75, 55, 90, "Ursaring", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 1., 125., "Bien que d'une large corpulence, il grimpe aux arbres pour s'y nourrir et y dormir.", 189, 1000000, 60, 217);
	Data::OpMons::listOp.try_emplace(218, 40, 40, 70, 40, 20, 40, "Limagma", Type::FEU, Type::NOTHING, 0, 38, new E_Level(219,38), {Stats.ATKSPE}, 0.7, 35, "Son corps est fait de magma. S'il cesse de bouger, il refroidit et durcit.", 78, 1000000, 190, 218);
	Data::OpMons::listOp.try_emplace(219, 50, 120, 90, 80, 30, 60, "Volcaropod", Type::FEU, Type::ROCHE, 0, -1, new E_Nope(), {Stats.DEF}, 0., 55, "Son corps en ébullition est aussi chaud que de la lave. Des flammes sortent de sa coquille.", 154, 1000000, 75, 219);
	Data::OpMons::listOp.try_emplace(220, 50, 40, 30, 30, 50, 50,"Marcacrin", Type::GLACE, Type::SOL, 0, 33, new E_Level(221,33), {Stats.ATK}, 0.4, 6.5, "S'il sent une odeur attirante, il fonce tête baissée pour en trouver l'origine.", 78, 1250000, 225, 220);
	Data::OpMons::listOp.try_emplace(221, 100, 80, 60, 60, 50, 100, "Cochignon", Type::GLACE, Type::SOL, 0, -1, new E_Nope(), {Stats.PV, Stats.ATK}, 1.1, 55., "Bien que pourvu de courtes pattes, ses sabots sont pointus pour l'empêcher de glisser sur la glace.", 160, 1250000, 75, 221);
	Data::OpMons::listOp.try_emplace(222, 55, 95, 65, 95, 35, 65, "Corayon", Type::EAU, Type::ROCHE, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEFSPE}, 0.6, 5, "Il grandit en permanence. Les exquises excroissances de sa tête sont très recherchées.", 113, 800000, 45, 222);
	Data::OpMons::listOp.try_emplace(223, 65, 35, 65, 35, 65, 35, "Rémoraid", Type::EAU, Type::NOTHING, 0, 25,new E_Level(223, 25), {Stats.ATKSPE}, 0, 12, "Se servant de sa nageoire dorsale, il s'accroche sous un Démanta pour récupérer ses restes.", 78, 1000000,190, 223);
	Data::OpMons::listOp.try_emplace(224, 105, 75, 105, 75, 45, 75, "Octillery", Type::EAU, Type::ACIER, 0, -1, new E_Nope(), {Stats.ATKSPE}, 0, 2, "  Il adore se cacher dans les fissures et les épaves, d’où il attaque en crachant de l'encre.", 164, 1000000,75, 224);
	Data::OpMons::listOp.try_emplace(225, 55, 45, 65, 45, 75, 45, "Cadoizo", Type::GLACE, Type::VOL, 0, -1, new E_Nope(), {Stats.SPE}, 0, 16, "Il dépose sa nourriture dans sa queue enroulée. Il l'offre souvent aux gens égarés en montagne.", 183, 800000,45, 225);
	Data::OpMons::listOp.try_emplace(226, 40, 70, 80, 140, 70, 85, "Démenta", Type::EAU, Type::VOL, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE}, 2, 220, "Il peut planer au-dessus des vagues sur plus de 100 m en prenant son élan dans la mer.", 168, 1250000, 45, 226);
	Data::OpMons::listOp.try_emplace(227, 80, 140, 40, 70, 70, 65, "Airmur", Type::ACIER, Type::VOL, 0, -1, new E_Nope(), {Stats.DEF}, 1, 50, "Comme il fait son nid dans les ronces, ses petits s'endurcissent à force d'être sans cesse éraflés", 168, 12500000, 35, 227);
	Data::OpMons::listOp.try_emplace(228, 60, 30, 80, 50, 65, 45, "Malosse", Type::TENEBRES, Type::FEU, 0, 24,new E_Level(228, 24), {Stats.ATKSPE}, 1, 11, "Il hurle dès l'aube pour délimiter son territoire. On l'entend à des kilomètres à la ronde.", 114, 1250000,120, 228);
	Data::OpMons::listOp.try_emplace(229, 90, 50, 110, 80, 95, 75, "Démolosse", Type::TENEBRES, Type::FEU, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE}, 1, 35, "Jadis, les gens prenaient son étrange hurlement pour l'appel de la Faucheuse.", 204, 1250000,45, 229);
	Data::OpMons::listOp.try_emplace(230, 95, 95, 95, 95, 85, 75, "Hyporoi", Type::EAU, Type::DRAGON, 0, -1, new E_Nope(), {Stats.ATK,Stats.ATKSPE,Stats.DEFSPE}, 2, 152, "Hyporoi vit au fin fond des profondeurs océaniques généralement inhabitées. On a longtemps cru que le bâillement de ce Pokémon créait les tourbillons dans les océans", 207, 1000000, 45, 230);//TAG : TODO : A vérifier : Taux de capture
	Data::OpMons::listOp.try_emplace(231, 60, 60, 40, 40, 40, 40, "Phanpy", Type::SOL, Type::NOTHING, 0, 25,new E_Level(231, 25), {Stats.PV}, 1, 33, "Il se cogne sur celui ou celle qu'il apprécie. Il est cependant si fort qu'il fait souvent mal.", 124, 1000000, 45, 231);
	Data::OpMons::listOp.try_emplace(232, 120, 120, 60, 60, 50, 90, "Donphan", Type::SOL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK,Stats.DEF}, 1, 120, "Si Donphan décidait de charger, il pourrait détruire une maison. Grâce à sa force étonnante, ce Pokémon peut aider à déplacer les rochers et les coulées de boue qui bloquent les chemins de montagne.", 189, 1000000, 45, 232);//TAG : TODO : A vérifier : Taux de capture
	Data::OpMons::listOp.try_emplace(233, 80, 90, 105, 95, 60, 85, "Porygon2", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.ATKSPE}, 0.6, 32.5, "Version évoluée de Porygon, créée dans l'espoir de pouvoir un jour terraformer des planètes, un rêve loin d'être concrétisé pour l'instant.", 180, 1000000, 45, 233);
	Data::OpMons::listOp.try_emplace(234, 95, 62, 85, 65, 85, 73, "Cerfrousse", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK}, 1.4, 71.2, " Ce Pokémon fut chassé et l'espèce proche de l'extinction à cause des gens qui recherchaient leurs précieux bois.", 165, 1250000, 45, 234);
	Data::OpMons::listOp.try_emplace(235, 20, 35, 20, 45, 75, 55, "Quelorior", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE}, 1.2, 5, "Ce Pokémon peint pour marquer son territoire. On reconnaît les villes peuplées de nombreux Queulorior à leurs murs recouverts de graffitis", 106, 800000, 45, 235);
	Data::OpMons::listOp.try_emplace(236, 35, 35, 35, 35, 35, 35, "Debugant", Type::COMBAT, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK}, 0.7, 21, "Pour augmenter ses capacités, il cherche à se battre contre n'importe qui. Il est très courageux.", 91, 1000000, 75, 236);//EVOLUTION A CORRIGER
	Data::OpMons::listOp.try_emplace(237, 95, 95, 35, 110, 70, 50, "Kapoera", Type::COMBAT, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE}, 1.4, 4, "Il combat en tournoyant comme une toupie. La force centrifuge décuple sa puissance destructrice.", 137, 1000000, 45, 237);//EVOLUTION A CORRIGER
	Data::OpMons::listOp.try_emplace(238, 30, 15, 85, 65, 65, 45, "Lippouti", Type::GLACE, Type::PSY, 0, 30, new E_Level (124, 30), {Stats.ATKSPE}, 0.6, 6, "Il goûte à tout du bout des lèvres. Elles gardent en mémoire ses goûts et ses dégoûts.", 87, 1000000, 45, 238);
	Data::OpMons::listOp.try_emplace(239, 63, 37, 65, 55, 95, 45, "Elekid", Type::ELECTRIQUE, Type::NOTHING, 0, 30, new E_Level(125,30), {Stats.SPE}, 0.6, 23.5, "Il génère de l'électricité en battant des bras, mais il n'a aucun moyen de stocker cette énergie.", 106, 1000000, 45, 239);
	Data::OpMons::listOp.try_emplace(240, 75, 37, 70, 55, 83, 45, "Magby", Type::FEU, Type::NOTHING, 0, 30, new E_Level (126,30), {Stats.SPE}, 0.7, 21.4, "Ce Pokémon est souvent aperçu dans les régions volcaniques. Donnez-lui à manger et il vous déclarera sa flamme... littéralement.", 117, 1000000, 45, 240);
	Data::OpMons::listOp.try_emplace(241, 80, 105, 40, 70, 100, 95, "Écrémeuh", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.SPE}, 1.2, 75.5, "Son lait est aussi nutritif qu'hypercalorique. A consommer avec modération", 200, 1250000, 45, 241);
	Data::OpMons::listOp.try_emplace(242, 10, 10, 75, 135, 55, 255, "Leuphorie", Type::NORMAL, Type::NOTHING, 0, -1, new E_Nope(), {Stats.PV, Stats.PV, Stats.PV}, 1.5, 46., "Le pelage de ce Pokémon lui fait office de radar à émotions. Il est ainsi capable de capter les humeurs des Pokémon et humains alentour", 608, 800000, 30, 242);//
	Data::OpMons::listOp.try_emplace(243, 85, 75, 115, 110, 115, 90, "Raikou", Type::ELECTRIQUE, Type::NOTHING, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.SPE, Stats.SPE}, 1.9, 17, "Le nuage de pluie qu'il porte peut relâcher la foudre à volonté. On dit de lui qu'il est venu avec l'orage.", 216, 1250000, 3, 243);
	Data::OpMons::listOp.try_emplace(244, 115, 85, 90, 75, 100, 115, "Entei", Type::FEU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.PV, Stats.ATK, Stats.ATK}, 2.1, 19, "Un Pokémon qui parcourt le monde. On dit qu'il en naît un à chaque fois qu'un volcan apparaît", 217, 1250000, 3, 244);
	Data::OpMons::listOp.try_emplace(245, 75, 115, 90, 115, 85, 100, "Suicune", Type::EAU, Type::NOTHING, 0, -1, new E_Nope(), {Stats.DEF, Stats.DEFSPE, Stats.DEFSPE}, 2, 187, "Il serait la réincarnation du vent du nord. Il peut purifier instantanément les eaux polluées.", 216, 1250000, 3, 245);
	Data::OpMons::listOp.try_emplace(246, 64, 50, 45, 50, 41, 50, "Embrylex", Type::ROCHE, Type::SOL, 0, 30, new E_Level (247,30), {Stats.ATK}, 0.6, 72, "Il vit très profond sous terre. Il n'en sort pour évoluer qu'après avoir dévoré tout ce qui l'entourait.", 67, 1250000, 45, 246);
	Data::OpMons::listOp.try_emplace(247, 84, 70, 65, 70, 51, 70, "Ymphect", Type::ROCHE, Type::SOL, 0, 55, new E_Level (248,55), {Stats.ATK, Stats.ATK}, 1.2, 152, "Sa carapace est aussi dure que la pierre et il est très fort. Ses coups peuvent raser une montagne.", 144, 1250000, 45, 247);
	Data::OpMons::listOp.try_emplace(248, 134, 110, 95, 100, 61, 100, "Tyranocif", Type::ROCHE, Type::TENEBRES, 0, -1, new E_Nope(), {Stats.ATK, Stats.ATK, Stats.ATK}, 2, 202, "Lorsqu'il est en colère, il abat des montagnes et enterre des fleuves. On doit alors modifier les cartes.", 218, 1250000, 45, 248);
	Data::OpMons::listOp.try_emplace(249, 90, 130, 90, 154, 110, 106, "Lugia", Type::PSY, Type::VOL, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 5.2, 216, "Il dort dans une faille des grands fonds. Ses battements d'ailes génèrent une tempête de 40 jours.", 220, 1250000, 3, 249);
	Data::OpMons::listOp.try_emplace(250, 130, 90, 110, 154, 90, 106, "Ho-Oh", Type::FEU, Type::VOL, 0, -1, new E_Nope(), {Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 3., 199, "Une légende raconte que son corps brille de sept couleurs. Un arc-en-ciel se forme derrière lui quand il vole.", 211, 1250000, 3, 250);
	Data::OpMons::listOp.try_emplace(?, 90, 90, 90, 90, 90, 90, "Clair de Lune", Type::LUMIERE, Type::TENEBRES, 0, -1, new E_Nope(), {Stats.ATKSPE, Stats.DEFSPE, Stats.}, 0.4, 5, "Ce chat adorait contempler la lune chaques soirs, mais un jour, la lune a eu raison de lui", 300, 1250000, 3, ?);
      */
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
  
    void initTextures() {

      Data::World::tileset.loadFromFile(getPath(RESSOURCES_PATH + "tileset/tileset.png"));
      if(!texturePP[(int) Side::TO_DOWN].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/pp0.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!texturePP[(int) Side::TO_RIGHT].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/pp1.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!texturePP[(int) Side::TO_LEFT].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/pp2.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!texturePP[(int) Side::TO_UP].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/pp3.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP[(int) Side::TO_DOWN].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp0.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP[(int) Side::TO_RIGHT].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp1.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP[(int) Side::TO_LEFT].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp2.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP[(int) Side::TO_UP].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp3.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP2[(int) Side::TO_DOWN].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp20.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP2[(int) Side::TO_RIGHT].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp21.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP2[(int) Side::TO_LEFT].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp22.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }
      if(!walkingPP2[(int) Side::TO_UP].loadFromFile(getPath(RESSOURCES_PATH + "sprites/chara/pp/mpp23.png"))){
	handleError("Failed to load one of the PP sprites", false);
      }

      std::vector<sf::Texture> basicDoor;
      for(unsigned int i = 0; i < 4; i++) {
	std::ostringstream oss;
	oss << RESSOURCES_PATH << getPath("animations/basicdoor/basic_door") << i + 1 << ".png";
	sf::Texture txtr;
	if(!txtr.loadFromFile(oss.str())){
	  handleError("Failed to load one of the basic door sprites", false);
	}
	basicDoor.push_back(txtr);
      }
      doorsTextures.push_back(basicDoor);
      if(!Model::Data::Ui::doorSoundBuffer.loadFromFile(getPath(RESSOURCES_PATH + "audio/sounds/door.ogg"))){
	handleError("Failed to load the door sound.", false);
      }
      if(!Model::Data::Ui::shopDoorSoundBuffer.loadFromFile(getPath(RESSOURCES_PATH + "audio/sounds/shopdoor.ogg"))){
	handleError("Failed to load the shop door sound.", false);
      }
      Events::doorSound.setBuffer(Model::Data::Ui::doorSoundBuffer);
      Events::shopdoorSound.setBuffer(Model::Data::Ui::shopDoorSoundBuffer);
      std::vector<sf::Texture> shopDoor;
      for(unsigned int i = 0; i < 4; i++) {
	std::ostringstream oss;
	oss << RESSOURCES_PATH << getPath("animations/shopdoor/shop_door") << i + 1 << std::string(".png");
	sf::Texture txtr;
	if(!txtr.loadFromFile(oss.str())){
	  handleError("Failed to load the shop door sprite.", false);
	}
	shopDoor.push_back(txtr);
      }
      doorsTextures.push_back(shopDoor);
      for(unsigned int i = 0; i < 12; i++) {
	std::string str;
	str << RESSOURCES_PATH << getPath("sprites/chara/kid/kid") << i << std::string(".png");
	charaTextures["kid"].push_back(sf::Texture());
	if(!charaTextures["kid"][i].loadFromFile(str)){
	  handleError("Failed to load one of the kid sprites", false);
	}
      }

      for(unsigned int i = 0; i < 12; i++) {
	std::string str;
	str << RESSOURCES_PATH << getPath("sprites/chara/prof/prof") << i << std::string(".png");
	charaTextures["kiwai"].push_back(sf::Texture());
	if(!charaTextures["kiwai"][i].loadFromFile(str)){
	  handleError("Failed to load one of the prof sprites", false);
	}
      }

      initEnumsEvents();
    }

    void initFonts(){
      if(!font.loadFromFile(getPath(RESSOURCES_PATH + "fonts/Default.ttf"))) {
        handleError("Font cannot be opened.", true);
      }
    }

    void initSounds() {
      if(!Model::Data::Sounds::dialogPass.loadFromFile(getPath(RESSOURCES_PATH + "audio/sounds/dialogChange.ogg"))) {
        handleError("Unable to open dialog sound.", false);
      }
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
    sf::Texture alpha = sf::Texture();
    std::vector<sf::Texture> alphaTab = std::vector<sf::Texture>();

    /**
     * Convert a 2d array into an array of pointer.
     *
     * The 2d array must be cast into a "char *", as it's an unsafe operation.
     * Also, the array of pointer itself is dynamically allocated, and should be freed by the caller after use.
     *
     * @example
     *  char array[10][20];
     *  char **ptr = array_to_pointer((char *)array, 10, 20);
     *  delete[] ptr;
     *
     * @param src 2d source array
     * @param sizeY first level size
     * @param sizeX second level size
     * @return the new pointer.
     */
    char **array_to_pointer(char *src, size_t sizeY, size_t sizeX) {
      auto pointer = new char*[sizeY];

      for (size_t i = 0; i < sizeY; ++i)
	pointer[i] = &src[i * sizeX];
      return pointer;
    }


    void initMaps() {
      auto &maps = Data::World::maps;

      UNS

	//Fauxbourg Euvi loading
	townMusics.push_back(new sf::Music());
      std::vector<sf::Vector2f> feEPos;
  if(!townMusics[0]->openFromFile("audio/music/faubourgeuvi.ogg")){
	  handleError("Unable to open the music faubourgeuvi.ogg", false);
	}
	Model::Data::Elements::elementsCounter["windturbine"] = 0;
	Model::Data::Elements::elementsSprites["windturbine"] = sf::Sprite();
	Model::Data::Elements::elementsPos["windturbine"] = sf::Vector2f(8 *32 + 25 *32 - 8, 3 *32 + 8);
	for(unsigned int i = 1; i < 17; i++) {
	  std::ostringstream str;
	  str << RESSOURCES_PATH + getPath("animations/windturbine/blade_") << i << string(".png");
	  Model::Data::Elements::elementsTextures["windturbine"].push_back(sf::Texture());
	  Model::Data::Elements::elementsTextures["windturbine"][i - 1].loadFromFile(str.str());
	}
	Model::Data::Elements::elementsCounter["smoke"] = 0;
	Model::Data::Elements::elementsSprites["smoke"] = sf::Sprite();
	Model::Data::Elements::elementsPos["smoke"] = sf::Vector2f(8*32+18*32, 11*32);
	for(unsigned int i = 1; i < 17; i++) {
	  std::ostringstream str;
	  str << RESSOURCES_PATH + getPath("animations/chimneysmoke/chimneysmoke_") << i << string(".png");
	  Model::Data::Elements::elementsTextures["smoke"].push_back(sf::Texture());
	  Model::Data::Elements::elementsTextures["smoke"][i - 1].loadFromFile(str.str());
	}
    
	auto feCol = array_to_pointer((char*) Collisions::feCol, 32, 32);
	Map *mapFauxbourgEuvi = maps.try_emplace("Fauxbourg Euvi", new Map(Maps::feLayer1, Maps::feLayer2, Maps::feLayer3, 32, 32, feCol, getPath(RESSOURCES_PATH +"audio/music/faubourgeuvi.ogg"), std::vector<std::string> {"windturbine", "smoke"})).first->second;
      delete[] feCol;
      mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(11, 2),  {OpString("fedesc.1"), OpString("fedesc.2"), OpString("fedesc.3")}, SIDE_UP));
      mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(21, 8),  {OpString("ppHouse", Data::player.getNameP()), OpString::voidStr, OpString::voidStr}, SIDE_UP));
      mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(25, 8), {OpString("rivalHouse"), OpString::voidStr, OpString::voidStr}, SIDE_UP));
      mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(14, 20),  {OpString("labo"), OpString::voidStr, OpString::voidStr}, SIDE_UP));
      mapFauxbourgEuvi->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(23, 20), {OpString("weirdsign.1"), OpString("weirdsign.2"), OpString::voidStr}, SIDE_UP));
      mapFauxbourgEuvi->addEvent(new Events::DoorEvent(Events::DoorType::NORMAL, sf::Vector2f(19, 8), sf::Vector2i(8, 15), "Player's home"));
      mapFauxbourgEuvi->addEvent(new Events::DoorEvent(Events::DoorType::NORMAL, sf::Vector2f(27, 8), sf::Vector2i(9, 15), "Rival's house"));
      mapFauxbourgEuvi->addEvent(new Events::DoorEvent(Events::DoorType::SHOP, sf::Vector2f(19, 20), sf::Vector2i(16, 15), "Laboratory"));
      /*Character 1*/
      std::vector<Side> pathChara1;
      for(int i = 0; i < 10; i++)
        pathChara1.push_back(Side::TO_RIGHT);

      pathChara1.push_back(Side::NO_MOVE);

      for(int i = 0; i < 10; i++)
        pathChara1.push_back(Side::TO_LEFT);

      pathChara1.push_back(Side::NO_MOVE);

      mapFauxbourgEuvi->addEvent(new Events::TalkingCharaEvent("kid", sf::Vector2f(17, 13),  {OpString("kid"), OpString::voidStr, OpString::voidStr}, Events::EventTrigger::PRESS, Events::MoveStyle::PREDEFINED, pathChara1));

      auto ppHomeCol = array_to_pointer((char*) Collisions::ppHomeCol, 16, 16);
      Map *mapPlayersHome = maps.try_emplace("Player's home", new Map(Maps::pphomeLayer1, Maps::pphomeLayer2, Maps::pphomeLayer3, 16, 16, ppHomeCol, getPath(RESSOURCES_PATH +"audio/music/faubourgeuvi.ogg"))).first->second;
    delete[] ppHomeCol;
    mapPlayersHome->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(7, 15), sf::Vector2i(20, 9), "Fauxbourg Euvi", Side::TO_DOWN, SIDE_DOWN));
    mapPlayersHome->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(15, 2), sf::Vector2i(9, 5), "Player's room", Side::TO_LEFT, SIDE_RIGHT));
    mapPlayersHome->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(0, 11), sf::Vector2i(6, 3), "Mom's room", Side::TO_LEFT, SIDE_LEFT));

    auto laboCol = array_to_pointer((char*) Collisions::laboCol, 16, 32);
    Map *mapLaboratory = maps.try_emplace("Laboratory", new Map(Maps::laboLayer1, Maps::laboLayer2, Maps::laboLayer3, 32, 16, laboCol, getPath(RESSOURCES_PATH + "audio/music/intro.ogg"))).first->second;
    delete[] laboCol;
    mapLaboratory->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(15, 15), sf::Vector2i(20, 21), "Fauxbourg Euvi", Side::TO_DOWN, SIDE_DOWN));

    mapLaboratory->addEvent(new Events::TalkingCharaEvent("kiwai", sf::Vector2f(15, 4), {OpString("prof.dialog.1"), OpString("prof.dialog.2"), OpString("prof.dialog.3")}, Events::EventTrigger::PRESS, Events::MoveStyle::NO_MOVE));

    auto rivalHomeCol = array_to_pointer((char*) Collisions::rivalHomeCol, 16, 16);
    Map *mapRivalsHouse = maps.try_emplace("Rival's house", new Map(Maps::rivalhomeLayer1, Maps::rivalhomeLayer2, Maps::rivalhomeLayer3, 16, 16, rivalHomeCol, getPath(RESSOURCES_PATH +"audio/music/faubourgeuvi.ogg"))).first->second;
    delete[] rivalHomeCol;
    mapRivalsHouse->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(8, 15), sf::Vector2i(28, 9), "Fauxbourg Euvi", Side::TO_DOWN, SIDE_DOWN));

    auto momRoomCol = array_to_pointer((char*) Collisions::momRoomCol, 6, 6);
    Map *mapMomsRoom = maps.try_emplace("Mom's room", new Map(Maps::momroomLayer1, Maps::momroomLayer2, Maps::momroomLayer3, 6, 6, momRoomCol, getPath(RESSOURCES_PATH +"audio/music/faubourgeuvi.ogg"))).first->second;
    delete[] momRoomCol;
    mapMomsRoom->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(5, 3), sf::Vector2i(1, 11), "Player's home", Side::TO_RIGHT, SIDE_RIGHT));

    auto ppRoomCol = array_to_pointer((char*) Collisions::ppRoomCol, 6, 9);
    Map *mapPlayersRoom = maps.try_emplace("Player's room", new Map(Maps::pproomLayer1, Maps::pproomLayer2, Maps::pproomLayer3, 9, 6, ppRoomCol, getPath(RESSOURCES_PATH +"audio/music/faubourgeuvi.ogg"))).first->second;
    delete[] ppRoomCol;
    mapPlayersRoom->addEvent(new Events::TPEvent(alphaTab, Events::EventTrigger::BE_IN, sf::Vector2f(8, 5), sf::Vector2i(16, 2), "Player's home", Side::TO_LEFT, SIDE_RIGHT));
    std::vector<OpString> phoE1 {OpString("pcRunLinux"), OpString::voidStr, OpString::voidStr};
    mapPlayersRoom->addEvent(new Events::TalkingEvent(alphaTab, sf::Vector2f(1, 1), phoE1, SIDE_UP));

    //Route 14 loading
    auto route14Col = array_to_pointer((char*) Collisions::route14Col, 41, 74);
    maps.try_emplace("Route 14", new Map(Maps::route14Layer1, Maps::route14Layer2, Maps::route14Layer3, 74, 41, route14Col, getPath(RESSOURCES_PATH + "audio/music/faubourgeuvi.ogg")));
    delete[] route14Col;

    //MysteriouCity loading
    auto myciCol = array_to_pointer((char*) Collisions::myciCol, 19, 19);
    maps.try_emplace("MysteriouCity", new Map(Maps::myciLayer1, Maps::myciLayer2, Maps::myciLayer3, 19, 19, myciCol, getPath(RESSOURCES_PATH + "audio/music/mysterioucity.ogg")));
    delete[] myciCol;

  }

  void initBackgrounds() {
      
  }

  void initKeys() {
    //Sets the language to initialize in the keys

    std::string lang = OptionsSave::getParam("lang").getValue();
    auto &tr = ::OpMon::I18n::Translator::getInstance();

    if (!tr.getAvailableLanguages().count(lang)){
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
    oplog("Sound initialisation");
    initSounds();
    oplog("Objects initialization ending");
    initSprites();
    oplog("Player initialization");
    initPlayer();
  }

  void initPlayer(){
    //TODO: get Overworld
    Model::Data::player.setMapID("Player's room");
    //Model::Data::player.getPosition().setPosition(((overworld.getCharacter().getPosition().x - 16) / SQUARES_SIZE) - 8, (overworld.getCharacter().getPosition().y / SQUARES_SIZE) - 8);
    Model::Data::player.getPosition().setDir(Side::TO_UP);
  }

}
}
