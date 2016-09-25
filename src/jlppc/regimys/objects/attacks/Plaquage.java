package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.utils.FormattedString;

public class Plaquage extends Attaque {
	public Plaquage() {
		super("Plaquage", 85, Type.NORMAL, 100, false, false, 16, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) < 3){
			FormattedString.outPrintln("%o est paralysé!", def.getSurnom());
			def.setStatus(Status.PARALYSIE);
		}

	}
}
