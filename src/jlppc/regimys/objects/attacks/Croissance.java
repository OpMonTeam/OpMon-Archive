package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class Croissance extends Attaque {
	
	public Croissance(){
		super("Croissance", 0, Type.NORMAL, 100, false, true, -1, true, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(atk.changeATKSPE(1)){
			FormattedString.outPrintln("L'attaque spéciale de %o augmente!", atk.getSurnom());
		}else{
			FormattedString.outPrintln("L'attaque spéciale de %o ne peut plus augmenter!", atk.getSurnom());
		}
		
		if(atk.changeATK(1)){
			FormattedString.outPrintln("L'attaque de %o augmente!", atk.getSurnom());
		}else{
			FormattedString.outPrintln("L'attaque de %o ne peut plus augmenter!", atk.getSurnom());
		}

	}

}
