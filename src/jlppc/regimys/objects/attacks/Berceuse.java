package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.regimys.objects.Pokemon.Status;

public class Berceuse extends Attaque {

	public Berceuse(){
		super("Berceuse", 0, Type.NORMAL, 55, false, true, -1, false, 15);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(def.setStatus(Status.SOMMEIL)){
			System.out.println(def.getSurnom() + " s'endort!");
		}else{
			System.out.println("Mais " + def.getSurnom() + " dort déjà!");
		}
	}

}
