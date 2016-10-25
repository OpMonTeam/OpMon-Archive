package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class ChocMental extends Attaque {

	public ChocMental(){
		super("Choc Mental", 50, Type.PSY, 100, true, false, 16, false, 25);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) == 2){
			def.confus = true;
			FormattedString.outPrintln("%o est confus!", def.getSurnom());
		}
	}

}
