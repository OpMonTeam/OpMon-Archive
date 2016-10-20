package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class CoudKrane extends Attaque {
	public CoudKrane() {
		super("Coud'Krâne", 130, Type.NORMAL, 100, false, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 0){
			fosout("%o baisse la tête", atk.getSurnom());
			def.changeDEF(1);
			part = 1;
			throw new SameAtkPartTwo();
		}else{
			part = 0;
			def.changeDEF(-1);
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		// TODO Auto-generated method stub

	}
}
