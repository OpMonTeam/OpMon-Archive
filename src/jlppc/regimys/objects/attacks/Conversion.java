package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Conversion extends Attaque {
	
	public Conversion(){
		super("Conversion", 0, Type.NORMAL, 100, false, true, -1, true, 30);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		atk.setType1(atk.getAttaques()[0].getType());
		atk.setType2(Type.AUCUN);
		System.out.println(atk.getSurnom() + " prend le type " + atk.getType1().nom);
	}

}
