package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;

public class Devoreve extends Attaque {
	public Devoreve() {
		super("Dévorêve", 100, Type.PSI, 100, true, false, 16, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(!(def.getStatus() == Status.SOMMEIL)){
			keyout(key("attack.fail"));
			throw new EndOfTurn();
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		atk.heal(pvPerdus / 2);
		fosout("%o récupère %o PV!", atk.getSurnom(), pvPerdus/2);

	}
}
