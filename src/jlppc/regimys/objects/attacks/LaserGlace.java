package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.utils.FormattedString;

public class LaserGlace extends Attaque {
	public LaserGlace() {
		super("Laser Glace", 90, Type.GLACE, 100, true, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(Start.rand.nextInt(10) == 2){
			FormattedString.outPrintln("%o est gelé!", def.getSurnom());
			def.setStatus(Status.GEL);
		}

	}
}
