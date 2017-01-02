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
	public static String[] trainers = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "NikolaÃƒÂ¯", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal"};
	/**La version du jeu*/
	public static float version = 0.07f;
	/**La lettre du jeu (Va surement Ãªtre supprimÃ©e, puisque jamais mise a jour)*/
	public static char commits = ' ';
	
	public static Thread gameThread;

	/**Le nombre aprÃ¨s pre , dans le cas d'un depassement de prÃ©visions*/
	public static int preNbre = 0;
	/**Verifie si il y a un pre, pour l'inclure dans versionS*/
	public static boolean pre = (preNbre != 0);
	/**Les sous versions (x.x.sousVers)*/
	public static int sousVers = 0;
	/**Verifie si il y a une sous version*/
	public static boolean sousVersIs = (sousVers != 0);
	/**Chaine de caractÃ¨re indiquant la version du jeu*/
	public static String versionS = "Alpha " + version  + (sousVersIs ? "." + sousVers : "") + (pre ? (" pre " + preNbre) : "") + commits;
	
	//Utilitaires pratiques
	/**
	 * Le gÃ©nÃ©rateur d'alÃ©atoire du programme. Au lieu de creer plein d'objets Random, je n'en crÃ©e que un, utilisÃ© dans tout le programme.
	 */
	public static Random rand = new Random();
	/**La variable contenant le joueur*/
	public static Player joueur;
	/**
	 * EntrÃ©es (utilisÃ© au dÃ©but du programme)
	 */
	public static Scanner sc = new Scanner(System.in);
	
	public static Main window = new Main();
	
	public static String sep = new String(System.getProperty("os.name").contains("win") ? "\\" : "/");

	/**
	 * Le prochain main du launcher
	 * @param saves - Les fichiers de sauvegarde (0 : Les paramètres, 1 : Le joueur)
	 */
	public static void main(File[] saves) throws Throwable{
		String playername;
		Parameters.paramInit(saves[0]);
		if((Parameters.checkParam("playerexists") ? Parameters.getParam("playerexists").getValue().equals("true") : false)){
			joueur = Player.getPlayer(saves[1]);
		}else{
			System.out.println("Bienvenue dans le monde non achevÃ© des pokÃ©mon! Quel est ton nom? : ");
			playername = sc.nextLine();
			joueur = new Player(playername);
			System.out.println("Une boite de dialogue s'est ouverte pour choisir ton PokÃ©mon.");
			ChoosePoke cp = new ChoosePoke();
			Espece esp = Initializer.listePoke[cp.getEspChoosen()];
			System.out.println("PokÃ©mon choisi : " + esp.getSurnom());
			System.out.println("Veux-tu donner un surnom a ton PokÃ©mon ? (Tapez true pour Oui et false pour Non ) : ");
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
			Parameters.modifyOrAddParam("playerexists", "true", "DÃ©finit si le joueur a deja Ã©tÃ© crÃ©e ou non.");
			
		}
		int combatsNumber = 0;
		while(true){
			System.out.println("Equipe : " + joueur.getEquipe());
			Parameters.updateFile();
			combatsNumber++;
			System.out.println("Combat nÂ°" + combatsNumber);
			
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
		try{
			try{
				if(args[0].startsWith("--")){
					if(args[0].equals("--creator")){
						try{
							if(args[1].equals("pokemon")){
								window.frmCrateurDePokmon.setVisible(true);
								
							}else{
								System.out.println("Un des mots suivants doivent apparaitre aprÃƒÂ¨s --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
								System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
							}
						}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
							System.out.println("Un des mots suivants doivent apparaitre aprÃƒÂ¨s --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
							System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. -99999 : Erreur dans l'initialiseur du programme -1 : Erreur fatale. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
						}
					}else if(args[0].equals("--version")){
						System.out.println("PokÃ©mon Regimys version " + versionS);
					}else if(args[0].equals("--guitest")){
						System.out.println("Test du gui de Pokemon Regimys");
						guiMain();
					}else if(args[0].equals("--launcher")){
						try{
							main(new File[]{new File(args[1]), new File(args[2])});
						}catch(Throwable e){
							JOptionPane.showMessageDialog(null, "Désolé, mais cette option ne peut être utilisée que par le launcher (a moins que vous ne sachiez vous en servir)", "Erreur", JOptionPane.ERROR_MESSAGE);
							System.exit(2);
						}
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
					System.out.println("Bienvenue dans le monde non achevÃ© des pokÃ©mon! Quel est ton nom? : ");
					playername = sc.nextLine();
					joueur = new Player(playername);
					System.out.println("Une boite de dialogue s'est ouverte pour choisir ton PokÃ©mon.");
					ChoosePoke cp = new ChoosePoke();
					Espece esp = Initializer.listePoke[cp.getEspChoosen()];
					System.out.println("PokÃ©mon choisi : " + esp.getSurnom());
					System.out.println("Veux-tu donner un surnom a ton PokÃ©mon ? (Tapez true pour Oui et false pour Non ) : ");
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
					Parameters.modifyOrAddParam("playerexists", "true", "DÃ©finit si le joueur a deja Ã©tÃ© crÃ©e ou non.");
					
				}
				int combatsNumber = 0;
				while(true){
					System.out.println("Equipe : " + joueur.getEquipe());
					Parameters.updateFile();
					combatsNumber++;
					System.out.println("Combat n�" + combatsNumber);
					
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
	
	public static void gererException(Exception e, boolean fatal){
		Log.writeT(fatal ? Entry.FATAL : Entry.EXCEPTION, "Exception : " + e.getClass().getCanonicalName());
		e.printStackTrace();
		
		if(fatal){
			Log.writeT(Entry.FATAL, "Echec de l'execution du programme. Merci de prevenir les developpeurs.");
			
			JOptionPane.showMessageDialog(null, "<HTML>Une erreur fatale s'est d�clanch�e dans le programme.<br/> Merci de prevenir les developpeur en leur joignant les fichiers log.txt et errLog.txt. <br/>Merci d'avance, c'est grace a votre intervention que le jeu s'am�liorera.</HTML>", "Erreur fatale", JOptionPane.ERROR_MESSAGE);
			Log.close();
			System.exit(1);
		}
	}

	private static void guiMain() {
		File errLog = new File("errLog.txt");
		try {
			Log.start();
			errLog.createNewFile();
			System.setErr(new PrintStream(errLog));
		} catch (IOException e) {
			gererException(e, true);
		}
		Log.writeT(Entry.INFO, "Informations systeme : ");
		Log.writeT(Entry.SYSTEM, "System.getProperty(\"os.name\") : " + System.getProperty("os.name"));
		Log.writeT(Entry.SYSTEM, "System.getProperty(\"os.version\") : " + System.getProperty("os.version"));
		Log.writeT(Entry.JAVA, "System.getProperty(\"java.vendor\") : " + System.getProperty("java.vendor"));
		Log.writeT(Entry.JAVA, "System.getProperty(\"java.version\") : " + System.getProperty("java.version"));
		Log.writeT(Entry.INFO, "Test de connexion...");
		try {
			new URL("http://www.google.com").openConnection();
			Log.writeT(Entry.INFO, "Connexion a internet �tablie");
		} catch (IOException e) {
			Log.writeT(Entry.WARNING, "Pas de connexion internet.");
		}
		
		gameThread = new Thread(new Runnable(){

			@Override
			public void run() {
				MainFrame.open();
				
			}
			
		});
		Log.writeT(Entry.INFO, "Lancement...");
		gameThread.start();
		
	}

	public static void exit() {
		
		System.exit(0);
	}

}
