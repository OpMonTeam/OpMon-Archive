package jlppc.regimys.objects.items;
/**
 * Classe permettant de creer des pokéballs
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
       itemList.add(new I_Pokeball("Pokeball", 1f));
       itemList.add(new I_Pokeball("Super Ball", 1.5f));
       itemList.add(new I_Pokeball("Hyper Ball", 2f));
       itemList.add(new I_Pokeball("Master Ball", 9999f));
    }
}
