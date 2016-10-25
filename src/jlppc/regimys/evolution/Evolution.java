package jlppc.regimys.evolution;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;

public abstract class Evolution {
	
	protected Espece toEvolve;
	
	
	public Evolution(Espece toEvolve) {
		this.toEvolve = toEvolve;
	}
	
	public abstract boolean checkEvolve(Pokemon toCheck);
	
	public Espece getEvolution(){
		return toEvolve;
	}
}
