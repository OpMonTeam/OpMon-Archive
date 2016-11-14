package jlppc.regimys.evolution;

import java.io.Serializable;

import jlppc.regimys.launch.Initializer;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;

public abstract class Evolution implements Serializable{
	
	protected Espece toEvolve;
	protected int evo;
	
	public Evolution(int evo) {
		this.evo = evo;
	}
	
	public abstract boolean checkEvolve(Pokemon toCheck);
	
	public Espece getEvolution(){
		return toEvolve;
	}
	public void checkEvo(){
		toEvolve = Initializer.listePoke[evo];
	}
}
