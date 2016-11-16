package jlppc.regimys.launch;

import jlppc.regimys.enums.Caractere.Stats;
import jlppc.regimys.enums.Type;
import jlppc.regimys.evolution.E_Item;
import jlppc.regimys.evolution.E_Land;
import jlppc.regimys.evolution.E_Level;
import jlppc.regimys.evolution.E_Love;
import jlppc.regimys.evolution.E_Nope;
import jlppc.regimys.evolution.E_Trade;
import jlppc.regimys.evolution.E_TradeItem;
import jlppc.regimys.objects.Espece;

import jlppc.regimys.objects.items.Item;
import jlppc.regimys.util.text.StringKey;
import jlppc.utils.Static;

/**
 * Permet d'initialiser des choses.
 * @author Jlppc
 *
 */
@Static
public class Initializer {
	public static Espece[] listePoke = new Espece[152];
	public static E_Nope ne = new E_Nope(); //ne = No Evolution

	/***
	 * Initialise les pokemon (espèces)
	 */
	 public static void initPokemons(){
		 listePoke[0] = new Espece(136, 0, 1, 1, 29, 33, "MissingNo.", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 80, new E_Level(0, 80), null, null, new Stats[]{Stats.ATK}, 0f, 0f, "ERROR : MISSINGNO.", 0, 1250000, 3);
		 listePoke[1] = new Espece(49, 49, 65, 65, 45, 45, "Bulbizarre", Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 16, new E_Level(2, 16), null, null, new Stats[]{Stats.ATKSPE}, 0.7f, 6.9f, "Il a une étrange graine plantée sur son dos. Elle grandit avec lui depuis sa naissance.", 64, 1059860, 45);
		 listePoke[2] = new Espece(62, 63, 80, 80, 60, 60, "Herbizarre",Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 32, new E_Level(3, 32), null, null, new Stats[]{Stats.ATKSPE, Stats.DEFSPE}, 1f, 13f, "Lorsque le bourgeon sur son dos éclot, il répand un doux parfum pour célébrer sa floraison.", 141, 1059860, 45);
		 listePoke[3] = new Espece(82, 83, 100, 100, 80, 80, "Florizarre", Type.PLANTE, Type.POISON, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.DEFSPE}, 2f, 100f, "Ses pétales lui servent à capter la lumière du soleil. Il peut ainsi en canaliser l'énergie.", 236, 1059860, 45);
		 listePoke[4] = new Espece(52, 43, 60, 50, 65, 39, "Salamèche", Type.FEU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 16, new E_Level(5, 16), null, null, new Stats[]{Stats.VIT}, 0.6f, 8.5f, "La flamme sur sa queue représente l'énergie vitale de Salamèche. Quand il est vigoureux, elle brûle plus fort.", 65, 1059860, 45);
		 listePoke[5] = new Espece(64, 58, 80, 65, 80, 58, "Reptincel", Type.FEU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 36, new E_Level(6, 36), null, null, new Stats[]{Stats.VIT, Stats.ATKSPE}, 1.1f, 19f, "En agitant sa gueue, il peut élever la température à un niveau incroyable", 142, 1059860, 45);
		 listePoke[6] = new Espece(84, 78, 109, 85, 100, 78, "Dracaufeu", Type.FEU, Type.VOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.7f, 90.5f, "Quand il crache son souffle brûlant, la flamme au bout de sa queue s'embrase.", 209, 1059860, 45);
		 listePoke[7] = new Espece(48, 65, 50, 64, 43, 44, "Carapuce", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 16, new E_Level(8, 16), null, null, new Stats[]{Stats.DEF}, 0.5f, 9f, "Caché sous l'eau, il crache un jet d'eau sur sa proie et se cache à l'intérieur de sa carapace.", 66, 1059860, 45);
		 listePoke[8] = new Espece(63, 80, 65, 80, 58, 59, "Carabaffe", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 36, new E_Level(9, 36),null, null, new Stats[]{Stats.DEF, Stats.DEFSPE}, 1f, 22.5f,"On prétend qu'il vit 10 000 ans. Sa queue duveteuse est un symbole de longévité populaire.", 143, 1059860, 45);
		 listePoke[9] = new Espece(83, 100, 85, 105, 78, 79, "Tortank", Type.EAU, Type.AUCUN, Espece.NO_EVOLUTION, -1,ne, null, null, new Stats[]{Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 1.6f, 85.5f, "Il écrase ses adversaires de tout son poids pour leur faire perdre connaissance. Il rentre dans sa carapace s'il se sent en danger.", 210, 1059860, 45);
		 listePoke[10] = new Espece(30, 35, 20, 20, 45, 45, "Chenipan", Type.INSECTE, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 7, new E_Level(11, 7), null, null, new Stats[]{Stats.PV}, 0.3f, 2.9f, "Ses pattes ont des ventouses lui permettant de grimper sur toute surface, notamment les arbres.", 53, 1000000, 255);
		 listePoke[11] = new Espece(20, 55, 25, 25, 30, 50, "Chrysacier", Type.INSECTE, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 10, new E_Level(12, 10), null, null, new Stats[]{Stats.DEF, Stats.DEF}, 0.7f, 9.9f, "Son corps frêle est protégé par sa carapace d'acier. Il encaisse les coups durs en attendant d'évoluer.", 72, 1000000, 120);
		 listePoke[12] = new Espece(45, 50, 90, 80, 70, 60, "Papilusion", Type.INSECTE, Type.VOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.DEFSPE},1.1f, 32f, "Ses ailes sont recouvertes d'une poudre les protégeant de la pluie. Ce Pokémon peut donc voler pendant de grosses averses.", 160, 1000000, 45);
		 listePoke[13] = new Espece(35, 30, 20, 20, 50, 40, "Aspicot", Type.INSECTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 7, new E_Level(14, 7), null, null, new Stats[]{Stats.VIT}, 0.3f, 3.2f, "Son aiguillon empoisonné est très dangereux. Son corps est coloré afin de repousser ses ennemis.", 52, 1000000, 255);
		 listePoke[14] = new Espece(25, 50, 25, 25, 35, 45, "Coconfort", Type.INSECTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 10, new E_Level(15, 10), null, null, new Stats[]{Stats.DEF, Stats.DEF}, 0.6f, 10f, "Incapable de se déplacer de lui-même, il se défend en durcissant sa carapace.", 71, 1000000, 120);
		 listePoke[15] = new Espece(80, 40, 45, 80, 75, 65, "Dardargnan", Type.INSECTE, Type.POISON, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK, Stats.ATK, Stats.DEFSPE}, 1f, 29.5f, "Il se sert de ses trois aiguillons empoisonnés pour attaquer sans relâche ses adversaires.", 159, 1000000, 45);
		 listePoke[16] = new Espece(45, 40, 35, 35, 56, 40, "Roucool", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 18, new E_Level(17, 18), null, null, new Stats[]{Stats.VIT}, 0.3f, 1.8f, "Ce Pokémon docile préfère éviter le combat. Toutefois, il se montre très féroce quand on l'agresse.", 55, 1059860, 255);
		 listePoke[17] = new Espece(60, 55, 50, 50, 71, 63, "Roucoups", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 36, new E_Level(18, 36), null,null, new Stats[]{Stats.VIT, Stats.VIT}, 1.1f, 30f, "Il protège son territoire avec ardeur et repousse à coup de bec tout intrus.", 113, 1059860, 120);
		 listePoke[18] = new Espece(80, 75, 70, 70, 101, 83, "Roucarnage", Type.NORMAL, Type.VOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.VIT, Stats.VIT, Stats.VIT}, 1.5f, 39.5f, "Roucarnage déploie ses ailes majestueuses pour effrayer ses ennemis. Il peut voler à Mach 2.", 172, 1059860, 45);
		 listePoke[19] = new Espece(56, 35, 25, 35, 72, 30, "Rattata", Type.NORMAL, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 20, new E_Level(20, 20), null, null, new Stats[]{Stats.VIT}, 0.3f, 3.5f, "Vivant là où se trouve la nourriture, ce charognard passe ses journées à la rechercher.", 57, 1000000, 255);
		 listePoke[20] = new Espece(81, 60, 50, 70, 97, 55, "Rattatac", Type.NORMAL, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.VIT, Stats.VIT}, 0.7f, 18.5f, "Ses pattes arrière lui permettent de traverser les rivières. Il est toujours en quête de nourriture.", 127, 1000000, 127);
		 listePoke[21] = new Espece(60, 30, 31, 31, 70, 40, "Piafabec", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 20, new E_Level(22, 20), null, null, new Stats[]{Stats.VIT}, 0.3f, 2f, "Il chasse les insectes dans les hautes herbes. Ses petites ailes lui permettent de voler très vite.", 58, 1000000, 255);
		 listePoke[22] = new Espece(90, 65, 31, 31, 100, 65, "Rapasdepic", Type.NORMAL, Type.VOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1.2f, 38f, "Il vole à très grande vitesse et attaque en chargeant son ennemi.", 162, 1000000, 90);
		 listePoke[23] = new Espece(60, 44, 40, 54, 55, 35, "Abo", Type.POISON, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 22, new E_Level(24, 22), null, null, new Stats[]{Stats.ATK}, 2f, 6.9f, "Plus il est âgé, plus son corps est long. Il se love autour des arbres pour se reposer.", 62, 1000000, 255);
	         listePoke[24] = new Espece(85, 69, 65, 79, 80, 60, "Arbok", Type.POISON, Type.NORMAL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK, Stats.ATK}, 3.5f, 65f, "Pour apeurer ses ennemis, il gonfle sa poitrine et émet d'étranges sons avec sa bouche.", 147, 1000000, 90);
		 listePoke[25] = new Espece(55, 40, 50, 50, 90, 35, "Pikachu", Type.ELECTRIQUE, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(26, Item.getItem("Pierrefoudre")), null, null, new Stats[]{Stats.VIT, Stats.VIT}, 0.4f, 6f, "Il élève sa queue pour surveiller les environs. Elle attire souvent la foudre dans cette position.", 82, 1000000, 190);
		 listePoke[26] = new Espece(90, 55, 90, 80, 110, 60, "Raichu", Type.ELECTRIQUE, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.VIT, Stats.VIT, Stats.VIT}, 0.8f, 30f, "Il peut terrasser des ennemis bien plus imposants en libérant une décharge de 100 000 V.", 122, 1000000, 75);
		 listePoke[27] = new Espece(75, 85, 20, 30, 40, 50, "Sabelette", Type.SOL, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 22, new E_Level(28, 22), null, null, new Stats[]{Stats.DEF}, 0.6f, 12f, "Il s'enterre et vit dans les sous-sols. S'il se sent menacé, il se met en boule pour se protéger.", 93, 1000000, 255);
		 listePoke[28] = new Espece(100, 110, 45, 55, 65, 75, "Sablaireau", Type.SOL, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.DEF, Stats.DEF}, 1f, 29.5f, "Il se roule en boule hérissée de piques s'il est menacé, il peut ainsi s'enfuir ou attaquer.", 163, 1000000, 90);
		 listePoke[29] = new Espece(47, 52, 40, 40, 41, 55, "Nidoran♀", Type.POISON, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 16, new E_Level(30, 16), null, null, new Stats[]{Stats.PV}, 0.4f, 7f, "Petite et docile, elle se protège avec sa minuscule corne empoisonnée lorsqu'elle est attaquée.", 59, 1059860, 235);
		 listePoke[30] = new Espece(62, 67, 55, 55, 56, 70, "Nidorina", Type.POISON, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(31, Item.getItem("Pierre Lune")), null, null, new Stats[]{Stats.PV, Stats.PV}, 0.8f, 20f, "La femelle a un tempérament doux. Elle émet des cris ultrasoniques capables de déstabiliser ses ennemis.", 117, 1059860, 120);
		 listePoke[31] = new Espece(92, 87, 75, 85, 76, 90, "Nidoqueen", Type.POISON, Type.SOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.PV, Stats.PV, Stats.PV}, 1.3f, 60f, "Son corps est recouvert d'écailles en forme de pointes. Quand ce Pokémon s'énerve, ses pointes se dressent de façon menaçante.", 194, 1059860, 45);
		 listePoke[32] = new Espece(57, 40, 40, 40, 50, 46, "Nidoran♂", Type.POISON, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 16, new E_Level(33, 16), null, null, new Stats[]{Stats.ATK}, 0.5f, 9f, "Il jauge le terrain en laissant ses oreilles dépasser de l'herbe. Il se défend avec sa corne toxique.", 60, 1059860, 235);
		 listePoke[33] = new Espece(72, 57, 55, 55, 65, 61, "Nidorino", Type.POISON, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1,new E_Item(34, Item.getItem("Pierre Lune")), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 0.9f, 19.5f, "Très agressif, il est prompt à répondre à la violence. La corne sur sa tête est venimeuse.", 118, 1059860, 120);
		 listePoke[34] = new Espece(102, 77, 85, 75, 85, 81, "Nidoking", Type.POISON, Type.SOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK, Stats.ATK, Stats.ATK}, 1.4f, 62f, "Un coup de sa puissante queue peut briser un poteau téléphonique comme une allumette.", 195, 1059860, 45);
		 listePoke[35] = new Espece(45, 48, 60, 65, 35, 70, "Mélofée", Type.FEE, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(36, Item.getItem("Pierre Lune")), null, null, new Stats[]{Stats.PV, Stats.PV}, 06f, 7.5f, "La lumière de la lune qu'il emmagasine dans ses ailes dorsales lui permet de flotter dans les airs.", 68, 800000, 150);
		 listePoke[36] = new Espece(70, 73, 95, 90, 60, 95, "Mélodelfe", Type.FEE, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.PV, Stats.PV, Stats.PV}, 1.3f, 40f, "Il aime le calme des montagnes. Son ouïe exceptionnelle entendrait une aiguille tomber à 1km.", 129, 8000000, 25);
		 listePoke[37] = new Espece(41, 40, 50, 65, 65, 38, "Goupix", Type.FEU, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(38, Item.getItem("Pierre Feu")), null, null, new Stats[]{Stats.VIT}, 0.6f, 9.9f, "Avec l'âge, la fourrure de ses six queues devient de plus en plus belle et soyeuse. Elle est chaude au toucher.",63, 1000000, 190);//TROP KAWAII!!!!
		 listePoke[38] = new Espece(76, 75, 81, 100, 100, 73, "Feunard", Type.FEU, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne,null, null, new Stats[]{Stats.VIT, Stats.DEFSPE}, 1.1f, 19.9f, "Il a neuf longues queues et une fourrure qui brille comme de l'or. On dit qu'il peut vivre 1 000 ans.", 178, 1000000, 75);
		 listePoke[39] = new Espece(45, 20, 45, 25, 20, 115, "Rondoudou", Type.NORMAL, Type.FEE, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(40, Item.getItem("Pierre Lune")),null, null, new Stats[]{Stats.PV, Stats.PV}, 0.5f, 5.5f, "En se gonflant, il peut chanter une longue berceuse qui endort inévitablement ses adversaires.", 76, 800000, 170);
		 listePoke[40] = new Espece(70, 45, 85, 50, 45, 140, "Grodoudou", Type.NORMAL, Type.FEE, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.PV, Stats.PV, Stats.PV}, 1f, 12f, "En cas de danger, il gonfle d'air son corps doux et potelé dans des proportions gigantesques.", 109, 800000, 50);
		 listePoke[41] = new Espece(45, 35, 30, 40, 55, 40, "Nosferapti", Type.POISON, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 22, new E_Level(42, 22), null, null, new Stats[]{Stats.VIT}, 0.8f, 7.5f, "Ce pokemon est détesté en raison de sa forte présence dans les grottes. Malgré le fait qu'il n'aie pas d'yeux, ce pokemon arrive a voir avec des utltrasons.", 54, 1000000, 255);
		 listePoke[42] = new Espece(80, 70, 65, 75, 90, 75, "Nosferalto", Type.POISON, Type.VOL, Espece.EVOLUTION_BY_LOVE, -1, new E_Love(0), null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1.6f, 55f, "Quand il se met à sucer du sang, il ne s'arrête qu'une fois rassasié. C'est un chasseur nocturne.", 171, 1000000, 90);
		 listePoke[43] = new Espece(50, 55, 75, 65, 30, 45, "Mystherbe", Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 21, new E_Level(44, 21), null, null, new Stats[]{Stats.ATKSPE}, 0.5f, 5.4f, "Le jour, il reste en sous-sol et évite le soleil. Il grandit en se baignant au clair de lune.", 78, 1059860, 255);
		 listePoke[44] = new Espece(65, 70, 85, 75, 40, 60, "Ortide", Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(45, Item.getItem("Pierre Plante")) ,null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE}, 0.8f, 8.6f, "Il sent très mauvais ! Mais une personne sur 1 000 aime la puanteur de son corps nauséabond.", 132, 1059860, 120);
		 listePoke[45] = new Espece(80, 85, 110, 90, 50, 75, "Rafflesia", Type.PLANTE, Type.POISON, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.2f, 18.6f, "Il possède des pétales énormes. À chaque pas, ils sèment d'épais nuages de pollen toxique.", 184, 1059860, 45);
		 listePoke[46] = new Espece(70, 55, 45, 55, 25, 35, "Paras", Type.INSECTE, Type.PLANTE, Espece.EVOLUTION_BY_LEVEL, 24, new E_Level(47, 24), null, null, new Stats[]{Stats.ATK}, 0.3f, 5.4f, "Il s'enfouit sous terre pour ronger des racines afin de nourrir les champignons sur son dos.", 70, 1000000, 190);
		 listePoke[47] = new Espece(95, 80, 60, 80, 30, 60, "Parasect", Type.INSECTE, Type.PLANTE, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK, Stats.ATK, Stats.DEF}, 1f, 29.5f, "Un champignon parasite plus gros que Parasect contrôle son corps. Il répand des spores empoisonnées.", 128, 1000000, 75);
		 listePoke[48] = new Espece(55, 50, 40, 55, 45, 60, "Mimitoss", Type.INSECTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 31, new E_Level(49, 31), null, null, new Stats[]{Stats.DEFSPE}, 1f, 30f, "Il vit à l'ombre des grands arbres où il se nourrit d'insectes. Il est attiré par la lumière.", 75, 1000000, 190);
		 listePoke[49] = new Espece(65, 60, 90, 75, 90, 70, "Aéromite", Type.INSECTE, Type.POISON,Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATKSPE, Stats.VIT}, 1.5f, 12.5f, "Les écailles qu'il sème ont le pouvoir de paralyser totalement un ennemi.", 138, 1000000, 75);
		 listePoke[50] = new Espece(55, 25, 35, 45, 95, 10, "Taupiqueur", Type.SOL, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 26, new E_Level(51, 26), null, null, new Stats[]{Stats.VIT}, 0.2f, 0.8f, "Son épiderme est très fin. S'il est exposé au soleil, son sang se réchauffe, ce qui l'affaiblit.", 81, 1000000, 255);
		 listePoke[51] = new Espece(80, 50, 50, 70, 120, 35, "Triopikeur", Type.SOL, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.VIT, Stats.VIT}, 0.7f, 33.3f, "Terriblement puissants, ils peuvent creuser un tunnel dans tout type de sol et jusqu'à 100 km de profondeur.", 153, 1000000, 50);
		 listePoke[52] = new Espece(45, 35, 40, 40, 90, 40, "Miaouss", Type.NORMAL, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 28, new E_Level(53, 28), null, null, new Stats[]{Stats.VIT}, 0.4f, 4.2f, "Son regard s'anime à la vue d'un objet brillant. C'est un Pokémon nocturne.", 69, 1000000, 255);
		 listePoke[53] = new Espece(70, 60, 65, 65, 115, 65, "Persian", Type.NORMAL, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1f, 32f, "Un Pokémon très snob. La taille du joyau qui orne son front alimente bien des débats parmi ses fans.", 148, 1000000, 90);
		 listePoke[54] = new Espece(52, 48, 65, 50, 55, 50, "Psykokwak", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 33, new E_Level(55, 33), null, null, new Stats[]{Stats.ATKSPE}, 0.8f, 19.6f, "Il ne se souvient pas qu'il a des pouvoirs psy. C'est pour cela qu'il a l'air si confus.", 80, 1000000, 190);
		 listePoke[55] = new Espece(82, 78, 95, 80, 85, 80, "Akwakwak", Type.EAU, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE}, 1.7f, 76.6f, "Il apparaît dans les étendues d'eau au crépuscule. Si son front brille, il se sert de sa télékinésie.", 174, 1000000, 75);
		 listePoke[56] = new Espece(80, 35, 35, 45, 70, 40, "Férosinge", Type.COMBAT, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 28, new E_Level(57, 28), null, null, new Stats[]{Stats.ATK}, 0.5f, 28f, "Il ne peut dissocier ses amis de ses ennemis et a tendance à enrager lorsqu'on l'approche.", 74, 1000000, 190);
		 listePoke[57] = new Espece(105, 60, 60, 70, 95, 65, "Colossinge", Type.COMBAT, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1f, 32f, "Sa fureur prend fin quand il n'a plus personne à frapper. Il est difficile d'en être témoin.", 149, 1000000, 75);
		 listePoke[58] = new Espece(70, 45, 70, 50, 60, 55, "Caninos", Type.FEU, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(59, Item.getItem("Pierre Feu")), null, null, new Stats[]{Stats.ATK}, 0.7f, 19f, "Il est courageux et fier. Il se dresse vaillamment devant ses ennemis même s'ils sont plus puissants.", 91, 1250000, 190);
		 listePoke[59] = new Espece(110, 80, 100, 80 , 95, 90, "Arcanin", Type.FEU, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null ,null, new Stats[]{Stats.ATK, Stats.ATK}, 1.9f, 155f, "Son aboiement est tout simplement majestueux. On ne peut que ramper à ses pieds après l'avoir entendu.", 213, 1250000, 75);
		 listePoke[60] = new Espece(50, 40, 40, 40, 90, 40, "Ptitard", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 25, new E_Level(61, 25), null, null, new Stats[]{Stats.VIT}, 0.6f, 12.4f, "Sa peau est si mince qu'on voit ses organes internes. Il tient à peine sur ses nouveaux pieds.", 77, 1059860, 255);
		 listePoke[61] = new Espece(65, 65, 50, 50, 90, 65, "Têtarte", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(62, Item.getItem("Pierre Eau")), null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1f, 20f, " Ce Pokémon amphibie transpire continuellement quand il est hors de l'eau afin d'hydrater son corps.", 131, 1059860, 120);
		 listePoke[62] = new Espece(95, 95, 70, 90, 70, 90, "Tartard", Type.EAU, Type.COMBAT, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.DEF, Stats.DEF, Stats.DEF}, 1.3f, 54f, "Il possède de sacrés biscoteaux. Il peut parcourir sans relâche l'Océan Pacifique.", 185, 1059860, 45);
		 listePoke[63] = new Espece(20, 15, 105, 55, 90, 25, "Abra", Type.PSY, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 16, new E_Level(64, 16), null, null, new Stats[]{Stats.ATKSPE}, 0.9f, 19.5f, "Il prévoit les attaques futures et se téléporte pour se mettre à l'abri et éviter le combat.", 75, 1059860, 200);
		 listePoke[64] = new Espece(35, 30, 120, 70, 105, 40, "Kadabra", Type.PSY, Type.AUCUN, Espece.EVOLUTION_BY_TRADE, -1, new E_Trade(65), null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE}, 1.3f, 56.5f, "En utilisant ses pouvoirs, il émet des ondes alphas et cause des distorsions électroniques.", 145, 1059860, 100);
		 listePoke[65] = new Espece(50, 45, 135, 95, 120, 55, "Alakazam", Type.PSY, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.5f, 48f, "Son cerveau hors du commun peut effectuer des opérations à la vitesse d'un ordinateur. Il a un QI de 5 000.", 186, 1059860, 50);
	 	 listePoke[66] = new Espece(80, 50, 35, 35, 35, 70, "Machoc", Type.COMBAT, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 28, new E_Level(67, 28), null, null, new Stats[]{Stats.ATK}, 0.8f, 19.5f, "Son corps est essentiellement composé de muscles. Même s'il a la taille d'un petit enfant, il peut soulever 100 adultes avec ses bras.", 75, 1059860, 180);
		 listePoke[67] = new Espece(100, 70, 50, 60, 45, 80, "Machopeur", Type.COMBAT, Type.AUCUN, Espece.EVOLUTION_BY_TRADE, -1, new E_Trade(68), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1.5f, 70.5f, "Son corps est si puissant qu'il lui faut une ceinture de force pour équilibrer ses mouvements.", 146, 1059860, 90);
		 listePoke[68] = new Espece(130, 80, 65, 85, 55, 90, "Mackogneur", Type.COMBAT, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK, Stats.ATK, Stats.ATK}, 1.6f, 130f, "Ses deux paires de bras permettent à Mackogneur d'envoyer une série de 1000 coups de poing en 2s.", 193, 1059860, 45);
		 listePoke[69] = new Espece(75, 35, 70, 30, 40, 50, "Chétiflor", Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 21, new E_Level(70, 21), null, null, new Stats[]{Stats.ATK}, 0.7f, 4f, "Son bourgeon ressemble à un visage humain. Selon la légende, Chétiflor serait un type de mandragore légendaire.", 84, 1059860, 255);
		 listePoke[70] = new Espece(90, 50, 85, 45, 55, 65, "Boustiflor", Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(71, Item.getItem("Pierre Plante")), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1f, 6.4f, "Il crache de la Poudre Toxik pour immobiliser sa proie et il l'achève avec de l'Acide.", 151, 1059860, 120);
		 listePoke[71] = new Espece(105, 65, 100, 70, 70, 80, "Empiflor", Type.PLANTE, Type.POISON, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK, Stats.ATK, Stats.ATK}, 1.7f, 15.5f, "Tout corps ingéré par ce Pokémon est systématiquement dissout en bouillie.", 191, 1059860, 45);
		 listePoke[72] = new Espece(40, 35, 50, 100, 70, 40, "Tentacool", Type.EAU, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 30, new E_Level(73, 30), null, null, new Stats[]{Stats.DEFSPE}, 0.9f, 45.5f, "Il vit en bord de mer. Les pêcheurs se font souvent arroser d'acide quand ils en accrochent un.", 105, 1250000, 190);
		 listePoke[73] = new Espece(70, 65, 80, 120, 100, 80, "Tentacruel", Type.EAU, Type.POISON, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.DEFSPE, Stats.DEFSPE}, 1.6f, 55f, "Ses tentacules sont rétractés au repos. En situation de chasse, ils s'allongent pour prendre ses proies au piège.", 205, 1250000, 60);
		 listePoke[74] = new Espece(80, 100, 30, 30, 20, 40, "Racaillou", Type.ROCHE, Type.SOL, Espece.EVOLUTION_BY_LEVEL, 25, new E_Level(75, 25), null, null, new Stats[]{Stats.DEF}, 0.4f, 20f, "Il vit dans les plaines ou les montagnes. On le confond souvent avec un petit caillou.", 73, 1059860, 255);
		 listePoke[75] = new Espece(95, 115, 45, 45, 35, 55, "Gravalanch", Type.ROCHE, Type.SOL, Espece.EVOLUTION_BY_TRADE, -1, new E_Trade(76), null, null, new Stats[]{Stats.DEF, Stats.DEF}, 1f, 105f, "D'une nature téméraire, il se moque de perdre des parties de son corps quand il dévale les pentes.", 134, 1059860, 120);
		 listePoke[76] = new Espece(120, 130, 55, 65, 45, 80, "Grolem", Type.ROCHE, Type.SOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.DEF, Stats.DEF, Stats.DEF}, 1.4f, 300f, "Aucun explosif ne pourrait entamer sa carapace de pierre. Il mue une fois par an.", 177, 1059860, 45);
		 listePoke[77] = new Espece(85, 55, 65, 65, 90, 50, "Ponyta", Type.FEU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 40, new E_Level(48, 40), null, null, new Stats[]{Stats.VIT}, 1f, 30f, "    Chancelantes à la naissance, ses pattes deviennent très vite sûres et solides à force de galoper.", 152, 1000000, 190);
		 listePoke[78] = new Espece(100, 70, 80, 80, 105, 65, "Galopa", Type.FEU, Type.AUCUN, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1.7f, 95f, "Au grand galop, sa crinière de feu disperse au vent une myriade d'étincelles ardentes.", 192, 1000000, 60);
		 listePoke[79] = new Espece(65, 65, 40, 40, 15, 90, "Ramoloss", Type.EAU, Type.PSY, Espece.EVOLUTION_BY_LEVEL, 37, new E_Level(80, 37), null, null, new Stats[]{Stats.PV}, 1.2f, 36f, "Il est tellement paresseux qu'il lui faut une journée pour remarquer qu'on lui mord la queue.", 99, 1000000, 190);
		 listePoke[80] = new Espece(75, 110, 100, 80, 30, 95, "Flagadoss", Type.EAU, Type.PSY, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.DEF, Stats.DEF}, 1.6f, 78.5f, "Le Kokiyas accroché à sa queue est friand de ce qu'il dévore et ne veut pas lâcher prise.", 164, 1000000, 75);
		 listePoke[81] = new Espece(35, 70, 95, 55, 45, 25, "Magneti", Type.ELECTRIQUE, Type.ACIER, Espece.EVOLUTION_BY_LEVEL, 30, new E_Level(81, 30), null, null, new Stats[]{Stats.ATKSPE},0.3f, 6f, "Les parties sur les côtés de son corps génèrent une énergie lui permettant de léviter.", 89, 1000000, 190);
		 listePoke[82] = new Espece(60, 95, 120, 70, 70, 50, "Magnéton", Type.ELECTRIQUE, Type.ACIER, Espece.EVOLUTION_BY_PLACE, -1, new E_Land(0, "Grotte Electrac"), null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE}, 1f, 60f, "Des groupes apparaissent si des taches solaires couvrent le soleil. Il brouillent les télévisions.", 161, 1000000, 60);
		 listePoke[83] = new Espece(65, 55, 58, 62, 52, 52, "Canarticho", Type.NORMAL, Type.VOL, Espece.NO_EVOLUTION, -1, ne, null, null, new Stats[]{Stats.ATK}, 0.8f, 15f, "Il utilise le légume qu'il tient comme s'il s'agissait d'une épée.", 94, 1000000, 45);
//		 listePoke[84] =
//		 listePoke[85] =
//		 listePoke[86] =
//		 listePoke[87] =
//		 listePoke[88] =
//		 listePoke[89] =
		 listePoke[90] = new Espece(65, 100, 45, 25, 40, 30, "Kokiyas", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(91, Item.getItem("Pierre Feu")), null, null, new Stats[]{Stats.DEF}, 0.3f, 4f, "Il se referme sur un ennemi pour attaquer mais ceci le rend vulnérable et il ne le fait que rarement.", 97, 1250000, 190);
		 listePoke[91] = new Espece(95, 180, 85, 45, 70, 50, "Crustabri", Type.EAU, Type.GLACE, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEF, Stats.DEF}, 1.5f, 132.5f, "Sa coquille est extrêmement résistante. Rien ne peut la détruire, pas même une bombe. Il ne l'ouvre que lorsqu'il attaque.", 203, 1250000, 60);
		 listePoke[92] = new Espece(35, 30, 100, 35, 80, 30, "Fantominus", Type.SPECTRE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 25,new E_Level(93, 25), null, null, new Stats[]{Stats.ATKSPE}, 1.3f, 0.1f, "Son corps composé de gaz toxique pourrait asphyxier n'importe qui en quelques secondes.", 95, 1059860, 190);
		 listePoke[93] = new Espece(50, 45, 115, 55, 95, 45, "Spectrum", Type.SPECTRE, Type.POISON, Espece.EVOLUTION_BY_TRADE, -1, new E_Item(94, Item.getItem("Pierre Feu")), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1.6f, 0.2f, "Il vole l'énergie vitale de l'ennemi d'un coup de langue gazeuse. Il aime chasser dans l'ombre.", 126, 1059860, 90);
//		 listePoke[94] =
//		 listePoke[95] = 
		 listePoke[96] = new Espece(48, 45, 43, 90, 42, 60, "Soporifik", Type.PSY, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 26,new E_Level(97, 26), null, null, new Stats[]{Stats.DEFSPE}, 1f, 32f, "Si vous pensez avoir rêvé mais que vous ne vous en souvenez pas, c'est que Soporifik a tout mangé.", 102, 1000000, 190);
		 listePoke[97] = new Espece(73, 70, 73, 115, 67, 85, "Hypnomade", Type.PSY, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEFSPE, Stats.DEFSPE}, 1f, 75f, "La vue de son pendule oscillant endort en trois secondes, même quand on vient de se réveiller.", 165, 1000000, 75);
		 listePoke[98] = new Espece(105, 90, 25, 25, 50, 30, "Krabby", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 28,new E_Level(99, 28), null, null, new Stats[]{Stats.ATK}, 0.4f, 6.5f, "Il creuse son terrier sur des plages sablonneuses. Ses pinces repoussent si on les brise.", 115, 1000000, 255);
		 listePoke[99] = new Espece(130, 115, 50, 50, 75, 55, "Kraboss", Type.EAU, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1.3f, 60f, "Sa pince devient énorme. S'il la soulève trop vite, il risque de perdre l'équilibre.", 206, 1000000, 60);
		 listePoke[100] = new Espece(30, 50, 55, 55, 100, 40, "Voltorbe", Type.ELECTRIQUE, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 30,new E_Level(101, 30), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 0.5f, 10.4f, "Découvert en même temps que les Poké Balls. Il paraît qu'il existe un lien entre les deux.", 103, 1000000, 190);
		 listePoke[101] = new Espece(50, 70, 80, 80, 140, 60, "Electrode", Type.ELECTRIQUE, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1.2f, 66.6f, "Il stocke tellement d'énergie dans son corps qu'une simple secousse peut le faire exploser.", 150, 1000000, 60);
		 listePoke[102] = new Espece(40, 80, 60, 45, 140, 60, "Noeunoeuf", Type.PLANTE, Type.PSY, Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(103, Item.getItem("Pierre Plante")), null, null, new Stats[]{Stats.DEF}, 0.4f, 2.5f, "Il stocke tellement d'énergie dans son corps qu'une simple secousse peut le faire exploser.", 98, 1250000, 90);
		 listePoke[103] = new Espece(95, 85, 125, 65, 55, 95, "Noadkoko", Type.PLANTE, Type.PSY, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEF}, 2f, 120f, "Il stocke tellement d'énergie dans son corps qu'une simple secousse peut le faire exploser.", 215, 1250000, 45);
		 listePoke[104] = new Espece(50, 95, 40, 50, 35, 50, "Osselait", Type.SOL, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 28,new E_Level(105, 28), null, null, new Stats[]{Stats.DEF}, 0.4f, 6.5f, "Il porte constamment le crâne de sa mère. Personne ne sait à quoi il ressemble sans ce crâne.", 87, 1000000, 190);
		 listePoke[105] = new Espece(80, 110, 50, 80, 45, 60, "Ossatueur", Type.SOL, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEF, Stats.DEF}, 1f, 45f, "Il porte constamment le crâne de sa mère. Personne ne sait à quoi il ressemble sans ce crâne.", 124, 1000000, 75);
		 listePoke[106] = new Espece(120, 53, 35, 110, 87, 50, "Kicklee", Type.COMBAT, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1.4f, 49.8f, "Ses pattes élastiques s'allongent, ce qui ne manque jamais de surprendre au premier combat.", 139, 1000000, 45);
		 listePoke[107] = new Espece(105, 79, 35, 110, 76, 50, "Tygnon", Type.COMBAT, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEFSPE, Stats.DEFSPE}, 1.4f, 50.2f, "Même le béton cède sous ses poings dévastateurs. Au combat, il s'essouffle au bout de 3 minutes.", 140, 1000000, 45);
        	 listePoke[108] = new Espece(55, 75, 60, 75, 30, 90, "Excelangue", Type.NORMAL, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.PV, Stats.PV}, 1.2f, 65.5f, "Chaque fois qu'Excelangue découvre quelque chose de nouveau, il le lèche. Sa mémoire est basée sur le goût et la texture des objets. Il n'aime pas les choses acides.", 127, 1000000, 45);
		 listePoke[109] = new Espece(65, 95, 60, 45, 35, 40, "Smogo", Type.POISON, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 35,new E_Level(110, 35), null, null, new Stats[]{Stats.DEF}, 0.6f, 1f, "Son corps très fin en forme de ballon est rempli d'un horrible gaz toxique. L'air est nauséabond à proximité de ce Pokémon.", 114, 1000000, 190);
		 listePoke[110] = new Espece(90, 120, 85, 70, 60, 65, "Smogogo", Type.POISON, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEF}, 1.2f, 9.5f, "Il peut arriver que deux Smogo mutent et s'associent pour former un Smogogo, mais c'est très rare.", 173, 1000000, 60);
		 listePoke[111] = new Espece(85, 95,  30, 30, 25, 30, "Rhinocorne", Type.SOL, Type.ROCHE,Espece.EVOLUTION_BY_LEVEL, 42, new E_Level (112, 42), null, null, new Stats[]{Stats.DEF}, 1f, 115f, "Ses petites jambes ne lui permettent pas de tourner facilement. Il ne peut charger que tout droit.", 135, 1250000, 120);
		 listePoke[112] = new Espece(130, 120, 45, 45, 40, 105, "Rhinoféros", Type.SOL, Type.ROCHE,Espece.EVOLUTION_BY_TRADE, -1, new E_TradeItem(0, Item.getItem("Protecteur")), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1.9f, 120f, "Son épiderme très épais lui permet de survivre dans un environnement où il fait plus de 2000°c.", 204, 1250000, 60);
		 listePoke[113] = new Espece(5, 5, 35, 105, 50, 250, "Leveinard", Type.NORMAL, Type.AUCUN,Espece.NO_EVOLUTION, -1, new E_Nope (), null, null, new Stats[]{Stats.PV, Stats.PV}, 1.1f, 34.6f, "Il est censé apporter la joie. Ce Pokémon charitable offre ses œufs aux blessés.", 395, 800000, 30);				      
		 listePoke[114] = new Espece(55, 115, 100, 40, 60, "Saquedeneu", Type.PLANTE, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E.Nope (), null, null, new Stats[]{Stats.DEF}, 1f, 35f, "Il paralyse tout ce qui bouge avec ses lianes. Elles vous chatouillent si vous êtes capturé.", 166, 1000000, 45);
		 listePoke[115] = new Espece(95, 80, 40, 80, 90, "Kangourex", Type.NORMAL, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E.Nope (), null, null, new Stats[]{Stats.PV, Stats.PV}, 2.2f, 80f, "Il élève ses petits dans sa poche ventrale. Il attend d'être en lieu sûr pour les laisser jouer dehors.", 175, 1000000, 45);
		 listePoke[116] = new Espece(40, 70, 70, 25, 60, "Hypotrempe", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 32, new E_Level (117, 32), null, null, new Stats[]{Stats.ATKSPE}, 0.4f, 8f, "Il abat les insectes volants en leur tirant un jet d'encre depuis la surface de l'eau. Ses tirs sont toujours précis.", 83, 1059860, 255);
         	 listePoke[117] = new Espece(65, 95, 95, 45, 85, "HYpocéan", Type.EAU, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E.Nope (), null, null, new Stats[]{Stats.DEF, Stats.ATKSPE}, 1.2f, 25f, "Il peut nager à l'envers en agitant ses petites nageoires pectorales.", 155, 1000000, 75);
//		 listePoke[118] = new Espece(
//		 listePoke[119] = new Espece(
//		 listePoke[120] = new Espece(
//		 listePoke[121] = new Espece(
//		 listePoke[122] = new Espece(
//		 listePoke[123] = new Espece(
//		 listePoke[124] = new Espece(
//		 listePoke[125] = new Espece(
//		 listePoke[126] = new Espece(
//		 listePoke[127] = new Espece(
//		 listePoke[128] = new Espece(
//		 listePoke[129] = new Espece(
//		 listePoke[130] = new Espece(
//		 listePoke[131] = new Espece(
//		 listePoke[132] = new Espece(
//		 listePoke[133] = new Espece(
//		 listePoke[134] = new Espece(
//		 listePoke[135] = new Espece(
//		 listePoke[136] = new Espece(
		 listePoke[137] = new Espece(60, 70, 85, 75, 40, 65, "Porygon", Type.NORMAL, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_TradeItem(0, Item.getItem("Ameliorator")), null, null, new Stats[]{Stats.ATK}, 0.8f, 36.5f, "Ce Pokémon a été développé en Java, il adore se fofiler dans les programmes pour tout modifier.", 133, 1000000, 45);
		 listePoke[138] = new Espece(40, 100, 90, 55, 35, 35, "Amonita", Type.ROCHE, Type.EAU, Espece.EVOLUTION_BY_LEVEL, 40,new E_Level(138, 40), null, null, new Stats[]{Stats.DEF}, 0.4f, 7.5f, "Recréé à partir d'un fossile, il utilise l'air dans sa coquille pour s'enfoncer dans l'eau ou faire surface.", 99, 1000000, 45);
		 listePoke[139] = new Espece(60, 125, 115, 70, 55, 70, "Amonistar", Type.ROCHE, Type.EAU, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEF, Stats.DEF}, 1f, 35f, "Une fois enroulé autour de sa proie, il ne la laisse pas repartir et la dévore avec ses crocs.", 199, 1000000, 45);
		 listePoke[140] = new Espece(80, 90, 55, 45, 55, 30, "Kabuto", Type.ROCHE, Type.EAU, Espece.EVOLUTION_BY_LEVEL, 40,new E_Level(140, 40), null, null, new Stats[]{Stats.DEF}, 0.5f, 11.5f, "Ce Pokémon a été reconstitué à partir du fossile d'une ancienne créature. Il se protège à l'aide de sa carapace.", 99, 1000000, 45);
		 listePoke[141] = new Espece(115, 105, 65, 70, 80, 60, "Kabutops", Type.ROCHE, Type.EAU, Espece.NO_EVOLUTION, -1,new E_Level(140, 40), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 1.3f, 40.5f, "C'est un très bon nageur. Il lacère sa proie de ses longues griffes et en absorbe les fluides corporels.", 199, 1000000, 45);
		 listePoke[142] = new Espece(105, 65, 60, 75, 130, 80, "Ptéra", Type.ROCHE, Type.VOL, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1.8f, 59f, "Ce terrible Pokémon a dominé les cieux d'une autre époque, terrorisant ses ennemis.", 202, 1250000, 45);
		 listePoke[143] = new Espece(110, 65, 65, 110, 30, 160, "Ronflex", Type.NORMAL, Type.AUCUN, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.PV, Stats.PV}, 2.1f, 460f, "Les journées de Ronflex se résument aux repas et aux siestes. IL est tellement gentil que les enfants n'hésitent pas à jouer sur son énorme ventre.", 154, 1250000, 25);
		 listePoke[144] = new Espece(85, 100, 95, 125, 85, 90, "Artikodin", Type.ELECTRIQUE, Type.VOL, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 1.7f, 55.4f, "Le légendaire oiseau des glaces. On dit qu'il apparaît aux gens perdus dans les sommets.", 215, 1250000, 3);
		 listePoke[145] = new Espece(90, 85, 125, 90, 100, 90, "Electhor", Type.ELECTRIQUE, Type.VOL, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.6f, 52.6f, "Un Pokémon Oiseau légendaire dont on dit qu'il vit dans les nuages d'orage. Il contrôle la foudre.", 216, 1250000, 3);
		 listePoke[146] = new Espece(100, 90, 125, 85, 90, 90, "Sulfura", Type.FEU, Type.VOL, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 2f, 60f, "C'est un Pokémon oiseau légendaire capable de contrôler le feu. On raconte que lorsqu'il est blessé, il se baigne dans le magma d'un volcan pour se soigner.", 217, 1250000, 3);
         listePoke[147] = new Espece(64, 45, 50, 50, 50, 41, "Minidraco", Type.DRAGON, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 0,new E_Level(148, 30), null, null, new Stats[]{Stats.ATK}, 1.8f, 3.3f, "Minidraco mue constamment, renouvelant sans arrêt sa peau. En effet, l'énergie vitale de son corps augmente régulièrement et sa mue lui permet d'éviter d'atteindre des niveaux incontrôlables.", 67, 1250000, 45);
		 listePoke[148] = new Espece(84, 65, 70, 70, 70, 61, "Draco", Type.DRAGON, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 1,new E_Level(149, 55), null, null, new Stats[]{Stats.ATK, Stats.ATK}, 4f, 16.5f, "Draco stocke une quantité d'énergie considérable dans son corps. On raconte qu'il peut modifier les conditions climatiques autour de lui en déchargeant l'énergie contenue dans les cristaux de son cou et de sa queue.", 144, 1250000, 45);
		 listePoke[149] = new Espece(134, 95, 100, 100, 80, 91, "Dracoloss", Type.DRAGON, Type.VOL, Espece.NO_EVOLUTION, -1, new E_Nope(), null, null, new Stats[]{Stats.ATK, Stats.ATK, Stats.ATK}, 2.2f, 210f, "On raconte qu'il vit quelque part en mer. Il guide les équipages naufragés jusqu'à la terre ferme.", 218, 1250000, 45);
		 //listePoke[150] = 
	     //listePoke[151] = 
		 //listePoke[387] = new Espece(68, 64, 45, 55, 31, 55, "Tortipouss", Type.PLANTE, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 0,new E_Level(388, 0), null, null, new Stats[]{Stats.ATK}, 0.4f, 10.2f, "Son corps assimile la lumière du soleil par photosynthèse. Sa carapace est faite de terre durcie.", 64, 1059860);
		 
		 for(Espece esp : listePoke){
			 if(esp != null){
				 esp.checkEvol();
			 }
		 }
	 }
	 /**
	  * Initialise les sprites
	  */
	 public static void initSprites(){
		 
	 }
	 
	 public static void initKeys(){
		 StringKey.initialisateKeys();
	 }
	 
	 public static void initItems(){
		 Item.init();
	 }
	 
	 public static void init(){
		 initKeys();
		 initSprites();
		
		 initItems();
		 initPokemons();
	 }
	 
	 
}
