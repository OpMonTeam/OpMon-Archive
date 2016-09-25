package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Belier extends jlppc.regimys.objects.Attaque{
	public Belier(){
		super("Belier", 90, Type.NORMAL, 85, false, false, 16, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		System.out.println(atk.getSurnom() + " prend " + ((int)(pvPerdus / 4)) + " pv de dégats de recul!");
		atk.attacked(Math.round(pvPerdus / 4f));
		
	}
}
