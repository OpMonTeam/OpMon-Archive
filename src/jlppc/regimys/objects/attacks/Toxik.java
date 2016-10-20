package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;

public class Toxik extends Attaque {
	public Toxik() {
		super("Toxik", 0, Type.POISON, 90, false, true, -1, false, 15);//15 pour compenser le fait que l'empoisement grave n'existe pas (peut-être qu'un jour...)
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.setStatus(Status.POISON)){
			keyout(key("effects.status.poison"), def.getSurnom());
		}else{
			keyout(key("attack.fail"));
		}

	}
}
