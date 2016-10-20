package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class OndeFolie extends Attaque {
	public OndeFolie() {
		super("Onde Folie", 0, Type.SPECTRE, 100, false, true, -1, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		def.confus = true;
		keyout(key("effects.status.confus"), def.getSurnom());

	}
}
