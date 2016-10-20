package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class OmbreNocturne extends Attaque {
	public OmbreNocturne() {
		super("Ombre Nocturne", 0, Type.SPECTRE, 100, false, true, -1, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		def.attacked(atk.getLevel());
		keyout(key("attack.pkmn.attacked"), def.getSurnom(), atk.getLevel(), def.getPV());
		
	}
}
