package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Charge extends Attaque{
	public Charge(){
		super("Charge", 50, Type.NORMAL, 100, false, false, 16, false, 35);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub
		
	}
}
