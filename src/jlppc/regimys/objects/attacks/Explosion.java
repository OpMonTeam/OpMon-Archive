package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class Explosion extends Attaque {
	public Explosion() {
		super("Explosion", 250, Type.NORMAL, 100, false, false, 16, false, 5);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		FormattedString.outPrintln("%o explose!", atk.getSurnom());
	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		FormattedString.outPrintln("%o est K.O", atk.getSurnom());
		atk.attacked(atk.getPV());

	}
}
