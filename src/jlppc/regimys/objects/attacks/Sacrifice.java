package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Sacrifice extends Attaque {
	public Sacrifice() {
		super("Sacrifice", 80, Type.COMBAT, 80, false, false, 8, false, 25);//Double coup critique : L'attaque me fait pitié (faut voir l'effet ;-) )
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		int toLose = Math.round(pvPerdus / 4f);
		atk.attacked(toLose);
		keyout(key("effects.stats.pv.ctrcoup"), atk.getSurnom(), toLose);
		

	}
}
