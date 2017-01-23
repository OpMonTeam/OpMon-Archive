package jlppc.regimys.objects.items;
/**
 * Classe permettant de creer des pok�balls
 * @author Jlppc
 *
 */
public class I_Pokeball extends Item{
	/**
	 * Le bonus offert par la pokeball
	 */
    float tauxCapture;
    /**
     * 
     * @param nom - Le nom de la pokeball
     * @param tauxCapture - {@link #tauxCapture}
     */
    public I_Pokeball(String nom, float tauxCapture){
      super(nom, false, true, true, BagCat.OBJETS);
      this.tauxCapture = tauxCapture;
    }
    
    public float getTauxCapture(){
      return tauxCapture;
    }
    /**
     * Initialise les pokeballs.
     */
    public static void initPokeballs(){
      
    }
}
