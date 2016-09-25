package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Ultimapoing extends Attaque {
	public Ultimapoing() {
		super("Ultimapoing", 80, Type.COMBAT, 85, false, false, 16, false, 20);//Normalement c'est une attaque de type Normal mais je la met de type combat avec son nom.
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}
}
