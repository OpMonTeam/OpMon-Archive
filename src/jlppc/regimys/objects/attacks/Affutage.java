package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Affutage extends Attaque {

	public Affutage(){
		super("Affûtage", 0, Type.NORMAL, 100, false, true, -1, true, 30);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(atk.changeATK(1)){
			System.out.println("L'attaque de " + atk.getSurnom() + " augmente!");
		}else{
			System.out.println("L'attaque de " + atk.getSurnom() + " ne peut plus augmenter!");
		}

	}

}
