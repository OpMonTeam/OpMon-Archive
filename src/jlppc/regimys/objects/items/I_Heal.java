package jlppc.regimys.objects.items;

import jlppc.regimys.enums.Caractere.Stats;
import jlppc.regimys.objects.Pokemon.Status;
/**
 * Construit les items de soin
 * @author Jlppc
 *
 */
public class I_Heal extends Item {
	/**
	 * Les PV soign�s
	 */
	protected int pvHeal;
	/**
	 * Le status soign�
	 */
	protected Status healed;
	/**
	 * Si l'item soigne tous les status
	 */
	protected boolean healAll;
	/**
	 * Si l'item ajoute une stat (stats+)
	 */
	protected Stats statAdd;
	/**
	 * Si l'item soigne les PP
	 */
	protected boolean PPheal;
	/**
	 * Le nombre de PP soign�s
	 */
	protected int ppHeal;
	/**
	 * Si les PP sont soign�s dans toutes les attaques.
	 */
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
	/**
	 * Intitialise les Items de soin
	 */
	public static void init(){
		
		//A suivre
	}
}
