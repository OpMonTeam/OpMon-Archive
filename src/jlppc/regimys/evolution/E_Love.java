package jlppc.regimys.evolution;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;

public class E_Love extends Evolution {
	public E_Love(Espece toEvolve) {
		super(toEvolve);
	}

	@Override
	public boolean checkEvolve(Pokemon toCheck) {
		// TODO Auto-generated method stub
		return (toCheck.getStatLove() > 100);
	}
}
