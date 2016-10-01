package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;

public class BullesDo extends Attaque {
	
	public BullesDo(){
		super("Bulles d'O", 65, Type.EAU, 100, true, false, 16, false, 20);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Start.rand.nextInt(10) == 2){
			if(def.changeVIT(-1)){
				System.out.println(FormattedString.format("La vitesse de %o baisse!", def.getSurnom()));
			}else{
				FormattedString.outPrintln("La vitesse de %o ne peut plus baisser!", def.getSurnom());
			}
			
		}else{
			
		}
	}

}
