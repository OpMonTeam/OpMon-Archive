package jlppc.regimys.objects.attacks;

import jlppc.regimys.objects.*;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.utils.*;
import jlppc.regimys.enums.Type;
import jlppc.regimys.launch.Start;

public class LanceFlammes extends Attaque{
	public LanceFlammes(){
		super("Lance-Flammes", 90, Type.FEU, 100, true, false, 16, false, 15);
	}
	
	
	public void effetAvant(Pokemon atk, Pokemon def){}
	
	public void effetApres(Pokemon atk, Pokemon def){
		if(Start.rand.nextInt() == 5 ){
			FormattedString.outPrintln("%o est brûlé!", def.getSurnom() );
			def.setStatus(Status.BRULURE);
		}
	}
	
}