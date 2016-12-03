package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
/**
 * Cette attaque a été crée par moi, puisque c'est une attaque dont je rève voir apparaitre dans pokémon
 * @author Jlppc
 *
 */
public class Simulation extends Attaque {
	public Simulation() {
		super("Simulation", 80, Type.NORMAL, 90, true, false, 16, false, 15);
	}

	Type typeSave;
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		typeSave = type;
		this.type = atk.getType1();
		

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) throws SameAtkPartTwo {
		type = typeSave;
	}
}
