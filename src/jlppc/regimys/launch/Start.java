package jlppc.regimys.launch;

import java.util.Random;
import java.util.Scanner;

import jlppc.regimys.enums.Caractere;
import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.Fight;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.attacks.Berceuse;
import jlppc.regimys.objects.attacks.BombOeuf;
import jlppc.regimys.objects.attacks.CageEclair;
import jlppc.regimys.objects.attacks.Charge;
import jlppc.regimys.objects.attacks.CrocDeMort;
import jlppc.regimys.objects.attacks.Explosion;
import jlppc.regimys.objects.attacks.Flammeche;
import jlppc.regimys.objects.attacks.FouetLianes;
import jlppc.regimys.objects.attacks.Furie;
import jlppc.regimys.objects.attacks.Griffe;
import jlppc.regimys.objects.attacks.OndeBoreale;
import jlppc.regimys.objects.attacks.PiedVoltige;
import jlppc.regimys.objects.attacks.Rugissement;
import jlppc.regimys.objects.attacks.Soin;
import jlppc.regimys.objects.attacks.Telekinesie;
import jlppc.regimys.objects.attacks.Toxik;
import jlppc.regimys.objects.attacks.Tunnel;
import jlppc.regimys.objects.attacks.Ultimawashi;
import jlppc.regimys.objects.attacks.Ultralaser;
import jlppc.regimys.objects.attacks.Vampigraine;
import jlppc.regimys.objects.attacks.ViveAttaque;
import jlppc.regimys.objects.attacks.Vol;
import jlppc.regimys.objects.attacks.Yoga;
import jlppc.regimys.util.text.StringKey;
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
	public static void main(String[] args) throws InstantiationException, IllegalAccessException {
		/*System.out.println("Combat pokemon test");
		
		StringKey.initialisateKeys();
		
		Espece esp1 = new Espece(50, 120, 50, 120, 50,990, "Defia", Type.POISON, Type.NORMAL);
		Espece esp2 = new Espece(75, 25, 75, 25, 25, 75, "Irregu", Type.PLANTE, Type.COMBAT);
		Pokemon pkm1 = new Pokemon(esp1, 50, new Attaque[]{Vampigraine.class.newInstance(), Toxik.class.newInstance(), Vol.class.newInstance(), Soin.class.newInstance()},Caractere.DOCILE, null);
		Pokemon pkm2 = new Pokemon(esp2, 60, new Attaque[]{PiedVoltige.class.newInstance(), Berceuse.class.newInstance(), Ultralaser.class.newInstance(), Yoga.class.newInstance()}, Caractere.BIZARRE, null);
		
		
		
		Espece bulbizarre = new Espece(49, 49, 65, 65, 45, 45, "Bulbizarre", Type.PLANTE, Type.AUCUN);
		Espece salameche = new Espece(52, 43, 60, 50, 65, 39,"Salameche", Type.FEU, Type.AUCUN);
		Fight.fight(pkm1, pkm2);*/
	}

}
