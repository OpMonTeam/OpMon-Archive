package jlppc.regimys.objects.attacks;

import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Type;

public class BecVrille extends Attaque {

	public BecVrille(){
		super("Bec Vrille", 80, Type.VOL, 100, false, false, 16, false, 20);
	}
	
	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn {}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {}

}
