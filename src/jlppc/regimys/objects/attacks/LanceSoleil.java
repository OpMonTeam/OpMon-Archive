package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class LanceSoleil extends Attaque {
	public LanceSoleil() {
		super("Lance-Soleil", 120, Type.PLANTE, 100, true, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 0){
			part = 1;
			FormattedString.outPrintln("%o absorbe les rayons du soleil!!", atk.getSurnom());
			throw new SameAtkPartTwo();
		}else{
			part = 0;
			
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		// TODO Auto-generated method stub

	}
}
