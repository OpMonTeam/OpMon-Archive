package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Ultralaser extends Attaque {
	public Ultralaser() {
		super("Ultralaser", 150, Type.NORMAL, 90, true, false, 16, false, 5);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 1){
			part = 0;
			fosout("%o ne peut pas attaquer!", def.getSurnom());
			throw new EndOfTurn();
		}else{
			part = 1;
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		// TODO Auto-generated method stub

	}
}
