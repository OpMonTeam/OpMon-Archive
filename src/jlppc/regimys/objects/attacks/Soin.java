package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Soin extends Attaque {
	public Soin() {
		super("Soin", 0, Type.NORMAL, 100, false, true, -1, true, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		fosout("%o récupère des PV!", atk.getSurnom());
		atk.heal(atk.getStatPV() / 2);
	}
}
