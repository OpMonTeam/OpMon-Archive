package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;

public class Triplattaque extends Attaque {
	public Triplattaque() {
		super("Triplattaque", 80, Type.NORMAL, 100, true, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(rand(5) == 3){
			switch(rand(3)){
			case 0:
				if(def.setStatus(Status.BRULURE)){
					keyout(key("effects.status.brulure"), def.getSurnom());
				}
				break;
			case 1:
				if(def.setStatus(Status.PARALYSIE)){
					keyout(key("effects.status.para"), def.getSurnom());
				}
				break;
			case 2:
				if(def.setStatus(Status.GEL)){
					keyout(key("effects.status.gel"), def.getSurnom());
				}
				break;
			}
		}

	}
}
