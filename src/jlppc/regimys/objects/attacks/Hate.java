package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Hate extends Attaque {
	public Hate() {
		super("Hâte", 0, Type.PSI, 100, false, true, -1, true, 30);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(atk.changeVIT(2)){
			keyout(key("effects.stats.vit.addtwo"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.vit.cantadd"), atk.getSurnom());
		}

	}
}
