package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Flash extends Attaque {
	public Flash() {
		super("Flash", 0, Type.NORMAL, 100, false, true, -1, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.changePRE(-1)){
			keyout(key("effects.stats.pre.low"), def.getSurnom());
		}else{
			keyout(key("effects.stats.pre.cantlow"), def.getSurnom());
		}

	}
}
