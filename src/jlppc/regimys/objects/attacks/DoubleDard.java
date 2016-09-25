package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class DoubleDard extends Attaque {
	public DoubleDard() {
		super("Double-Dard", 25, Type.INSECTE, 100, false, false, 16, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		if(Start.rand.nextInt(10) < 2){
			def.setStatus(Status.POISON);
			FormattedString.outPrintln("%o est empoisonné!", def.getSurnom());
		}
		if(def.getPV() <= 0){
			FormattedString.outPrintln("%o attaque une deuxième fois!", atk.getSurnom());
			def.attacked(pvPerdus);
			FormattedString.outPrintln("%o a perdu %o pv. Il lui reste %o pv.", def.getSurnom(), pvPerdus, def.getPV());
			if(Start.rand.nextInt(10) < 2){
			
					def.setStatus(Status.POISON);
				FormattedString.outPrintln("%o est empoisonné!", def.getSurnom());
			}
		}

	}
}
