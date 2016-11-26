package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.Time;

public class Synthese extends Attaque {
	public Synthese() {
		super("Synthese", 0, Type.PLANTE, 100, false, true, -1, true, 5);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(Integer.decode(Time.getPers("HH")).intValue() < 7 || Integer.decode(Time.getPers("hh")).intValue() > 20){
			atk.heal(Math.round(atk.getStatPV() / 2f));
		}else{
			atk.heal(Math.round(atk.getStatPV() / 4f));
		}

	}
}
