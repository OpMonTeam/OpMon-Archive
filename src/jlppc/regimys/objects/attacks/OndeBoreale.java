package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class OndeBoreale extends Attaque {
	public OndeBoreale() {
		super("Onde Boréale", 65, Type.GLACE, 100, true, false, 16, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(rand(10) == 2){
			if(def.changeATK(-1)){
				keyout(key("effects.stats.atk.low"), def.getSurnom());
			}else{
				keyout(key("effects.stat.atk.cantlow"), def.getSurnom());
			}
			
		}

	}
}
