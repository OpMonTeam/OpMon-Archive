package jlppc.regimys.objects.items;

import jlppc.regimys.objects.Pokemon.Status;

public class I_Heal extends Item {
	
	protected int pvHeal;
	protected Status healed;
	protected boolean healAll;
	
	public I_Heal(String nom, boolean usable, boolean usableInFight,boolean givable, BagCat categorie, int pvHeal, Status heal, boolean healAllStatus) {
		super(nom, usable, usableInFight,givable, categorie);
		this.pvHeal = pvHeal;
		this.healed = heal;
		healAll = healAllStatus;
	}
	
	public Status getStatusHeald(){
		return healed;
	}
	
	public int getPvHeal(){
		return pvHeal;
	}
	
	public boolean isHealAll(){
		return healAll;
	}
	
	public Object clone(){
		return new I_Heal(nom, usable, usableInFight, givable, categorie, pvHeal, healed, healAll);
	}
	
	public static void init(){
		itemList.add(new I_Heal("Baie Oran", true, true, true, BagCat.BAIES, 10, Status.AUCUN, false));
		itemList.add(new I_Heal("Potion", true, true, true, BagCat.SOIN, 20, Status.AUCUN, false));
		itemList.add(new I_Heal("Super Potion", true, true, true, BagCat.SOIN, 50, Status.AUCUN, false));
		itemList.add(new I_Heal("Hyper Potion", true, true, true, BagCat.SOIN, 200, Status.AUCUN, false));
		itemList.add(new I_Heal("Potion Max", true, true, true, BagCat.SOIN, 999999, Status.AUCUN, false));
		itemList.add(new I_Heal("Guerison", true, true, true, BagCat.SOIN, 999999, Status.AUCUN, true));
		itemList.add(new I_Heal("Total Soin", true, true, true, BagCat.SOIN, 0, Status.AUCUN, true));
		itemList.add(new I_Heal("Antidote",true, true, true, BagCat.SOIN, 0, Status.POISON, false));
		itemList.add(new I_Heal("Anti-Para", true, true, true, BagCat.SOIN, 0, Status.PARALYSIE, false));
		//A suivre
	}
}
