package jlppc.regimys.objects.attacks;

import jlppc.regimys.objects.*;
import jlppc.utils.*;

public class Sonicboom extends Attaque{
	
	public Sonicboom(){
		super(Sonicboom.class.getName(), 0, Type.NORMAL, 90, true, true, -1, false, 20);
	}
	
	public void effetAvant(Pokemon atk, Pokemon def){}
	
	public void effetApres(Pokemon atk, Pokemon def){
		FormattedString.outPrintln("%o a perdu 20 PV. Il lui en reste %o", def.getSurnom(), def.getPV() - 20);
		def.attacked(20);
	}
	
	
	
}