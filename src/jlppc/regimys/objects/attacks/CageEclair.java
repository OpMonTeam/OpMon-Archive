package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.utils.Comparaisons;
import jlppc.utils.FormattedString;

public class CageEclair extends Attaque {

	public CageEclair(){
		super("Cage-Eclair", 0, Type.ELECTRIQUE, 100, false, true, -1, false, 20);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		if(Comparaisons.muliEgal(Type.ELECTRIQUE, def.getType1(), def.getType2())){
			System.out.println("Mais cela n'a aucun effet!");
		}else{
			if(def.setStatus(Status.PARALYSIE)){
				FormattedString.outPrintln("%o est paralysé!", def.getSurnom());
			}else{
				FormattedString.outPrintln("%o est déjà paralysé!", def.getSurnom());
			}
		}

	}

}
