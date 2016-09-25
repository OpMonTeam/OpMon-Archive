package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
//A voir plus tard
public abstract class Etreinte extends Attaque {
	

	public Etreinte(String nom, int puissance, Type type, int precision, boolean special, boolean status, int chanceDeCoups, boolean rateJamais, int ppMax) {
		super(nom, puissance, type, precision, special, status, chanceDeCoups, rateJamais, ppMax);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		// TODO Auto-generated method stub

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}
}
