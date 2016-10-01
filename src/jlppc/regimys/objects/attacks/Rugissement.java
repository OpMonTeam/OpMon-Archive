package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class Rugissement extends Attaque {
	public Rugissement() {
		super("Rugissement", 0, Type.NORMAL, 100, false, true, -1, false, 35);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.changeATK(-1)){
			FormattedString.outPrintln("L'attaque de %o baisse!", def.getSurnom());
		}else{
			FormattedString.outPrintln("L'attaque de %o ne peut plus baisser!", def.getSurnom());
		}

	}
}
