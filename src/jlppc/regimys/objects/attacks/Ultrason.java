package jlppc.regimys.objects.attacks;

import jlppc.regimys.objects.*;
import jlppc.utils.*;
import jlppc.regimys.enums.Type;
import jlppc.regimys.launch.Start;

public class Ultrason extends Attaque{
	
	public Ultrason(){
		super("Ultrason", 0, Type.NORMAL, 55, false, true, -1, false, 20);
	}
	
	public void effetAvant(Pokemon atk, Pokemon def){}
	
	public void effetApres(Pokemon atk, Pokemon def){
		FormattedString.outPrintln("%o est confus!", def.getSurnom());
		def.confus = true;
	}
	
	
}