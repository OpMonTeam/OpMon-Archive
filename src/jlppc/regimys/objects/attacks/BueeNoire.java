package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.Fight;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class BueeNoire extends Attaque {
	
	public BueeNoire(){
		super("Buée Noire", 0, Type.GLACE, 100, false, true, -1, true, 35);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		atk.setStats(Fight.oldStats[0]);
		def.setStats(Fight.oldStats[1]);
		System.out.println("Tous les changements de status sont revenus à la normale!");

	}

}
