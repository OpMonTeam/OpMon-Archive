package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Rebondifeu extends Attaque {
	public Rebondifeu() {
		super("Rebondifeu", 70, Type.FEU, 100, true, false, 8, false, 15);//Je lui mets plus de coups critiques pour compenser sa perte d'efficacité (Pas d'effet secondaire parce que pas de combats duo)
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		// TODO Auto-generated method stub

	}
}
