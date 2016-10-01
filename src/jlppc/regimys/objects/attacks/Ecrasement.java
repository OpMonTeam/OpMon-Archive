package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class Ecrasement extends Attaque {
	public Ecrasement(){
		super("Ecrasement", 65, Type.NORMAL, 100, false, false, 16, true, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) < 3){
			FormattedString.outPrintln("%o est apeuré!", def.getSurnom());
			def.peur = true;
		}

	}
}
