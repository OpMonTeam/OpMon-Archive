package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class Vol extends Attaque {
	public Vol() {
		super("Vol", 90, Type.VOL, 95, false, false, 16, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 0){
			part = 1;
			FormattedString.outPrintln("%o s'envole!", atk.getSurnom());
			throw new SameAtkPartTwo();
		}else{
			part = 0;
			FormattedString.outPrintln("%o fonce sur %o!", atk.getSurnom(), def.getSurnom());
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}
}
