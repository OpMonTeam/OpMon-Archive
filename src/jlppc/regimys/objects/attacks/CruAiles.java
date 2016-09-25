package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class CruAiles extends Attaque {
	
	public CruAiles(){
		super("Cru-Aile", 60, Type.VOL, 100, false, false, 16, false, 35);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {}

}
