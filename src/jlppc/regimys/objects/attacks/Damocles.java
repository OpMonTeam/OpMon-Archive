package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class Damocles extends Attaque{
	public Damocles() {
		super("Damoclès", 120, Type.NORMAL, 100, false, false, 16, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		FormattedString.outPrintln("%o prend des dégats! Il lui reste %o pv!", atk.getSurnom(), atk.getPV() - (pvPerdus/3));
		atk.attacked(pvPerdus / 3);
		
	}
}
