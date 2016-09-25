package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Acidarmure extends Attaque {

	public Acidarmure(){
		super("Acidarmure", 0, Type.POISON, 100, false, true, -1, true, 20);
	}
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(atk.changeDEF(2)){
			System.out.println("La defense de " + atk.getSurnom() + " monte beaucoup!");
		}else{
			System.out.println("La defense de " + atk.getSurnom() + " ne peut plus augmenter");
		}
		
	}

}
