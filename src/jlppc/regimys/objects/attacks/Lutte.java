package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
// A ameliorer
public class Lutte extends Attaque {
	public Lutte() {
		super("Lutte", 50, Type.NORMAL, 100, false, false, 8, false, 99999);//Plus de coups critiques, pour ameliorer lutte
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		fosout("%o prend le contrecoup!", atk.getSurnom());
		atk.attacked(atk.getStatPV() / 4);

	}
}
