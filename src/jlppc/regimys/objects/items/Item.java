package jlppc.regimys.objects.items;

import java.io.Serializable;
import java.util.Vector;

import jlppc.regimys.enums.Caractere.Stats;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
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
	 * Si c'est un item donnable a un pok�on
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
	
	protected int id;
	public String toString(){
		return nom;
	}
	/**
	 * Liste des cat�gories du sac
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
		id = itemList.size() - 1;
	}
	
	public int getID() {
		return id;
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
	 * Quand l'item est utilis� sur un pok�mon.
	 * @param given - Le pokemon sur lequel l'item est utilis�
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
		itemList.add(new I_Heal("Baie Oran", true, true, true, BagCat.BAIES, 10, Status.AUCUN, false));
		itemList.add(new I_Heal("Potion", true, true, true, BagCat.SOIN, 20, Status.AUCUN, false));
		itemList.add(new I_Heal("Super Potion", true, true, true, BagCat.SOIN, 50, Status.AUCUN, false));
		itemList.add(new I_Heal("Hyper Potion", true, true, true, BagCat.SOIN, 200, Status.AUCUN, false));
		itemList.add(new I_Heal("Potion Max", true, true, true, BagCat.SOIN, 999999, Status.AUCUN, false));
		itemList.add(new I_Heal("Guerison", true, true, true, BagCat.SOIN, 999999, Status.AUCUN, true));
		itemList.add(new I_Heal("Total Soin", true, true, true, BagCat.SOIN, 0, Status.AUCUN, true));
		itemList.add(new I_Heal("Antidote",true, true, true, BagCat.SOIN, 0, Status.POISON, false));
		itemList.add(new I_Heal("Anti-Para", true, true, true, BagCat.SOIN, 0, Status.PARALYSIE, false));
		itemList.add(new I_Heal("Anti-Gel", true, true, true, BagCat.SOIN, 0, Status.GEL, false));
		itemList.add(new I_Heal("Anti-Brulure", true, true, true, BagCat.SOIN, 0, Status.BRULURE, false));
		itemList.add(new I_Heal("R�veil", true, true, true, BagCat.SOIN, 0, Status.SOMMEIL, false));
		itemList.add(new I_Heal("Attaque+", Stats.ATK));
		itemList.add(new I_Heal("Defense+", Stats.DEF));
		itemList.add(new I_Heal("Attaque Sp�ciale+", Stats.ATKSPE));
		itemList.add(new I_Heal("D�fense Sp�ciale+", Stats.DEFSPE));
		itemList.add(new I_Heal("Vitesse+", Stats.VIT));
		itemList.add(new I_Heal("Chococoeur", true, true, true, BagCat.SOIN, 20, Status.AUCUN, false));
		itemList.add(new I_Heal("Eau fraiche", true, true, true, BagCat.SOIN, 50, Status.AUCUN, false));
		itemList.add(new I_Heal("Elixir", true, true, true, BagCat.SOIN, 10, true));
		itemList.add(new I_Heal("Galette Illumis", true, true, true, BagCat.SOIN, Status.AUCUN, true));
		itemList.add(new I_Heal("Huile", true, true, true, BagCat.SOIN, 10, false));
		itemList.add(new I_Heal("Huile max", true, true, true, BagCat.SOIN, 9999, false));
		itemList.add(new I_Heal("Jus de baies", true, true, true, BagCat.SOIN, 20));
		itemList.add(new I_Heal("Lait Meumeu", true, true, true, BagCat.SOIN, 100));
		itemList.add(new I_Heal("Lava Cookie", true, true, true, BagCat.SOIN, Status.AUCUN, true));
		itemList.add(new I_Heal("Limonade", true, true, true, BagCat.SOIN, 80));
		itemList.add(new I_Heal("Max Elixir", true, true, true, BagCat.SOIN, 9999, true));
		itemList.add(new I_Heal("Poudre Soin", true, true, true, BagCat.SOIN, Status.AUCUN, true));
		itemList.add(new I_Heal("Pourdr�nergie", true, true, true, BagCat.SOIN, 50));
		itemList.add(new I_Heal("Racin�nergie", true, true, true, BagCat.SOIN, 200));
		itemList.add(new I_Heal("Soda Cool", true, true, true, BagCat.SOIN, 60));
		itemList.add(new I_Heal("Vieux Gateau", true, true, true, BagCat.SOIN, Status.AUCUN, true));
		itemList.add(new I_Pokeball("Pokeball", 1f));
	    itemList.add(new I_Pokeball("Super Ball", 1.5f));
	    itemList.add(new I_Pokeball("Hyper Ball", 2f));
	    itemList.add(new I_Pokeball("Master Ball", 9999f));
		itemList.add(new Item("Pierre Feu", true, false,false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Plante", true, false, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Eau", true, false, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Lune", true, false, false, BagCat.OBJETS));
		//AJOUTER A LA SUITE MEME SI C'EST PAS DANS L'ORDRE!!!!!!!!!!!!!!!!!!!!!!!!:!!!!!!!:!!!!!!!!!!
		CT.initCTs();
		
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
	 * @throws NullPointerException si l'item n'est pas trouv�
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
