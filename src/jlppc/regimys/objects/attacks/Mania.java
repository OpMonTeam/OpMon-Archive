package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class Mania extends Attaque {
	public Mania() {
		super("Mania", 120, Type.NORMAL, 100, false, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo{
		if(part == 0){
			part = 1;
			throw new SameAtkPartTwo();
		}else if(part == 1){
			if(Start.rand.nextBoolean()){
				part = 2;
				throw new SameAtkPartTwo();
			}else{
				part = 0;
			}
			
		}else if(part == 2){
			part = 0;
			FormattedString.outPrintln("%o devient confus!", atk.getSurnom());
			atk.confus = true;
		}

	}
}
