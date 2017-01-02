package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;

public class Feudenfer extends Attaque {
	public Feudenfer() {
		super("Feu d'Enfer", 100, Type.FEU, 50, true, false, 16, false, 5);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.setStatus(Status.BRULURE)){
			keyout(key("effects.status.brulure"), def.getSurnom());
		}else{
			keyout(key("effects.status.fail"), def.getStatus());
		}

	}
}
