package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Repli extends Attaque {
	public Repli() {
		super("Repli", 0, Type.EAU, 100, false, true, -1, true, 40);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(atk.changeDEF(1)){
			keyout(key("effects.stats.def.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.def.cantadd"), atk.getSurnom());
		}

	}
}
