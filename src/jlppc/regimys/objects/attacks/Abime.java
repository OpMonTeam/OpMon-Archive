package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Abime extends Attaque {

	public Abime(){
		super("Abime", 99999, Type.SOL, 30, false, false, -1, false, 5);
}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {
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
