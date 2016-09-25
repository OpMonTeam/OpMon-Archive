package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.utils.FormattedString;

public class Constriction extends Attaque {
	
	public Constriction() {
		super("Constriction", 10, Type.NORMAL, 100, false, false, 8, false, 35);//8 au lieu de 16 juste parce que l'attaque me fait pitié...
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) == 2){
			if(def.changeVIT(-1)){
				FormattedString.outPrintln("La vitesse de %o baisse!", def.getSurnom());
			}else{
				FormattedString.outPrintln("La vitesse de %o ne peut plus baisser!", def.getSurnom());
			}
		}

	}

}
