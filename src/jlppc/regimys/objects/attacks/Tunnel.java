package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.fight.EndOfTurn;
import jlppc.regimys.fight.SameAtkPartTwo;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.utils.FormattedString;
import jlppc.utils.WIP;

/**
 * TODO : Ajouter l'invulnerabilité sauf a certaines attaques.
 * @author jlppc
 *
 */
@WIP
public class Tunnel extends Attaque {
	public Tunnel() {
		super("Tunnel", 80, Type.SOL, 100, false, false, 16, false, 10);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 0){
			part = 1;
			FormattedString.outPrintln("%o s'enfonce dans le sol!", atk.getSurnom());
			
			throw new SameAtkPartTwo();
		}else{
			part = 0;
			FormattedString.outPrintln("%o sort du sol sous les pieds de %o!", atk.getSurnom(), def.getSurnom());
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}
}
