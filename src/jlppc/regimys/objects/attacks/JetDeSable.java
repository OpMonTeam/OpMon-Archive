package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class JetDeSable extends Attaque {
	public JetDeSable() {
		super("Jet de Sable", 0, Type.SOL, 100, false, true, -1, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(def.changePRE(-1)){
			FormattedString.outPrintln("La précision de %o baisse!", def.getSurnom());
		}else{
			FormattedString.outPrintln("La précision de %o ne peut plus baisser!", def.getSurnom());
		}
	}
}
