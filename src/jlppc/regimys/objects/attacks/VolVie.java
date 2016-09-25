package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class VolVie extends Attaque {
	public VolVie() {
		super("Vol-Vie", 20, Type.PLANTE, 100, true, false, 16, false, 25);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		atk.heal((pvPerdus/2));
		keyout(key("attack.pkmn.absorb"), def.getSurnom(), atk.getSurnom(), pvPerdus/2);

	}
}
