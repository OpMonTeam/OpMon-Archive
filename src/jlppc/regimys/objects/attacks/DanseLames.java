package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class DanseLames extends Attaque {
	public DanseLames() {
		super("Danse-Lames", 0, Type.NORMAL, 100, false, true, -1, true, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(atk.changeATK(2)){
			FormattedString.outPrintln("L'attaque de %o augmente beaucoup!", atk.getSurnom());
		}else{
			FormattedString.outPrintln("L'attaque de %o ne peut plus augmenter!", atk.getSurnom());
		}

	}
}
