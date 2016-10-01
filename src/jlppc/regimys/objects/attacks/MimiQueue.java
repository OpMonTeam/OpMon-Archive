package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class MimiQueue extends Attaque {
	public MimiQueue() {
		super("Mimi-Queue", 0, Type.NORMAL, 100, false, false, -1, false, 30);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.changeDEF(-1)){
			FormattedString.outPrintln("La défense de %o baisse!", def.getSurnom());
		}else{
			FormattedString.outPrintln("La défense de %o ne peut plus baisser!", def.getSurnom());
		}

	}
}
