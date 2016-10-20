package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class MassdOs extends Attaque {
	public MassdOs() {
		super("Massd'Os", 65, Type.SOL, 85, false, false,16, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(rand(10) == 5){
			def.peur = true;
			keyout(key("effects.status.peur"), def.getSurnom());
		}

	}
}
