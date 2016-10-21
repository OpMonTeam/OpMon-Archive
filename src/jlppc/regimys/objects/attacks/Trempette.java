package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Trempette extends Attaque {
	public Trempette() {
		super("Trempette", 0, Type.NORMAL, 100, false, true, -1, true, 40);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		System.out.println("Mais rien ne se passe.");
		throw new EndOfTurn();

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		// TODO Auto-generated method stub

	}
}
