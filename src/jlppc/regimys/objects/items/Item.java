package jlppc.regimys.objects.items;

import java.util.Vector;

import jlppc.regimys.objects.Pokemon;

public class Item {
	protected String nom;
	protected boolean usable;
	protected boolean givable;
	protected BagCat categorie;
	protected boolean usableInFight;
	
	
	public enum BagCat{
		SOIN, OBJETS, RARES, CTS, BAIES;
	}
	
	public BagCat getBagCat(){
		return categorie;
	}
	
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




	public void used(Pokemon given){
		if(given.itemUsed(this)){
			//Il faudra supprimer l'item ici
		}
	}
	
	public static Vector<Item> itemList = new Vector<Item>();

	public static void init() {
		I_Heal.init();
		CT.initCTs();
		itemList.add(new Item("Pierre Feu", true, false,false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Plante", true, false, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Eau", true, false, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Lune", true, false, false, BagCat.OBJETS));
		
	}
	
	public static int getItemNumber(){
		return itemList.size();
	}
	
	
	
	public static Item getItem(int id){
		return itemList.get(id);
	}
	
	public String getName(){
		return nom;
	}
	
	public static Item getItem(String name){
		for(Item tem : itemList){
			if(tem.getName().equals(name)){
				return tem;
			}
		}
		
		return null;
	}
	
	public static int searchItem(Item toSearch){
		int i = 0;
		for(Item tem : itemList){
			if(toSearch.equals(tem)){
				return i;
			}
			i++;
		}
		return -1;
	}

	public boolean isUsableInFight() {
		// TODO Auto-generated method stub
		return usableInFight;
	}
	
	
	
}
