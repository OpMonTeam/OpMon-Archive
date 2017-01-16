package jlppc.regimys.evolution;

import java.io.Serializable;

import jlppc.regimys.launch.Initializer;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
/**
 * Classe permettant de définir une évolution, qui pourra être differente selon les cas<br/>
 * Les classes filles ne seront pas documentés, puisque je pense que les noms sont assez explicites.
 * @author jlppc
 */
public abstract class Evolution implements Serializable{
	/**L'espece en laquelle le pokémon evolura*/
	protected Espece toEvolve;
	/**Le numéro pokedex du pokemon qui évolura*/
	protected int evo;
	
	public Evolution(int evo) {
		this.evo = evo;
	}
	/**Retourne true si l'évolution est possible, false sinon*/
	public abstract boolean checkEvolve(Pokemon toCheck);
	
	public Espece getEvolution(){
		return toEvolve;
	}
	/**Permet de charger l'évolution aprÃ¨s que tous les pokémons aient été chargés*/
	public void checkEvo(){
		toEvolve = Initializer.listePoke[evo];
	}
}
