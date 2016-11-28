package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Plenitude extends Attaque {
	public Plenitude() {
		super("Plénitude", 0, Type.PSY, 100, false, true, -1, true, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(atk.changeATKSPE(1)){
			keyout(key("effects.stats.atkspe.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.atkspe.cantadd"), atk.getSurnom());
		}
		if(atk.changeDEFSPE(1)){
			keyout(key("effects.stats.defspe.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.defspe.cantadd"), atk.getSurnom());
		}
		

	}
}
