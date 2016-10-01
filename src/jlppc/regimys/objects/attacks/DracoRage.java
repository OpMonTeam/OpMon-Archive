package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class DracoRage extends Attaque {
	public DracoRage() {
		super("Draco-rage", 0, Type.DRAGON, 100, false, true, -1, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		keyout(key("attack.pkmn.attacked"), def.getSurnom(), 40, def.getPV() - 40);
		def.attacked(40);

	}
}
