package jlppc.regimys.util.math;

import jlppc.utils.Static;
/**
 * Contient des utilitaire pour faire des maths plus facilement (En fait pour l'instant il n'y a que des racines mais bon...)
 * @author Jlppc
 *
 */
@Static
public class Maths{
	/**
	 * Fait une racine
	 * @param dessous - Le nombre sous le _/
	 * @param exposant - L'exposant
	 * @return une valeur float de cette racine.
	 */
  public static float racine(float dessous, float exposant){
    return (float) Math.pow(dessous, 1/exposant);
  }
  	/**
	 * Fait une racine
	 * @param dessous - Le nombre sous le _/
	 * @param exposant - L'exposant
	 * @return une valeur double de cette racine.
	 */
  public static double racine(double dessous, double exposant){
    return Math.pow(dessous, 1/exposant);
  }
}
