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
public class Vol extends Attaque {
	int esquiveBase;
	public Vol() {
		super("Vol", 90, Type.VOL, 95, false, false, 16, false, 15);
	}

	@Override
	protected void effetAvant(Pokemon atk, Pokemon def) throws EndOfTurn, SameAtkPartTwo {
		if(part == 0){
			part = 1;
			FormattedString.outPrintln("%o s'envole!", atk.getSurnom());
			esquiveBase = atk.getStatESQ();
			atk.setStatESQ(10000);
			throw new SameAtkPartTwo();
		}else{
			part = 0;
			atk.setStatESQ(esquiveBase);
			FormattedString.outPrintln("%o fonce sur %o!", atk.getSurnom(), def.getSurnom());
		}

	}

	@Override
	protected void effetApres(Pokemon atk, Pokemon def) {
		// TODO Auto-generated method stub

	}
}
