package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Pique extends Attaque {
	public Pique() {
		super("Piqué", 140, Type.VOL, 90, false, false, 8, false, 5);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 0){
			fosout("%o est entouré d'une lumière intense!", def.getSurnom());
			part = 1;
			throw new EndOfTurn();
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(rand(10) < 3){
			def.peur = true;
			keyout(key("effects.status.peur"), def.getSurnom());
		}

	}
}
