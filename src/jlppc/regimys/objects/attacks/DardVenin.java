package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.utils.FormattedString;

public class DardVenin extends Attaque {
	public DardVenin() {
		super("Dard-Venin", 15, Type.POISON, 100, false, false, 16, false, 35);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(Start.rand.nextInt(10) < 3){
			FormattedString.outPrintln("%o est empoisonné!", def.getSurnom());
			def.setStatus(Status.POISON);
		}

	}
}
