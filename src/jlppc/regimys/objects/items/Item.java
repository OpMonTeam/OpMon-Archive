package jlppc.regimys.objects.items;

import java.util.Vector;

import jlppc.regimys.objects.Pokemon;

public class Item {
	protected String nom;
	protected boolean usable;
	protected boolean givable;
	protected BagCat categorie;
	
	
	public enum BagCat{
		SOIN, OBJETS, RARES, CTS, BAIES;
	}
	
	public Item(String nom, boolean usable, boolean giveable, BagCat categorie) {
		this.nom = nom;
		this.usable = usable;
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
		return result;
	}
	
	public Object clone(){
		return new Item(nom, usable, givable, categorie);
	}




	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Item other = (Item) obj;
		if (categorie != other.categorie)
			return false;
		if (givable != other.givable)
			return false;
		if (nom == null) {
			if (other.nom != null)
				return false;
		} else if (!nom.equals(other.nom))
			return false;
		if (usable != other.usable)
			return false;
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
		itemList.add(new Item("Pierre Feu", true, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Plante", true, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Eau", true, false, BagCat.OBJETS));
		itemList.add(new Item("Pierre Lune", true, false, BagCat.OBJETS));
		
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
	
	
	
}
