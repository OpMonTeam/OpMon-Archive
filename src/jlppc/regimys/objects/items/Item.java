package jlppc.regimys.objects.items;

import java.io.Serializable;
import java.util.Vector;

import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Pokemon;
/**
 * Classe décrivant un item.
 * @author Jlppc
 *
 */
public class Item implements Serializable{
	/**
	 * Le nom de l'item
	 */
	protected String nom;
	/**
	 * Si c'est un item utilisable
	 */
	protected boolean usable;
	/**
	 * Si c'est un item donnable a un pokéon
	 */
	protected boolean givable;
	/**
	 * La categorie dans le sac
	 */
	protected BagCat categorie;
	/**
	 * Si c'est un item utilisable en combat
	 */
	protected boolean usableInFight;
	
	public String toString(){
		return nom;
	}
	/**
	 * Liste des catégories du sac
	 * @author Jlppc
	 *
	 */
	public enum BagCat implements Serializable{
		SOIN, OBJETS, RARES, CTS, BAIES;
	}
	
	public BagCat getBagCat(){
		return categorie;
	}
	/**
	 * 
	 * @param nom - {@link #nom}
	 * @param usable - {@link #usable}
	 * @param usableInFight - {@link #usableInFight}
	 * @param giveable - {@link #givable}
	 * @param categorie - {@link #categorie}
	 */
	public Item(String nom, boolean usable, boolean usableInFight,boolean giveable, BagCat categorie) {
		this.nom = nom;
		this.usable = usable;
		this.usableInFight = usableInFight;
		this.givable = giveable;
		this.categorie = categorie;
	}
	
	
	
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((categorie == null) ? 0 : categorie.hashCode());
		result = prime * result + (givable ? 1231 : 1237);
		result = prime * result + ((nom == null) ? 0 : nom.hashCode());
		result = prime * result + (usable ? 1231 : 1237);
		result = prime * result + (usableInFight ? 1231 : 1237);
		return result;
	}
	
	public Object clone(){
		return new Item(nom, usable, usableInFight,givable, categorie);
	}




	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (!(obj instanceof Item)) {
			return false;
		}
		Item other = (Item) obj;
		if (categorie != other.categorie) {
			return false;
		}
		if (givable != other.givable) {
			return false;
		}
		if (nom == null) {
			if (other.nom != null) {
				return false;
			}
		} else if (!nom.equals(other.nom)) {
			return false;
		}
		if (usable != other.usable) {
			return false;
		}
		if (usableInFight != other.usableInFight) {
			return false;
		}
		return true;
	}



	/**
	 * Quand l'item est utilisé sur un pokémon.
	 * @param given - Le pokemon sur lequel l'item est utilisé
	 */
	public void used(Pokemon given){
		if(given.itemUsed(this)){
			Start.joueur.deleteItem(searchItem(this));
		}
	}
	/**
	 * La liste des items existants
	 */
	public static Vector<Item> itemList = new Vector<Item>();
	/**
	 * Initialisation de tous les items (mettez vos items mods ici)
	 */
	public static void init() {
		I_Heal.init();
		CT.initCTs();
		I_Pokeball.initPokeballs();
		itemList.add(new Item("Pierre Feu", true, false,false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Plante", true, false, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Eau", true, false, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Lune", true, false, false, BagCat.OBJETS));
		
	}
	/**
	 * 
	 * @return le nombre d'items au total
	 */
	public static int getItemNumber(){
		return itemList.size();
	}
	
	
	
	public static Item getItem(int id){
		return itemList.get(id);
	}
	
	public String getName(){
		return nom;
	}
	/**
	 * Retourne un item selon son nom
	 * @param name - Le nom de l'item
	 * @return L'item (si il existe)
	 * @throws NullPointerException si l'item n'est pas trouvé
	 */
	public static Item getItem(String name){
		try{
			for(Item tem : itemList){
				if(tem.getName().equals(name)){
					return tem;
				}
			}
		}catch(NullPointerException e){
			e.printStackTrace();
		}
		
		
		return null;
	}
	/**
	 * Cherche un item a partir de l'objet
	 * @param toSearch - L'item a chercher
	 * @return L'ID de l'item
	 */
	public static int searchItem(Item toSearch){
		try{
			int i = 0;
			for(Item tem : itemList){
				if(toSearch.equals(tem)){
					return i;
				}
				i++;
			}
			
		}catch(NullPointerException e){
			e.printStackTrace();
		}
		return -1;
		
	}

	public boolean isUsableInFight() {
		// TODO Auto-generated method stub
		return usableInFight;
	}
	
	
	
}
