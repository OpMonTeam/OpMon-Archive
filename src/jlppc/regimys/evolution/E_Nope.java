package jlppc.regimys.evolution;

import jlppc.regimys.objects.Pokemon;

public class E_Nope extends Evolution {
	public E_Nope() {
		super(null);
	}

	@Override
	public boolean checkEvolve(Pokemon toCheck) {
		return false;
	}
}
