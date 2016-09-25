package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Guillotine extends Attaque {
	public Guillotine() {
		super("Guillotine", 65535, Type.NORMAL, 30, false, false, -1, false, 5);
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
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}
}
