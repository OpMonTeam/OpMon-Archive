package jlppc.regimys.enums;

import java.io.Serializable;

import jlppc.regimys.launch.Start;

/**
 * WAW! Tous les caract�res des pokemon! Je vais pas les documenter un par un, ca serait totalement INUTILE! Sinon y'a pokepedia!
 * @author Jlppc
 *
 */
public enum Caractere implements Serializable{
	
	ASSURE(Stats.DEF, Stats.ATK), 
	BIZARRE(Stats.RIEN, Stats.RIEN),
	BRAVE(Stats.ATK, Stats.VIT),
	CALME(Stats.DEFSPE, Stats.ATK),
	DISCRET(Stats.ATKSPE, Stats.VIT),
	DOCILE(Stats.RIEN, Stats.RIEN),
	DOUX(Stats.ATKSPE, Stats.DEF),
	FOUFOU(Stats.ATKSPE, Stats.DEFSPE),
	GENTIL(Stats.DEFSPE, Stats.DEF),
	HARDI(Stats.RIEN, Stats.RIEN),
	JOVIAL(Stats.VIT, Stats.ATKSPE),
	LACHE(Stats.DEF, Stats.DEFSPE),
	MALIN(Stats.DEF, Stats.ATKSPE),
	MALPOLI(Stats.DEFSPE, Stats.VIT),
	MAUVAIS(Stats.ATK, Stats.DEFSPE),
	MODESTE(Stats.ATKSPE, Stats.ATK),
	NAIF(Stats.VIT, Stats.DEFSPE),
	PRESSE(Stats.VIT, Stats.DEF),
	PRUDENT(Stats.DEFSPE, Stats.ATKSPE),
	PUDIQUE(Stats.RIEN, Stats.RIEN),
	RELAX(Stats.DEF, Stats.VIT),
	RIGIDE(Stats.ATK, Stats.ATKSPE),
	SERIEUX(Stats.RIEN, Stats.RIEN),
	SOLO(Stats.ATK, Stats.DEF),
	TIMIDE(Stats.VIT, Stats.ATK);
	
	/**
	 * Les statistiques. Permettent de definir les bonus et malus des caract�res. (Et un peu plus aussi ;-) )
	 * @author Jlppc
	 *
	 */
	public enum Stats implements Serializable{
		ATK, DEF, DEFSPE, ATKSPE, VIT, RIEN,
		/**A part, il sert pour les EV*/
		PV;
	}
	/**
	 * Le bonus et malus que offre le caractere.
	 * <br/> Les deux sont d�clar�s sur la m�me ligne parce que... flemme?
	 */
	public final Stats bonus, malus;
	/**
	 * Le constructeur. Devinez a quoi il sert!
	 * @param bonus - {@link #bonus}
	 * @param malus - {@link #malus}
	 */
	private Caractere(Stats bonus, Stats malus){
		this.bonus = bonus;
		this.malus = malus;
	}
	
	public static Caractere random(){
		return Caractere.values()[Start.rand.nextInt(Caractere.values().length)];
	}
}


