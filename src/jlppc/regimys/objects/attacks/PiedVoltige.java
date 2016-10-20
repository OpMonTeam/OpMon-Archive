package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class PiedVoltige extends Attaque {
	public PiedVoltige() {
		super("Pied Voltige", 130, Type.COMBAT, 90, false, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		// TODO Auto-generated method stub

	}
	
	@Override
	public void siEchoue(Pokemon atk, Pokemon def) {
		fosout("%o s'écrase au sol!", atk.getSurnom());
		atk.attacked(atk.getStatPV() / 2);
	}
}
