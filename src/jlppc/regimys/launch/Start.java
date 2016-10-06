package jlppc.regimys.launch;

import java.util.Random;
import java.util.Scanner;

import jlppc.regimys.enums.Caractere;
import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.Fight;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.attacks.CageEclair;
import jlppc.regimys.objects.attacks.Charge;
import jlppc.regimys.objects.attacks.CrocDeMort;
import jlppc.regimys.objects.attacks.Flammeche;
import jlppc.regimys.objects.attacks.FouetLianes;
import jlppc.regimys.objects.attacks.Griffe;
import jlppc.regimys.objects.attacks.OndeBoreale;
import jlppc.regimys.objects.attacks.Rugissement;
import jlppc.regimys.objects.attacks.ViveAttaque;
/**
 * Demmare le programme.
 * @author Jlppc
 *
 */
public class Start {
	
	public static float version = 0.03;
	
	public static char commits = 'k';
	

	
	public static int preNbre = 0;
	
	public static boolean pre = (preNbre != 0);
	
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
	public static void main(String[] args) throws InstantiationException, IllegalAccessException {
		System.out.println("Combat pokemon test");
		
		
		Espece bulbizarre = new Espece(49, 49, 65, 65, 45, 45, "Bulbizarre", Type.PLANTE, Type.AUCUN);
		Espece salameche = new Espece(52, 43, 60, 50, 65, 39,"Salameche", Type.FEU, Type.AUCUN);
		Fight.fight(new Pokemon("Herbefolle", bulbizarre, 7, new Attaque[]{Charge.class.newInstance(), CageEclair.class.newInstance(), FouetLianes.class.newInstance(), ViveAttaque.class.newInstance()}, Caractere.BIZARRE, null), new Pokemon(salameche, 7, new Attaque[]{Griffe.class.newInstance(), CrocDeMort.class.newInstance(), Flammeche.class.newInstance()}, Caractere.DOCILE, null));
	}

}
