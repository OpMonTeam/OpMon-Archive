package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class VaguePsy extends Attaque {
	public VaguePsy() {
		super("Vargue Psy", 0, Type.PSI, 100, true, true, -1, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		pvPerdus = atk.getLevel() * (rand(10) + 5) / 10;
		def.attacked(pvPerdus);
		fosout("%o perd %o pv. Il lui reste %o pv.", def.getSurnom(), pvPerdus, def.getPV());
		throw new EndOfTurn();

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		// TODO Auto-generated method stub

	}
}
