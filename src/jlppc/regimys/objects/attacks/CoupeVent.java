package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class CoupeVent extends Attaque {

	public CoupeVent(){
		super("Coupe-Vent", 80, Type.NORMAL, 100, true, false, 8, false, 10);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 0){
			part = 1;
			FormattedString.outPrintln("%o déclanche un cyclone!", atk.getSurnom());
			throw new SameAtkPartTwo();
		}else if(part == 1){
			part = 0;
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {}

}
