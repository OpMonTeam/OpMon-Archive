package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Amnesie extends Attaque {

	public Amnesie(){
		super("Amnésie", 0, Type.PSI, 100, false, true, -1, true, 20);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(atk.changeDEFSPE(2)){
			System.out.println("La defense spéciale de " + atk.getSurnom() + " monte beaucoup!");
		}else{
			System.out.println("La defense spéciale de " + atk.getSurnom() + " ne peut plus augmenter");
		}

	}

}
