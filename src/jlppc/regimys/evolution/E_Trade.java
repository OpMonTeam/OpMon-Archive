package jlppc.regimys.evolution;

import jlppc.regimys.objects.Pokemon;

public class E_Trade extends Evolution {
	public E_Trade(int evo) {
		super(evo);
	}

	@Override
	public boolean checkEvolve(Pokemon toCheck) {
		return true;
	}
}
