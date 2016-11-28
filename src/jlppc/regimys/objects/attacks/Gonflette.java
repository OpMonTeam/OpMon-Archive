package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Gonflette extends Attaque {
	public Gonflette() {
		super("Gonflette", 0, Type.COMBAT, 100, false, true, -1, true, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(atk.changeATK(1)){
			keyout(key("effects.stats.atk.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.atk.cantadd"), atk.getSurnom());
		}
		if(def.changeDEF(1)){
			keyout(key("effects.stats.def.add"), atk.getSurnom());
		}else{
			keyout(key("effects.stats.def.cantadd"), atk.getSurnom());
		}
		
		
	}
}
