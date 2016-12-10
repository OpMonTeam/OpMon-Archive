package jlppc.regimys.launch;

import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

import jlppc.regimys.core.save.Parameters;
import jlppc.regimys.creator.pokemon.Main;
import jlppc.regimys.enums.Caractere;
import jlppc.regimys.fight.Fight;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.attacks.Berceuse;
import jlppc.regimys.objects.attacks.Charge;
import jlppc.regimys.objects.attacks.GodAttackPleaseDontHackAndCheat;
import jlppc.regimys.objects.attacks.Rugissement;
import jlppc.regimys.objects.attacks.Soin;
import jlppc.regimys.objects.attacks.Triplattaque;
import jlppc.regimys.objects.items.Item;
import jlppc.regimys.playercore.Equipe;
import jlppc.regimys.playercore.Player;
import jlppc.regimys.tempgui.ChoosePoke;
import jlppc.utils.FormattedString;
import jlppc.utils.Log;
import jlppc.utils.Static;
/**
 * Demmare le programme.
 * @author Jlppc
 *
 */
@Static
public class Start {
	static{
		try{
			Initializer.init();
		}catch(Throwable e){
			System.err.println("Une erreur est survenue lors du demmarage du programme. Merci d'en informer de toute urgence le developpeur.");
			System.exit(-99999);
		}
		
	}
	/**
	 * Liste des noms qui apparaitront dans le Nomdujoueur vs unElementDeCeTableau
	 */
	public static String[] trainers = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "NikolaÃ¯", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal"};
	/**La version du jeu*/
	public static float version = 0.07f;
	/**La lettre du jeu (Va surement être supprimée, puisque jamais mise a jour)*/
	public static char commits = ' ';
	

	/**Le nombre après pre , dans le cas d'un depassement de prévisions*/
	public static int preNbre = 0;
	/**Verifie si il y a un pre, pour l'inclure dans versionS*/
	public static boolean pre = (preNbre != 0);
	/**Les sous versions (x.x.sousVers)*/
	public static int sousVers = 0;
	/**Verifie si il y a une sous version*/
	public static boolean sousVersIs = (sousVers != 0);
	/**Chaine de caractère indiquant la version du jeu*/
	public static String versionS = "Alpha " + version  + (sousVersIs ? "." + sousVers : "") + (pre ? (" pre " + preNbre) : "") + commits;
	
	//Utilitaires pratiques
	/**
	 * Le générateur d'aléatoire du programme. Au lieu de creer plein d'objets Random, je n'en crée que un, utilisé dans tout le programme.
	 */
	public static Random rand = new Random();
	/**La variable contenant le joueur*/
	public static Player joueur;
	/**
	 * Entrées (utilisé au début du programme)
	 */
	public static Scanner sc = new Scanner(System.in);
	
	public static Main window = new Main();
	
	public static String sep = new String(System.getProperty("os.name").contains("win") ? "\\" : "/");

	/**
	 * Le prochain main du launcher
	 * @param saves - Les fichiers de sauvegarde
	 */
	public static void main(File[] saves) throws Throwable{
		String playername;
		if((Parameters.checkParam("playerexists") ? Parameters.getParam("playerexists").getValue().equals("true") : false)){
			joueur = Player.getPlayer(new File("player.rsave"));
		}else{
			System.out.println("Bienvenue dans le monde non achevé des pokémon! Quel est ton nom? : ");
			playername = sc.nextLine();
			joueur = new Player(playername);
			System.out.println("Une boite de dialogue s'est ouverte pour choisir ton Pokémon.");
			ChoosePoke cp = new ChoosePoke();
			Espece esp = Initializer.listePoke[cp.getEspChoosen()];
			System.out.println("Pokémon choisi : " + esp.getSurnom());
			System.out.println("Veux-tu donner un surnom a ton Pokémon ? (Tapez true pour Oui et false pour Non ) : ");
			boolean isS = sc.nextBoolean();
			String surnom = esp.getSurnom();
			if(isS){
				sc.nextLine();
				System.out.println("Surnom : ");
				surnom = sc.nextLine();
			}
			Pokemon first = new Pokemon(surnom, esp, 5, new Attaque[]{GodAttackPleaseDontHackAndCheat.class.newInstance(), Rugissement.class.newInstance(), Berceuse.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
			joueur.addPokeToEquipe(first);
			System.out.println("C'est parti pour les combats!");
			
			joueur.addItem(Item.searchItem(Item.getItem("Potion")));joueur.addItem(Item.searchItem(Item.getItem("Potion")));//Oui il y a deux instructions en deux lignes. ET ALORS?
			Player.savePlayer(new File("player.rsave"));
			Parameters.modifyOrAddParam("playerexists", "true", "Définit si le joueur a deja été crée ou non.");
			
		}
		int combatsNumber = 0;
		while(true){
			System.out.println("Equipe : " + joueur.getEquipe());
			Parameters.updateFile();
			combatsNumber++;
			System.out.println("Combat n°" + combatsNumber);
			
			joueur.healPoke();
			Pokemon[] equipeAdverse = new Pokemon[6];
			for(int i = -1; i < rand.nextInt(6); i++){
				Espece eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
				while(eAdv == null){
					eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
				}
				equipeAdverse[i + 1] = new Pokemon(eAdv, joueur.getPoke(0).getLevel() - rand.nextInt(3), new Attaque[]{Charge.class.newInstance(), Rugissement.class.newInstance(), Soin.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
			}
			Equipe adv = new Equipe(trainers[rand.nextInt(trainers.length)],equipeAdverse);
			FormattedString.outPrintln("%o (%o pokemons) vs %o (%o pokemons)!", joueur.getName(), joueur.getEquipe().getSize(), adv.getNom(), adv.getSize());

			Fight.fight(joueur.getEquipe(), adv);
			int itemID = rand.nextInt(Item.itemList.size());
			joueur.addItem(itemID);
			System.out.println("Ajout de l'item " + Item.getItem(itemID).getName());
			Player.savePlayer(new File("player.rsave"));

		}
		
	
	}
	
	/**
	 * Le main, permet de... demmarer le programme. Tu ne le savais pas? ;-)
	 * @param args
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 */
	public static void main(String[] args){
		try{
			try{
				if(args[0].startsWith("--")){
					if(args[0].equals("--creator")){
						try{
							if(args[1].equals("pokemon")){
								window.frmCrateurDePokmon.setVisible(true);
								
							}else{
								System.out.println("Un des mots suivants doivent apparaitre aprÃ¨s --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
								System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
							}
						}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
							System.out.println("Un des mots suivants doivent apparaitre aprÃ¨s --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
							System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. -99999 : Erreur dans l'initialiseur du programme -1 : Erreur fatale. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
						}
					}else if(args[0].equals("--version")){
						System.out.println("Pok�mon Regimys version " + versionS);
					}
					else{
						System.out.println("Page d'aide des arguments de Pokemon Regimys." + Log.saut + "--creator : Permet d'affcher une fenetre de creation d'un objet (Voir --creator aide)" + Log.saut + "--help : Affiche cette page");
					}
					
				}else{
					System.out.println("L'ouverture de fichiers de sauvegarde par ce biais n'est actuellement pas disponible. Lancement du jeu...");
				}
			}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
				
				String playername;
				if((Parameters.checkParam("playerexists") ? Parameters.getParam("playerexists").getValue().equals("true") : false)){
					joueur = Player.getPlayer(new File("player.rsave"));
				}else{
					System.out.println("Bienvenue dans le monde non achevé des pokémon! Quel est ton nom? : ");
					playername = sc.nextLine();
					joueur = new Player(playername);
					System.out.println("Une boite de dialogue s'est ouverte pour choisir ton Pokémon.");
					ChoosePoke cp = new ChoosePoke();
					Espece esp = Initializer.listePoke[cp.getEspChoosen()];
					System.out.println("Pokémon choisi : " + esp.getSurnom());
					System.out.println("Veux-tu donner un surnom a ton Pokémon ? (Tapez true pour Oui et false pour Non ) : ");
					boolean isS = sc.nextBoolean();
					String surnom = esp.getSurnom();
					if(isS){
						sc.nextLine();
						System.out.println("Surnom : ");
						surnom = sc.nextLine();
					}
					Pokemon first = new Pokemon(surnom, esp, 5, new Attaque[]{GodAttackPleaseDontHackAndCheat.class.newInstance(), Rugissement.class.newInstance(), Berceuse.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
					joueur.addPokeToEquipe(first);
					System.out.println("C'est parti pour les combats!");
					
					joueur.addItem(Item.searchItem(Item.getItem("Potion")));joueur.addItem(Item.searchItem(Item.getItem("Potion")));//Oui il y a deux instructions en deux lignes. ET ALORS?
					Player.savePlayer(new File("player.rsave"));
					Parameters.modifyOrAddParam("playerexists", "true", "Définit si le joueur a deja été crée ou non.");
					
				}
				int combatsNumber = 0;
				while(true){
					System.out.println("Equipe : " + joueur.getEquipe());
					Parameters.updateFile();
					combatsNumber++;
					System.out.println("Combat n°" + combatsNumber);
					
					joueur.healPoke();
					Pokemon[] equipeAdverse = new Pokemon[6];
					for(int i = -1; i < rand.nextInt(6); i++){
						Espece eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
						while(eAdv == null){
							eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
						}
						equipeAdverse[i + 1] = new Pokemon(eAdv, joueur.getPoke(0).getLevel() - rand.nextInt(3), new Attaque[]{Charge.class.newInstance(), Rugissement.class.newInstance(), Soin.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
					}
					Equipe adv = new Equipe(trainers[rand.nextInt(trainers.length)],equipeAdverse);
					FormattedString.outPrintln("%o (%o pokemons) vs %o (%o pokemons)!", joueur.getName(), joueur.getEquipe().getSize(), adv.getNom(), adv.getSize());

					Fight.fight(joueur.getEquipe(), adv);
					int itemID = rand.nextInt(Item.itemList.size());
					joueur.addItem(itemID);
					System.out.println("Ajout de l'item " + Item.getItem(itemID).getName());
					Player.savePlayer(new File("player.rsave"));

				}
				
			}
		}catch(Exception | Error e){
			System.err.println("Une erreur est survenue. Merci de contacter le developpeur.");
			e.printStackTrace();
			if(e instanceof FileNotFoundException || e instanceof EOFException){
				Parameters.modifyOrAddParam("playerexists", "false");
				if(new File("player.rsave").exists()){
					new File("player.rsave").delete();
				}
				try {
					Parameters.updateFile();
				} catch (IOException e1) {
					System.err.println(-9);
					System.exit(-9);
				}
			}
			System.exit(-1);
		}
		
		
	}

}
