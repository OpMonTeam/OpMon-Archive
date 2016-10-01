package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class DoublePied extends Attaque {
	public DoublePied() {
		super("Double Pied", 30, Type.COMBAT, 100, false, false, 16, false, 30);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(def.getPV() <= 0){
			FormattedString.outPrintln("%o attaque une deuxième fois!", atk.getSurnom());
			def.attacked(pvPerdus);
			FormattedString.outPrintln("%o a perdu %o pv. Il lui reste %o pv.", def.getSurnom(), pvPerdus, def.getPV());
		}

	}
}
