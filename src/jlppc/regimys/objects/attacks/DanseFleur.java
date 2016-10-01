package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class DanseFleur extends Attaque {
	public DanseFleur() {
		super("Danse-Fleur", 120, Type.PLANTE, 100, true, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(part == 0){
			part = 1;
			throw new SameAtkPartTwo();
		}else if(part == 1){
			pp++;
			if(Start.rand.nextBoolean()){
				part = 2;
				throw new SameAtkPartTwo();
			}else{
				part = 0;
				atk.confus = true;
				keyout(key("effects.status.confus"), atk.getSurnom());
			}
		}else{
			pp++;
			part = 0;
			atk.confus = true;
			keyout(key("effects.status.confus"), atk.getSurnom());
		}
	}
}
