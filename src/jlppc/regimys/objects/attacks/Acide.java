package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;

public class Acide extends Attaque {
	
	public Acide(){
		super("Acide", 40, Type.POISON, 100, true, false, 16, false, 30);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {
		

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) == 2){
			if(def.changeDEFSPE(-1)){
				System.out.println("La défense spéciale de " + def.getSurnom() + " baisse!");
			}else{
				System.out.println("La defense spéciale de " + def.getSurnom() + " ne peut plus baisser!");
			}
		}
	}

}
