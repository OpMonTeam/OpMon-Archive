package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class ECoque extends Attaque {
	
	public ECoque(){
		super("E-Coque", 0, Type.NORMAL, 100, false, true, -1, true, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(atk.getPV() == atk.getStatPV()){
			FormattedString.outPrintln("Mais cela échoue!");
		}
		int pvOrigin = atk.getPV();
		atk.heal(Math.round(atk.getPV() / 2));
		FormattedString.outPrintln("%o a récupéré %o pv", atk.getSurnom(), atk.getPV() - pvOrigin);

	}

}
