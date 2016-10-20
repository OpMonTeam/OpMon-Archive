package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Reflet extends Attaque {
	public Reflet() {
		super("Reflet", 0, Type.NORMAL, 100, false, true, -1, true, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(atk.changeESQ(1)){
			keyout(key("effects.stats.esq.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.esq.cantadd"), atk.getSurnom());
		}

	}
}
