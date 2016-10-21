package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;

public class Spore extends Attaque {
	public Spore() {
		super("Spore", 0, Type.PLANTE, 100, false, true, -1, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.setStatus(Status.SOMMEIL)){
			keyout(key("effects.status.sommeil"), def.getSurnom());
		}else{
			keyout(key("attack.fail"));
		}

	}
}
