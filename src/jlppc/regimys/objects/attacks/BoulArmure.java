package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class BoulArmure extends Attaque {

	public BoulArmure(){
		super("Boul'Armure", 0, Type.NORMAL, 100, false, false, -1, true, 40);
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
