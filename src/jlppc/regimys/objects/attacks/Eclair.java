package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.regimys.objects.Pokemon.Status;

public class Eclair extends Attaque {
	
	public Eclair(){
		super("Eclair", 40, Type.ELECTRIQUE, 100, true, false, 16, false, 30); 
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) == 2){
			System.out.println(def.getSurnom() + " est paralysé!");
			def.setStatus(Status.PARALYSIE);
			
		}

	}

}
