package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class CrocFatal extends Attaque {
	
	public CrocFatal(){
		super("Croc Fatal", 0, Type.NORMAL, 90, false, true, -1, false, 10);
	}
	

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		FormattedString.outPrint("%o a perdu %o pv.", def.getSurnom(), (def.getPV() == 1) ? 1 : Math.round(def.getPV() / 2));
		if(def.getPV() != 1){
			def.attacked(Math.round(def.getPV() / 2));
		}else{
			def.attacked(1);
		}
		FormattedString.outPrintln("Il lui reste %o pv", def.getPV());
		throw new EndOfTurn();

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {}

}
