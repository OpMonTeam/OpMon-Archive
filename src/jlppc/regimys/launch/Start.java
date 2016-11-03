package jlppc.regimys.launch;

import java.util.Random;
import java.util.Scanner;

import jlppc.regimys.enums.Caractere;
import jlppc.regimys.fight.Fight;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.attacks.Berceuse;
import jlppc.regimys.objects.attacks.Charge;
import jlppc.regimys.objects.attacks.Rugissement;
import jlppc.regimys.objects.attacks.Soin;
import jlppc.regimys.objects.attacks.Triplattaque;
import jlppc.regimys.playercore.Player;
import jlppc.regimys.tempgui.ChoosePoke;
import jlppc.utils.FormattedString;
/**
 * Demmare le programme.
 * @author Jlppc
 *
 */
public class Start {
	static{
		Initializer.init();
	}
	
	public static float version = 0.04f;
	
	public static char commits = ' ';
	

	
	public static int preNbre = 0;
	
	public static boolean pre = (preNbre != 0);
	
	public static String versionS = "" + version + (pre ? (" pre " + preNbre) : "") + commits;//Actuel : 0.04 
	
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
	/**
	 * Le main, permet de... demmarer le programme. Tu ne le savais pas? ;-)
	 * @param args
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws InstantiationException, IllegalAccessException {
		
		String playername;
		System.out.println("Bienvenue dans le monde non achevé des pokémon! Quel est ton nom? : ");
		playername = sc.nextLine();
		joueur = new Player(playername);
		ChoosePoke cp = new ChoosePoke();
		System.out.println(cp.getEspChoosen());
		Espece esp = Initializer.listePoke[cp.getEspChoosen()];
		System.out.println("Veux-tu donner un surnom a ton Pokémon(true (oui)/false(non)? : ");
		boolean isS = sc.nextBoolean();
		String surnom = esp.getSurnom();
		if(isS){
			System.out.println("Surnom : ");
			surnom = sc.nextLine();
		}
		Pokemon first = new Pokemon(surnom, esp, 5, new Attaque[]{Charge.class.newInstance(), Rugissement.class.newInstance(), Berceuse.class.newInstance(), Triplattaque.class.newInstance()}, Caractere.HARDI, null);
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
			FormattedString.outPrintln("%o vs %o", joueur.getPoke(0).getSurnom(), adv.getSurnom());
			Fight.fight(joueur.getPoke(0), adv);
		}
		
	}

}
