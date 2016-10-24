package jlppc.regimys.launch;

import java.util.Random;
import java.util.Scanner;

import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
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
	/**
	 * Entrées (utilisé au début du programme)
	 */
	public static Scanner sc = new Scanner(System.in);
	/**
	 * Le main, permet de... demmarer le programme. Tu ne le savais pas, espèce d'incompetent? ;-)
	 * @param args
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws InstantiationException, IllegalAccessException {
		System.out.println("Choisissez un pokémon avec son numéro pokedex : ");
		int pkdx = sc.nextInt();
		boolean ok = false;
		while(!ok){
			if(pkdx < 0 || pkdx > 38){
				System.out.print("Numéro invalide, recommencez : ");
				pkdx = sc.nextInt();
			}else{
				ok = true;
			}
		}
		Class<Attaque>[] atksAtk = new Class[4];
		for(int i = 0; i < 4; i++){
			System.out.print("Choisissez l'attaque n" + (i+1) + " (Entrez le nom de l'attaque sans espaces avec des majuscules a chaque debut de mot, et sans accents) : ");
			String atk = sc.nextLine();
			try{
				atksAtk[i] = (Class<Attaque>) Class.forName(atk);
			}catch(ClassNotFoundException e){
				System.out.println("Attaque inexistante.");
				i--;
			}
		}
		System.out.println("Entrez le niveau du pokemon (1-100) (Valeur par défaut : 50) : ");
		int level = sc.nextInt();
		if(level < 1 || level > 100){
			level = 50;
		}
		
		//A continuer
		
	}

}
