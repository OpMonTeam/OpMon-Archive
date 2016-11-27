package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class ChocPsy extends Attaque {
	public ChocPsy() {
		super("Choc Psy", 80, Type.PSY, 100, true, false, 16, false, 10);
	}

	int def;
	int defspe;
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		this.def = def.getStatDEF();
		this.defspe = def.getStatDEFSPE();
		def.setStat("defspe", this.def);
		
	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		def.setStat("defspe", defspe);

	}
}
