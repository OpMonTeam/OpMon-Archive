package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.regimys.objects.Pokemon.Status;

public class Blizzard extends Attaque {
	
	public Blizzard(){
		super("Blizzard", 110, Type.GLACE, 70, true, false, 16, false, 5);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) == 2){
			System.out.println(def.getSurnom() + " est gelé!");
			def.setStatus(Status.GEL);
		}

	}

}
