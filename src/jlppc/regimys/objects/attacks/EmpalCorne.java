package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class EmpalCorne extends Attaque {
	public EmpalCorne() {
		super("Empal'Korne", 65535, Type.NORMAL, 30, false, false, -1, false, 5);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		precision = (short) ((atk.getLevel() - def.getLevel()) + 30);
		if(atk.getLevel() < def.getLevel()){
			System.out.println("Mais cela echoue!");
			throw new EndOfTurn();
		}
		if(Start.rand.nextInt(100) > precision){
			System.out.println("Mais cela echoue!");
			throw new EndOfTurn();
		}else{
			def.attacked(def.getPV());
			System.out.println("K.O en un coup!");
			throw new EndOfTurn();
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {}
}
