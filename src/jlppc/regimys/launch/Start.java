package jlppc.regimys.launch;

import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.net.URL;
import java.util.Random;
import java.util.Scanner;

import javax.swing.JOptionPane;

import jlppc.regimys.core.save.Parameters;
import jlppc.regimys.creator.pokemon.Main;
import jlppc.regimys.enums.Caractere;
import jlppc.regimys.fight.Fight;
import jlppc.regimys.gui.MainFrame;
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
import jlppc.utils.Log.Entry;
import jlppc.utils.Static;
import jlppc.utils.WIP;
/**
 * Demmare le programme.
 * @author Jlppc
 *
 */
@Static
public class Start {
	static{//Permet d'initialiser toutes les ressources avant meme le début du programme!
		try{
			Initializer.init();
		}catch(Throwable e){
			System.err.println("Une erreur est survenue lors du demmarage du programme. Merci d'en informer de toute urgence le developpeur.");
			e.printStackTrace();
			System.exit(-99999);
		}
		
	}
	public static boolean connected = false;
	/**
	 * Liste des noms qui apparaitront dans le Nomdujoueur vs unElementDeCeTableau
	 */
	public static String[] trainers = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "NikolaÏ¯", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal", "Brahim"};
	/**La version du jeu*/
	public static float version = 0.07f;
	/**La lettre du jeu (Va surement ÃƒÂªtre supprimÃƒÂ©e, puisque jamais mise a jour)*/
	public static char commits = ' ';
	
	public static Thread gameThread;

	/**Le nombre aprÃƒÂ¨s pre , dans le cas d'un depassement de prÃƒÂ©visions*/
	public static int preNbre = 0;
	/**Verifie si il y a un pre, pour l'inclure dans versionS*/
	public static boolean pre = (preNbre != 0);
	/**Les sous versions (x.x.sousVers)*/
	public static int sousVers = 0;
	/**Verifie si il y a une sous version*/
	public static boolean sousVersIs = (sousVers != 0);
	/**Chaine de caractÃƒÂ¨re indiquant la version du jeu*/
	public static String versionS = "Alpha " + version  + (sousVersIs ? "." + sousVers : "") + (pre ? (" pre " + preNbre) : "") + commits;
	
	//Utilitaires pratiques
	/**
	 * Le gÃƒÂ©nÃƒÂ©rateur d'alÃƒÂ©atoire du programme. Au lieu de creer plein d'objets Random, je n'en crÃƒÂ©e que un, utilisÃƒÂ© dans tout le programme.
	 */
	public static Random rand = new Random();
	/**La variable contenant le joueur*/
	public static Player joueur;
	/**
	 * EntrÃƒÂ©es (utilisÃƒÂ© au dÃƒÂ©but du programme)
	 */
	public static Scanner sc = new Scanner(System.in);
	
	public static Main window = new Main();
	/**
	 * Le séparateur du systeme (Oui j'aurais pu utiliser System.getProperty mais flemme)
	 */
	public static String sep = new String(System.getProperty("os.name").contains("win") ? "\\" : "/");
	
	public static File playerSave;
	
	public static File params;
	
	

	/**
<<<<<<< HEAD
	 * Le prochain main du launcher (Ou pas)
	 * @param saves - Les fichiers de sauvegarde (0 : Les paramètres, 1 : Le joueur)
=======
	 * Le prochain main du launcher
	 * @param saves - Les fichiers de sauvegarde (0 : Les paramÃ¨tres, 1 : Le joueur)
>>>>>>> refs/remotes/origin/master
	 */
	public static void main(File[] saves) throws Throwable{//Cette methode c'est de la merde, allez plutot voir le main de base ;-)
		String playername;
		Parameters.paramInit(saves[0]);
		if((Parameters.checkParam("playerexists") ? Parameters.getParam("playerexists").getValue().equals("true") : false)){
			joueur = Player.getPlayer(saves[1]);
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
			Player.savePlayer(saves[1]);
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
			Player.savePlayer(saves[1]);

		}
		
	
	}
	
	/**
	 * Le main, permet de... demmarer le programme. Tu ne le savais pas? ;-)
	 * @param args
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 */
	public static void main(String[] args){
		try{//Pour attraper tous les problèmes...
			try{//Verification des arguments
				if(args[0].startsWith("--")){//La chaine de caractère de début d'argument
					if(args[0].equals("--creator")){//Lance le créateur (De toutes facons il est pas a jour ;-) )
						try{
							if(args[1].equals("pokemon")){//de pokémon
								window.frmCrateurDePokmon.setVisible(true);
							}else{
								System.out.println("Un des mots suivants doivent apparaitre après --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
								System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
							}
						}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
							System.out.println("Un des mots suivants doivent apparaitre après --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
							System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. -99999 : Erreur dans l'initialiseur du programme -1 : Erreur fatale. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
						}
					}else if(args[0].equals("--version")){
						System.out.println("Pokémon Regimys version " + versionS);
					}else if(args[0].equals("--guitest")){
						System.out.println("Test du gui de Pokemon Regimys");
						guiMain();
						System.out.println("PokÃ©mon Regimys version " + versionS);
					}else if(args[0].equals("--launcher")){
						try{
							params = new File(args[1]);
							playerSave = new File(args[2]);
							guiMain();//Lancement du gui
							
						}catch(Throwable e){//Si le format d'argument est incorrect
							e.printStackTrace();
							JOptionPane.showMessageDialog(null, "Désolé, mais cette option ne peut être utilisée que par le launcher (a moins que vous ne sachiez vous en servir)", "Erreur", JOptionPane.ERROR_MESSAGE);
							System.exit(2);
						}
					}
					else{//Si l'argument entré n'existe pas, ou que c'est --help, alors ça affiche ceci.
						System.out.println("Page d'aide des arguments de Pokemon Regimys." + Log.saut + "--creator : Permet d'affcher une fenetre de creation d'un objet (Voir --creator aide)" + Log.saut + "--help : Affiche cette page");
					}
					
				}else{//Sinon y'a pas d'argument!
					System.out.println("Lancement du jeu...");
				}
			}catch(ArrayIndexOutOfBoundsException | NullPointerException e){//Si il n'y a pas d'argument, il detecte donc une exception.
				
				String playername;
				if((Parameters.checkParam("playerexists") ? Parameters.getParam("playerexists").getValue().equals("true") : false)){//Verfifie si un joueur n'est pas déjà sauvegardé
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
					if(isS){//Si on veut donner un surnom
						sc.nextLine();
						System.out.println("Surnom : ");
						surnom = sc.nextLine();
					}
					//Creation du pokémon puis du joueur
					Pokemon first = new Pokemon(surnom, esp, 5, new Attaque[]{GodAttackPleaseDontHackAndCheat.class.newInstance(), Rugissement.class.newInstance(), Berceuse.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
					joueur.addPokeToEquipe(first);
					System.out.println("C'est parti pour les combats!");
					
					joueur.addItem(Item.searchItem(Item.getItem("Potion")));joueur.addItem(Item.searchItem(Item.getItem("Potion")));//Oui il y a deux instructions en deux lignes. ET ALORS?
					Player.savePlayer(new File("player.rsave"));
					Parameters.modifyOrAddParam("playerexists", "true", "Définit si le joueur a deja été crée ou non.");
					
				}
				int combatsNumber = 0;
				while(true){//Lancement des combats
					System.out.println("Equipe : " + joueur.getEquipe());//Descritpion des équipes
					Parameters.updateFile();
					combatsNumber++;
					System.out.println("Combat n°" + combatsNumber);
					
					joueur.healPoke();
					Pokemon[] equipeAdverse = new Pokemon[6];
					for(int i = -1; i < rand.nextInt(6); i++){//Choix des pokémons adverses
						Espece eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
						while(eAdv == null){
							eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
						}
						equipeAdverse[i + 1] = new Pokemon(eAdv, joueur.getPoke(0).getLevel() - rand.nextInt(3), new Attaque[]{Charge.class.newInstance(), Rugissement.class.newInstance(), Soin.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
					}
					Equipe adv = new Equipe(trainers[rand.nextInt(trainers.length)],equipeAdverse);
					FormattedString.outPrintln("%o (%o pokemons) vs %o (%o pokemons)!", joueur.getName(), joueur.getEquipe().getSize(), adv.getNom(), adv.getSize());
					
					Fight.fight(joueur.getEquipe(), adv);//Lancement du combat
					int itemID = rand.nextInt(Item.itemList.size());//Ajout d'un item aléatoire
					joueur.addItem(itemID);
					System.out.println("Ajout de l'item " + Item.getItem(itemID).getName());
					Player.savePlayer(new File("player.rsave"));//Sauvegarde

				}
				
			}
		}catch(Exception | Error e){//Si une erreur est detectée
			System.err.println("Une erreur est survenue. Merci de contacter le developpeur.");
			e.printStackTrace();
			if(e instanceof FileNotFoundException || e instanceof EOFException){//Si l'erreur est a cause du fichier de sauvegarde, il le recrée (perte des données) TODO : Creer un outil permettant d'importer de vieilles sauvegardes.
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
	/**
	 * Permet de gérer une exception. Cette methode va être améliorée
	 * @param e : L'exception
	 * @param fatal : Si l'exception doit faire crash le jeu
	 */
	@WIP
	public static void gererException(Exception e, boolean fatal){
		Log.writeT(fatal ? Entry.FATAL : Entry.EXCEPTION, "Exception : " + e.getClass().getCanonicalName());
		e.printStackTrace();
		
		if(fatal){//Si un crash a lieu
			Log.writeT(Entry.FATAL, "Echec de l'execution du programme. Merci de prevenir les developpeurs.");
			
			JOptionPane.showMessageDialog(null, "<HTML>Une erreur fatale s'est déclanchée dans le programme.<br/> Merci de prevenir les developpeur en leur joignant les fichiers log.txt et errLog.txt. <br/>Merci d'avance, c'est grace a votre intervention que le jeu s'améliorera.</HTML>", "Erreur fatale", JOptionPane.ERROR_MESSAGE);
			Log.close();
			System.exit(1);
		}
	}
	/**
	 * Le main de la version gui.
	 */
	private static void guiMain() {
		File errLog = new File("errLog.txt");//Initialisation du Log et de l'errLog
		try {
			Log.start();
			errLog.createNewFile();
			System.setErr(new PrintStream(errLog));
		} catch (IOException e) {//Si il y a un problème avec la création du log (GROS PROBLEME ALORS!!!)
			gererException(e, true);
		}
		Parameters.paramInit(params);
		//Verifications utiles pour le dev
		Log.writeT(Entry.INFO, "Informations systeme : ");
		Log.writeT(Entry.SYSTEM, "System.getProperty(\"os.name\") : " + System.getProperty("os.name"));
		Log.writeT(Entry.SYSTEM, "System.getProperty(\"os.version\") : " + System.getProperty("os.version"));
		Log.writeT(Entry.JAVA, "System.getProperty(\"java.vendor\") : " + System.getProperty("java.vendor"));
		Log.writeT(Entry.JAVA, "System.getProperty(\"java.version\") : " + System.getProperty("java.version"));
		Log.writeT(Entry.INFO, "Test de connexion...");
		try {
			new URL("http://regimys.jlppc.tk").openConnection().connect();//Oui, pour tester la connexion internet, je me connecte au site de Regimys. ET ALORS?
			Log.writeT(Entry.INFO, "Connexion a internet établie");
			connected = true;
		} catch (IOException e) {
			Log.writeT(Entry.WARNING, "Pas de connexion internet.");
		}
		
		gameThread = new Thread(new Runnable(){

			@Override
			public void run() {
				MainFrame.open();//Ouverture de la fenetre
				
			}
			
		});
		Log.writeT(Entry.INFO, "Lancement...");
		gameThread.start();//Start du thread du jeu
		
	}

	public static void exit() {//Je ne dirai meme pas a quoi elle sert, celle-la!
		
		System.exit(0);
	}

}
