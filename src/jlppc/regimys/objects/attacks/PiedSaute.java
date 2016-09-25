package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class PiedSaute extends Attaque {
	public PiedSaute() {
		super("PiedSaute", 100, Type.COMBAT, 95, false, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}
	
	public void siEchoue(Pokemon atk, Pokemon def){
		FormattedString.outPrint("%o s'écrase au sol!", atk.getSurnom());
		atk.attacked(Math.round(atk.getStatPV() / 2));
		FormattedString.outPrintln("Il lui reste %o pv.", atk.getPV());
	}
}
