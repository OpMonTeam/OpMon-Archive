package jlppc.regimys.launch;

import java.util.Random;
import java.util.Scanner;

import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.playercore.Player;
/**
 * Demmare le programme.
 * @author Jlppc
 *
 */
public class Start {
	
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
		System.out.println("Programme actuellement non fonctionnel.");
		
		//A continuer
		
	}

}
