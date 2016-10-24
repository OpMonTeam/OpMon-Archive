package jlppc.regimys.launch;

import jlppc.regimys.enums.Caractere.Stats;
import jlppc.regimys.enums.Type;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Typedef;
import jlppc.regimys.objects.Typedef.Null;
import jlppc.regimys.util.text.StringKey;

/**
 * Permet d'initialiser des choses.
 * @author Jlppc
 *
 */
public class Initializer {
	public static Espece[] listePoke = new Espece[152];
	public static Object[] TODO = {null};
	/***
	 * Initialise les pokemon (espèces)
	 */
	 public static void initPokemons(){
		 listePoke[0] = new Espece(136, 0, 1, 1, 29, 33, "MissingNo.", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 80, listePoke[0], null, null, new Stats[]{Stats.ATK}, 0f, 0f, "ERROR : MISSINGNO.", 0);
		 listePoke[1] = new Espece(49, 49, 65, 65, 45, 45, "Bulbizarre", Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 16, listePoke[2], null, null, new Stats[]{Stats.ATKSPE}, 0.7f, 6.9f, "Il a une étrange graine plantée sur son dos. Elle grandit avec lui depuis sa naissance.", 64);
		 listePoke[2] = new Espece(62, 63, 80, 80, 60, 60, "Herbizarre",Type.PLANTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 32, listePoke[3], null, null, new Stats[]{Stats.ATKSPE, Stats.DEFSPE}, 1f, 13f, "Lorsque le bourgeon sur son dos éclot, il répand un doux parfum pour célébrer sa floraison.", 141);
		 listePoke[3] = new Espece(82, 83, 100, 100, 80, 80, "Florizarre", Type.PLANTE, Type.POISON, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.DEFSPE}, 2f, 100f, "Ses pétales lui servent à capter la lumière du soleil. Il peut ainsi en canaliser l'énergie.", 236);
		 listePoke[4] = new Espece(52, 43, 60, 50, 65, 39, "Salamèche", Type.FEU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 16, listePoke[5], null, null, new Stats[]{Stats.VIT}, 0.6f, 8.5f, "La flamme sur sa queue représente l'énergie vitale de Salamèche. Quand il est vigoureux, elle brûle plus fort.", 65);
		 listePoke[5] = new Espece(64, 58, 80, 65, 80, 58, "Reptincel", Type.FEU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 36, listePoke[6], null, null, new Stats[]{Stats.VIT, Stats.ATKSPE}, 1.1f, 19f, "En agitant sa gueue, il peut élever la température à un niveau incroyable", 142);
		 listePoke[6] = new Espece(84, 78, 109, 85, 100, 78, "Dracaufeu", Type.FEU, Type.VOL, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.ATKSPE}, 1.7f, 90.5f, "Quand il crache son souffle brûlant, la flamme au bout de sa queue s'embrase.", 209);
		 listePoke[7] = new Espece(48, 65, 50, 64, 43, 44, "Carapuce", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 16, listePoke[8], null, null, new Stats[]{Stats.DEF}, 0.5f, 9f, "Caché sous l'eau, il crache un jet d'eau sur sa proie et se cache à l'intérieur de sa carapace.", 66);
		 listePoke[8] = new Espece(63, 80, 65, 80, 58, 59, "Carabaffe", Type.EAU, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 36, listePoke[9],null, null, new Stats[]{Stats.DEF, Stats.DEFSPE}, 1f, 22.5f,"On prétend qu'il vit 10 000 ans. Sa queue duveteuse est un symbole de longévité populaire.", 143 );
		 listePoke[9] = new Espece(83, 100, 85, 105, 78, 79, "Tortank", Type.EAU, Type.AUCUN, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.DEFSPE, Stats.DEFSPE, Stats.DEFSPE}, 1.6f, 85.5f, "Il écrase ses adversaires de tout son poids pour leur faire perdre connaissance. Il rentre dans sa carapace s'il se sent en danger.", 210);
		 listePoke[10] = new Espece(30, 35, 20, 20, 45, 45, "Chenipan", Type.INSECTE, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 7, listePoke[11], null, null, new Stats[]{Stats.PV}, 0.3f, 2.9f, "Ses pattes ont des ventouses lui permettant de grimper sur toute surface, notamment les arbres.", 53);
		 listePoke[11] = new Espece(20, 55, 25, 25, 30, 50, "Chrysacier", Type.INSECTE, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 10, listePoke[12], null, null, new Stats[]{Stats.DEF, Stats.DEF}, 0.7f, 9.9f, "Son corps frêle est protégé par sa carapace d'acier. Il encaisse les coups durs en attendant d'évoluer.", 72);
		 listePoke[12] = new Espece(45, 50, 90, 80, 70, 60, "Papilusion", Type.INSECTE, Type.VOL, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.ATKSPE, Stats.ATKSPE, Stats.DEFSPE},1.1f, 32f, "Ses ailes sont recouvertes d'une poudre les protégeant de la pluie. Ce Pokémon peut donc voler pendant de grosses averses.", 160);
		 listePoke[13] = new Espece(35, 30, 20, 20, 50, 40, "Aspicot", Type.INSECTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 7, listePoke[14], null, null, new Stats[]{Stats.VIT}, 0.3f, 3.2f, "Son aiguillon empoisonné est très dangereux. Son corps est coloré afin de repousser ses ennemis.", 52);
		 listePoke[14] = new Espece(25, 50, 25, 25, 35, 45, "Coconfort", Type.INSECTE, Type.POISON, Espece.EVOLUTION_BY_LEVEL, 10, listePoke[15], null, null, new Stats[]{Stats.DEF, Stats.DEF}, 0.6f, 10f, "Incapable de se déplacer de lui-même, il se défend en durcissant sa carapace.", 71);
		 listePoke[15] = new Espece(80, 40, 45, 80, 75, 65, "Dardargnan", Type.INSECTE, Type.POISON, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.ATK, Stats.ATK, Stats.DEFSPE}, 1f, 29.5f, "Il se sert de ses trois aiguillons empoisonnés pour attaquer sans relâche ses adversaires.", 159);
		 listePoke[16] = new Espece(45, 40, 35, 35, 56, 40, "Roucool", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 18, listePoke[17], null, null, new Stats[]{Stats.VIT}, 0.3f, 1.8f, "Ce Pokémon docile préfère éviter le combat. Toutefois, il se montre très féroce quand on l'agresse.", 55);
		 listePoke[17] = new Espece(60, 55, 50, 50, 71, 63, "Roucoups", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 36, listePoke[18], null,null, new Stats[]{Stats.VIT, Stats.VIT}, 1.1f, 30f, "Il protège son territoire avec ardeur et repousse à coup de bec tout intrus.", 113);
		 listePoke[18] = new Espece(80, 75, 70, 70, 101, 83, "Roucarnage", Type.NORMAL, Type.VOL, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.VIT, Stats.VIT, Stats.VIT}, 1.5f, 39.5f, "Roucarnage déploie ses ailes majestueuses pour effrayer ses ennemis. Il peut voler à Mach 2.", 172);
		 listePoke[19] = new Espece(56, 35, 25, 35, 72, 30, "Rattata", Type.NORMAL, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 20, listePoke[20], null, null, new Stats[]{Stats.VIT}, 0.3f, 3.5f, "Vivant là où se trouve la nourriture, ce charognard passe ses journées à la rechercher.", 57);
		 listePoke[20] = new Espece(81, 60, 50, 70, 97, 55, "Rattatac", Type.NORMAL, Type.AUCUN, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.VIT, Stats.VIT}, 0.7f, 18.5f, "Ses pattes arrière lui permettent de traverser les rivières. Il est toujours en quête de nourriture.", 127);
		 listePoke[21] = new Espece(60, 30, 31, 31, 70, 40, "Piafabec", Type.NORMAL, Type.VOL, Espece.EVOLUTION_BY_LEVEL, 20, listePoke[22], null, null, new Stats[]{Stats.VIT}, 0.3f, 2f, "Il chasse les insectes dans les hautes herbes. Ses petites ailes lui permettent de voler très vite.", 58);
		 listePoke[22] = new Espece(90, 65, 31, 31, 100, 65, "Rapasdepic", Type.NORMAL, Type.VOL, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.VIT, Stats.VIT}, 1.2f, 38f, "Il vole à très grande vitesse et attaque en chargeant son ennemi.", 162);
		 listePoke[23] = new Espece(60, 44, 40, 54, 55, 35, "Abo", Type.POISON, Type.AUCUN, Espece.EVOLUTION_BY_LEVEL, 22, listePoke[24], null, null, new Stats[]{Stats.ATK}, 2f, 6.9f, "Plus il est âgé, plus son corps est long. Il se love autour des arbres pour se reposer.", 62);
		 listePoke[24] = new Espece(85, 69, 65, 79, 80, 60, "Arbok", Type.POISON, Type.NORMAL, Espece.NO_EVOLUTION, -1, null, null, null, new Stats[]{Stats.ATK, Stats.ATK}, 3.5f, 65f, "Pour apeurer ses ennemis, il gonfle sa poitrine et émet d'étranges sons avec sa bouche.", 147);
	 }
	 /**
	  * Initialise les sprites
	  */
	 public static void initSprites(){
		 
	 }
	 
	 public static void initKeys(){
		 StringKey.initialisateKeys();
	 }
	 
	 
}
