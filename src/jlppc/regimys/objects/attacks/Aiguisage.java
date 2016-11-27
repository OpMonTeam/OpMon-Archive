package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Aiguisage extends Attaque {
	public Aiguisage() {
		super("Aiguisage", 0, Type.NORMAL, 100, false, true, -1, true, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(atk.changeATK(1)){
			keyout(key("effects.stats.atk.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.atk.cantadd"), atk.getSurnom());
		}
		if(atk.changePRE(1)){
			keyout(key("effects.stats.pre.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.pre.cantadd"), atk.getSurnom());
		}

	}
}
