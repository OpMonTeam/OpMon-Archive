package jlppc.regimys.launch;

import java.util.Random;
import java.util.Scanner;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Type;
/**
 * Demmare le programme.
 * @author Jlppc
 *
 */
public class Start {
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
	 */
	public static void main(String[] args) {
		System.out.println("Combat pokemon test");
		
		
		Espece bulbizarre = new Espece(49, 49, 65, 65, 45, 45, "Bulbizarre", Type.PLANTE, Type.AUCUN);
		Espece salameche = new Espece(52, 43, 60, 50, 65, 39,"Salameche", Type.FEU, Type.AUCUN);
		//Fight.fight(new Pokemon("Herbefolle", bulbizarre, 7, new Attaque[]{charge, rugissement, fouetLianes}, Caractere.BIZARRE), new Pokemon(salameche, 7, new Attaque[]{griffe, rugissement2, flammeche, toxic}, Caractere.DOCILE));
	}

}
