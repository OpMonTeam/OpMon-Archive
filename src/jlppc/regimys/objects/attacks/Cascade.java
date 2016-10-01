package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class Cascade extends Attaque {
	public Cascade(){
		super("Cascade", 80, Type.EAU, 100, false, false, 16, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(5) == 2){
			def.peur = true;
			FormattedString.outPrintln("%o prend peur!", def.getSurnom());
		}
		
	}
}
