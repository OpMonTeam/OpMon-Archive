package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.regimys.util.text.StringKey;

public class RafalePsy extends Attaque {
	public RafalePsy() {
		super("Rafale Psy", 65, Type.PSI, 100, true, false, 16, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(Start.rand.nextInt(10) == 2){
			def.confus = true;
			keyout(key("effects.status.confus"), def.getSurnom());
			
		}

	}
}
