package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Secretion extends Attaque {
	
	public Secretion() {
		super("Sécrétion", 0, Type.INSECTE, 95, false, true, -1, false, 40);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(def.changeVIT(-2)){
			keyout(key("effects.stats.vit.lowtwo"), def.getSurnom());
		}else{
			keyout(key("effects.stats.vit.cantlow"), def.getSurnom());
		}

	}
}
