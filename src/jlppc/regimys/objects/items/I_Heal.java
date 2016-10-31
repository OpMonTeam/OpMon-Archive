package jlppc.regimys.objects.items;

import jlppc.regimys.objects.Pokemon.Status;

public class I_Heal extends Item {
	
	protected int pvHeal;
	protected Status healed;
	protected boolean healAll;
	
	public I_Heal(String nom, boolean usable, boolean givable, BagCat categorie, int pvHeal, Status heal, boolean healAllStatus) {
		super(nom, usable, givable, categorie);
		this.pvHeal = pvHeal;
		this.healed = heal;
		healAll = healAllStatus;
	}
	
	public Object clone(){
		return new I_Heal(nom, usable, givable, categorie, pvHeal, healed, healAll);
	}
	
	public static void init(){
		
	}
}
