package jlppc.regimys.evolution;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;

public class E_Trade extends Evolution {
	public E_Trade(Espece toEvolve) {
		super(toEvolve);
	}

	@Override
	public boolean checkEvolve(Pokemon toCheck) {
		return true;
	}
}
