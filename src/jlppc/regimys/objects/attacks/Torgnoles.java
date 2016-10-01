package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class Torgnoles extends Attaque {
	public Torgnoles() {
		super("Torgnoles", 15, Type.NORMAL, 85, false, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		FormattedString.outPrintln("%o attaque une 1ère fois!", atk.getSurnom());
		if(def.getPV() <= 0){
			return;
		}
		int i = 0;
		int coups = Start.rand.nextInt(4);
		for(i = 0; i != coups + 1; i++){
			FormattedString.outPrintln("%o attaque une %oème fois!", atk.getSurnom(), (i + 2));
			def.attacked(pvPerdus);
			FormattedString.outPrintln("%o perd %o pv. Il lui reste %o pv.", def.getSurnom(), pvPerdus, def.getPV());
			if(def.getPV() <= 0){
				return;
			}
		}

	}
}
