package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;

public class Detritus extends Attaque {
	public Detritus() {
		super("Détritus", 65, Type.POISON, 100, true, false, 16, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(rand(10) < 3){
			if(def.setStatus(Status.POISON)){
				keyout(key("effects.status.poison"), def.getSurnom());
			}
		}

	}
}
