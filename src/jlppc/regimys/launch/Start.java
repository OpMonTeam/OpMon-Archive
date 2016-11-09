package jlppc.regimys.launch;

import java.util.Random;
import java.util.Scanner;

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
import jlppc.regimys.playercore.Player;
import jlppc.regimys.tempgui.ChoosePoke;
import jlppc.utils.FormattedString;
import jlppc.utils.Log;
/**
 * Demmare le programme.
 * @author Jlppc
 *
 */
public class Start {
	static{
		Initializer.init();
	}
	
	public static float version = 0.05f;
	
	public static char commits = ' ';
	

	
	public static int preNbre = 0;
	
	public static boolean pre = (preNbre != 0);
	
	public static int sousVers = 2;
	
	public static boolean sousVersIs = sousVers == 0;
	
	public static String versionS = "" + version  + (sousVersIs ? "." + sousVers : "") + (pre ? (" pre " + preNbre) : "") + commits;//Actuel : 0.04 
	
	//Utilitaires pratiques
	/**
	 * Aléatoire
	 */
	public static Random rand = new Random();
	
	public static Player joueur;
	/**
	 * Entrées (utilisé au début du programme)
	 */
	public static Scanner sc = new Scanner(System.in);
	static Main window = new Main();;
	/**
	 * Le main, permet de... demmarer le programme. Tu ne le savais pas? ;-)
	 * @param args
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 */
	public static void main(String[] args) throws InstantiationException, IllegalAccessException {
		
		try{
			if(args[0].startsWith("--")){
				if(args[0].equals("--creator")){
					try{
						if(args[1].equals("pokemon")){
							window.frmCrateurDePokmon.setVisible(true);
							
						}else{
							System.out.println("Un des mots suivants doivent apparaitre après --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
							System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
						}
					}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
						System.out.println("Un des mots suivants doivent apparaitre après --creator :"  + Log.saut + "<html><ul><li>pokemon</li></ul></html>");
						System.exit(2);//Les signaux d'exit du programme : 0 : Tout va bien. 1 : Erreur dans le programme 2 : Erreur dans les arguments.
					}
				}else if(args[0].equals("--version")){
					System.out.println("Pokémon Regimys version " + versionS);
				}
				else{
					System.out.println("Page d'aide des arguments de Pokemon Regimys." + Log.saut + "--creator : Permet d'affcher une fenetre de creation d'un objet (Voir --creator aide)" + Log.saut + "--help : Affiche cette page");
				}
				
			}else{
				System.out.println("L'ouverture de fichiers de sauvegarde par ce biais n'est actuellement pas disponible. Lancement du jeu...");
			}
		}catch(ArrayIndexOutOfBoundsException | NullPointerException e){

			String playername;
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
			int combatsNumber = 0;
			
			while(true){
				combatsNumber++;
				System.out.println("Combat n°" + combatsNumber);
				Espece eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
				while(eAdv == null){
					eAdv = Initializer.listePoke[rand.nextInt(Initializer.listePoke.length)];
				}
				joueur.healPoke();
				Pokemon adv = new Pokemon(eAdv, joueur.getPoke(0).getLevel() - rand.nextInt(3), new Attaque[]{Charge.class.newInstance(), Rugissement.class.newInstance(), Soin.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
				FormattedString.outPrintln("%o niveau %o vs %o niveau %o", joueur.getPoke(0).getSurnom(),joueur.getPoke(0).getLevel(), adv.getSurnom(), adv.getLevel());
				Fight.fight(joueur.getPoke(0), adv);
			}
			
		}
		
	}

}
