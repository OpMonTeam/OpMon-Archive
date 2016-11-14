package jlppc.regimys.objects.items;

import jlppc.regimys.enums.Caractere.Stats;
import jlppc.regimys.objects.Pokemon.Status;

public class I_Heal extends Item {
	
	protected int pvHeal;
	protected Status healed;
	protected boolean healAll;
	protected Stats statAdd;
	protected boolean PPheal;
	protected int ppHeal;
	protected boolean allAttacksHeal;
	
	/**Constructeur Polyvalent*/
	public I_Heal(String nom, boolean usable, boolean usableInFight,boolean givable, BagCat categorie, int pvHeal, Status heal, boolean healAllStatus) {
		super(nom, usable, usableInFight,givable, categorie);
		this.pvHeal = pvHeal;
		this.healed = heal;
		healAll = healAllStatus;
		statAdd = Stats.RIEN;
	}
	/**Constructeur des PP*/
	public I_Heal(String nom, boolean usable, boolean usableInFight,boolean givable, BagCat categorie, int ppHeal, boolean allAttacksHeal) {
		super(nom, usable, usableInFight,givable, categorie);
		this.pvHeal = 0;
		this.healed = Status.AUCUN;
		healAll = false;
		statAdd = Stats.RIEN;
		PPheal = true;
		this.ppHeal = ppHeal;
		this.allAttacksHeal = allAttacksHeal;
	}
	
	/**
	 *Constructeur des items de pvHeal
	 */
	public I_Heal(String nom, boolean usable, boolean usableInFight,boolean givable, BagCat categorie, int pvHeal) {
		super(nom, usable, usableInFight,givable, categorie);
		this.pvHeal = pvHeal;
		this.healed = Status.AUCUN;
		healAll = false;
		statAdd = Stats.RIEN;
	}
	/**
	 * Constructeur des status Heal
	 */
	public I_Heal(String nom, boolean usable, boolean usableInFight,boolean givable, BagCat categorie, Status heal, boolean healAllStatus) {
		super(nom, usable, usableInFight,givable, categorie);
		this.pvHeal = 0;
		this.healed = heal;
		healAll = healAllStatus;
		statAdd = Stats.RIEN;
	}
	/**
	*Constructeur des Stat+
	*/
	public I_Heal(String nom, Stats statAdd){
		super(nom, true, true, true, BagCat.SOIN);
		this.pvHeal = 0;
		this.healed = Status.AUCUN;
		healAll = false;
		this.statAdd = statAdd;
	}
	
	public Stats getStatAdd(){
		return statAdd;
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
		itemList.add(new I_Heal("Anti-Gel", true, true, true, BagCat.SOIN, 0, Status.GEL, false));
		itemList.add(new I_Heal("Anti-Brulure", true, true, true, BagCat.SOIN, 0, Status.BRULURE, false));
		itemList.add(new I_Heal("Réveil", true, true, true, BagCat.SOIN, 0, Status.SOMMEIL, false));
		itemList.add(new I_Heal("Attaque+", Stats.ATK));
		itemList.add(new I_Heal("Defense+", Stats.DEF));
		itemList.add(new I_Heal("Attaque Spéciale+", Stats.ATKSPE));
		itemList.add(new I_Heal("Défense Spéciale+", Stats.DEFSPE));
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
		itemList.add(new I_Heal("Pourdrénergie", true, true, true, BagCat.SOIN, 50));
		itemList.add(new I_Heal("Racinénergie", true, true, true, BagCat.SOIN, 200));
		itemList.add(new I_Heal("Soda Cool", true, true, true, BagCat.SOIN, 60));
		itemList.add(new I_Heal("Vieux Gateau", true, true, true, BagCat.SOIN, Status.AUCUN, true));
		//A suivre
	}
}
