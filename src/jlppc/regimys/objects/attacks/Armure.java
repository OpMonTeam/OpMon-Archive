package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Armure extends Attaque {

	public Armure(){
		super("Armure", 0, Type.NORMAL, 100, false, true, -1, false, 30);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(atk.changeDEF(1)){
			System.out.println("La défense de " + atk.getSurnom() + " augmente!");
		}else{
			System.out.println("La défense de " + atk.getSurnom() + " ne peut plus augmenter!");
		}
	}

}
