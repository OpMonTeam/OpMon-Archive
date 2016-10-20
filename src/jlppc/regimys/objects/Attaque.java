package jlppc.regimys.objects;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.NoPP;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.utils.HashArray;
import jlppc.utils.WIP;
/**
 * Contient toutes les donn�es permettant de creer une attaque.
 * @author Jlppc
 *
 */
public abstract class Attaque extends Typedef{
	/**
	 * Le nom de l'attaque
	 */
	protected String nom;
	/**
	 * La puissance de l'attaque
	 */
	protected int puissance;
	protected int priorite;
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + chanceDeCoups;
		result = prime * result + ((nom == null) ? 0 : nom.hashCode());
		result = prime * result + precision;
		result = prime * result + puissance;
		result = prime * result + (rateJamais ? 1231 : 1237);
		result = prime * result + (special ? 1231 : 1237);
		result = prime * result + (status ? 1231 : 1237);
		result = prime * result + ((type == null) ? 0 : type.hashCode());
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (!(obj instanceof Attaque)) {
			return false;
		}
		Attaque other = (Attaque) obj;
		if (chanceDeCoups != other.chanceDeCoups) {
			return false;
		}
		if (nom == null) {
			if (other.nom != null) {
				return false;
			}
		} else if (!nom.equals(other.nom)) {
			return false;
		}
		if (precision != other.precision) {
			return false;
		}
		if (puissance != other.puissance) {
			return false;
		}
		if (rateJamais != other.rateJamais) {
			return false;
		}
		if (special != other.special) {
			return false;
		}
		if (status != other.status) {
			return false;
		}
		if (type != other.type) {
			return false;
		}
		return true;
	}
	
	//Cette methode sera completée dans le futur
	@WIP
	public HashArray[] listVar(){
		HashArray[] toReturn = {
				new HashArray("nom", String.class, NULL),
				new HashArray("puissance", Integer.class,NULL),
				new HashArray("priorite", Integer.class, NULL),
				new HashArray("precision", Short.class, NULL),
				new HashArray("type", Type.class, NULL),
				new HashArray("special", Boolean.class, NULL),
				new HashArray("status", Boolean.class, NULL),
				new HashArray("part", Integer.class, part),
				new HashArray("pp", Integer.class, pp),
				new HashArray("ppMax", Integer.class, NULL),
				new HashArray("chanceDeCoups", Integer.class, NULL),
				new HashArray("rateJamais", Boolean.class, NULL),
				new HashArray("pvPerdus", Integer.class, NULL)
		};
		return toReturn;
	}
	/**
	 * La pr�cision de l'attaque (pourquoi short? Je sais pas.)
	 */
	protected short precision;
	/**
	 * Le type de l'attaque.
	 */
	protected Type type;
	/**
	 * Si c'est une attaque de status (je crois que c'est inutile...)
	 */
	public static final int STATUS_ATK = 0;
	/**
	 * Si c'est une attaque de d�gats (Je crois AUSSI que c'est inutile...)	 
	*/
	public static final int DEGATS_ATK = 1;
	/**
	 * Si l'attaque est physique, cette variable est false. Si elle est sp�ciale, alors cette variable est... TRUE! BRAVO! Vous avez bien devin�!
	 */
	protected boolean special;
	/**
	 * Si l'attaque est une attaque de status ou pas (Voila pourquoi les autres sont useless {@link #STATUS_ATK} et {@link #DEGATS_ATK}
	 */
	protected boolean status;
	/**
	 * La partie de l'attaque (utilis� pour les attaques en 2 tours)
	 */
	protected int part = 0;
	/**
	 * Les PP actuels de l'attaque.
	 */
	protected int pp;
	/**
	 * Les PP max de l'attaque.
	 */
	protected int ppMax;
	/**
	 * La chance de coups... CRITIQUES. C'etait difficile a deviner!
	 */
	protected int chanceDeCoups = 16;
	/**
	 * Si l'attaque ne... rate jamais. Merci captain obvious!
	 */
	protected boolean rateJamais = false;
	/**
	 * Compte les PV perdus. Est en variable de classe pour pouvoir �tre acced�e par effetAvant et effetApr�s. (Vous en avez de la chance les moddeurs!)
	 */
	protected int pvPerdus;
	/**
	 * Un effet qui se passe avant les d�gats.
	 * @param atk - Le pokemon attaquant
	 * @param def - Le pokemon d�fenseur
	 * @throws EndOfTurn Si le tour doit se terminer avant d'avoir effectu� les degats.
	 * @throws SameAtkPartTwo 
	 */
	protected abstract void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo;
	/**
	 * Un effet qui se passe apr�s l'attaque.
	 * @param atk - Le pokemon attaquant
	 * @param def - Le pokemon defenseur
	 * @throws SameAtkPartTwo 
	 */
	protected abstract void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo;
	/**
	 * L'action d'attaquer
	 * @param atk - Le pokemon a qui appartient l'attaque
	 * @param def - La cible
	 * @throws SameAtkPartTwo - Si le combat doit faire la m�me attaque a la partie deux (Attaques en deux tours)
	 * @throws NoPP - Si l'attaque n'a plus de PP.
	 */
	public final void attack(Pokemon atk, Pokemon def) throws SameAtkPartTwo{
		pp--;
		try{
			System.out.println(atk.getSurnom() + " utilise " + nom);
			if((Start.rand.nextDouble() * 100) > (precision * (atk.getStatPRE() / def.getStatESQ())) && rateJamais == false){
				System.out.println("Mais rate son attaque!");
				siEchoue(atk, def);
				return;
			}
			if(Type.calcEfficacite(type, def.getType1(), def.getType2()) == 0 && (rateJamais == false || status == false)){
				System.out.println("Mais cela n'a aucun effet!");
				siEchoue(atk, def);
				return;
			}
			effetAvant(atk, def);
			if(!status){
				pvPerdus = (int) (((atk.getLevel() * 0.4 + 2) * (special ? atk.getStatATKSPE() : atk.getStatATK()) * puissance) / ((special ? def.getStatDEFSPE() : def.getStatDEF()) * 50) + 2);
				if(type == atk.getType1() || type == atk.getType2()){
					pvPerdus = Math.round(pvPerdus * 1.5f);
				}else{
					pvPerdus = pvPerdus * 1;
				}
				float efficacite = (Type.calcEfficacite(type, def.getType1(), def.getType2()));
				if(efficacite == 0f){
					System.out.println("Mais cela �choue!");
				}else if(efficacite == 0.25f || efficacite == 0.5f){
					System.out.println("Ce n'est pas tr�s efficace...");
				}else if(efficacite == 2f){
					System.out.println("C'est tr�s efficace!");
				}else if(efficacite == 4f){
					System.out.println("C'est super efficace!");
				}
				pvPerdus = (int) (pvPerdus * efficacite);
				if(Start.rand.nextInt(chanceDeCoups) == 0){
					pvPerdus = (int) (pvPerdus * 1.5f);
					System.out.println("Coup critique!");
				}
				pvPerdus = (int) (pvPerdus * (Start.rand.nextInt(100 - 85 + 1) + 85) / 100);
				def.attacked(pvPerdus);
				System.out.println(def.getSurnom() + " perd " + pvPerdus + " pv. Il lui reste " + def.getPV() + " pv.");
			}
			effetApres(atk, def);
			
		}catch(SameAtkPartTwo e){
			throw e;
		}catch(EndOfTurn e){
			
		}
	}
	
	
	//Oh! Des getteurs! Y'en a beaucoup. Je crois pas qu'il soit n�cessaire de les documenter.
	public String getNom() {
		return nom;
	}
	public int getPuissance() {
		return puissance;
	}
	public short getPrecision() {
		return precision;
	}
	public Type getType() {
		return type;
	}
	public static int getStatusAtk() {
		return STATUS_ATK;
	}
	public static int getDegatsAtk() {
		return DEGATS_ATK;
	}
	public boolean isSpecial() {
		return special;
	}
	public boolean isStatus() {
		return status;
	}
	public int getPart() {
		return part;
	}
	public int getPp() {
		return pp;
	}
	public int getPpMax() {
		return ppMax;
	}
	public int getChanceDeCoups() {
		return chanceDeCoups;
	}
	public boolean isRateJamais() {
		return rateJamais;
	}
	
	/**
	 * Construit une attaque.<br/>
	 *  Ce constructeur doit obligatoirement �tre appel� par super dans un constructeur par d�faut puisque l'attaque est cr�e par class.newInstance().
	 * @param nom - Le nom de l'attaque
	 * @param puissance - La puissance de l'attaque (Noooon? C'est vrai?)
	 * @param type - Le type (J'y aurait jamais cru!)
	 * @param precision - La pr�cision... (J'ai vraiment besoin de pr�ciser? HAHAHAHAHAHAHA!)
	 * @param special - Bon vous savez quoi? Voir : {@link #special} (J'ai la flemme de tout redocumenter pour le constructeur.)
	 * @param status - {@link #status} 
	 * @param chanceDeCoups - {@link #chanceDeCoups}
	 * @param rateJamais - {@link #rateJamais}
	 * @param ppMax - {@link #ppMax}
	 * 
	 */
	protected Attaque(String nom, int puissance, Type type, int precision, boolean special, boolean status, int chanceDeCoups, boolean rateJamais, int ppMax){
		this.nom = nom;
		this.puissance = puissance;
		this.type = type;
		this.precision = (short) precision;
		this.special = special;
		this.status = status;
		this.chanceDeCoups = chanceDeCoups;
		this.rateJamais = rateJamais;
		this.pp = this.ppMax = ppMax;
		priorite = 0;
	}
	protected Attaque(String nom, int puissance, Type type, int precision, boolean special, boolean status, int chanceDeCoups, boolean rateJamais, int ppMax, int priorite){
		this.nom = nom;
		this.puissance = puissance;
		this.type = type;
		this.precision = (short) precision;
		this.special = special;
		this.status = status;
		this.chanceDeCoups = chanceDeCoups;
		this.rateJamais = rateJamais;
		this.pp = this.ppMax = ppMax;
		this.priorite = priorite;
	}
	public int getPriorite(){
		return priorite;
	}
	/**
	 * Action effectu�e si l'attaque �choue.
	 * @param atk - Le pokemon attaquant
	 * @param def - Le pokemon d�fenseur
	 */
	public void siEchoue(Pokemon atk, Pokemon def){
		
	}
	
	
}
