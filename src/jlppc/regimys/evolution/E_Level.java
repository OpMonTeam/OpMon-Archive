package jlppc.regimys.evolution;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;

public class E_Level extends Evolution {
	
	protected int level;
	
	public E_Level(Espece toEvolve, int level) {
		super(toEvolve);
		this.level = level;
	}

	@Override
	public boolean checkEvolve(Pokemon toCheck) {
		return (toCheck.getLevel() >= level);
	}
}
