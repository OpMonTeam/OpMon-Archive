package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Brouillard extends Attaque {
	
	public Brouillard(){
		super("Brouillard", 0, Type.NORMAL, 100, false, true, -1, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(def.changePRE(-1)){
			System.out.println("La précision de " + def.getSurnom() + " baisse!");
		}else{
			System.out.println("La précision de " + def.getSurnom() + " ne peut plus baisser!");
		}

	}

}
