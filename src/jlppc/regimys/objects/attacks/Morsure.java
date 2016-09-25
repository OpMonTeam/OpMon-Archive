package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class Morsure extends Attaque {
	public Morsure() {
		super("Morsure", 60, Type.TENEBRES, 100, false, false, 16, false, 25);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(Start.rand.nextInt(10) < 2){
			FormattedString.outPrintln("%o est apeuré!", def.getSurnom());
			def.peur = true;
		}

	}
}
