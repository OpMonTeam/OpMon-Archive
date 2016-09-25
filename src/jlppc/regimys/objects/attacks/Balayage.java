package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class Balayage extends Attaque {

	public Balayage(){
		super("Balayage", 0, Type.COMBAT, 100, false, false, 16, false, 20);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {
		if(def.getEspece().getPoids() <= 10){
			puissance = 20;
		}else if(def.getEspece().getPoids() > 10 && def.getEspece().getPoids() <= 25){
			puissance = 40;
		}else if(def.getEspece().getPoids() > 25 && def.getEspece().getPoids() <=50){
			puissance = 60;
		}else if(def.getEspece().getPoids() > 50 && def.getEspece().getPoids() <= 100){
			puissance = 80;
		}else if(def.getEspece().getPoids() > 100 && def.getEspece().getPoids() <= 200){
			puissance = 100;
		}else{
			puissance = 120;
		}
	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}

}
