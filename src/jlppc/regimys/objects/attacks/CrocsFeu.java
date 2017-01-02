package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;

public class CrocsFeu extends Attaque {
	public CrocsFeu() {
		super("Crocs Feu", 65, Type.FEU, 95, false, false, 16, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(rand(10) == 5){
			if(def.setStatus(Status.BRULURE)){
				keyout(key("effects.status.brulure"), def.getSurnom());
			}
		}
		if(rand(10) == 7){
			def.peur = true;
			keyout(key("effects.status.peur"), def.getSurnom());
		}
	}
}
