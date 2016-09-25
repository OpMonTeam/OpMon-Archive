package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.Type;

public class PoudreToxik extends Attaque {
	public PoudreToxik() {
		super("Poudre Toxik", 0, Type.POISON, 75, false, true, -1, false, 35);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.getType1() != Type.POISON){
			if(def.setStatus(Status.POISON)){
				keyout(key("effects.status.poison"), def.getSurnom());
			}else{
				keyout(key("effects.status.fail"), def.getSurnom(), "empoisonné");
			}
		}else{
			System.out.println("Mais cela echoue!");
		}

	}
}
