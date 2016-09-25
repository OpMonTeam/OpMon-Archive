package jlppc.regimys.objects.attacks;

import jlppc.regimys.objects.*;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.utils.*;
import jlppc.regimys.launch.Start;

public class Flammeche extends Attaque{
	public Flammeche(){
		super("Flammèche", 40, Type.FEU, 100, true, false, 16, false, 25);
	}
	
	public void effetAvant(Pokemon atk, Pokemon def){}
	
	public void effetApres(Pokemon atk, Pokemon def){
		if(Start.rand.nextInt() == 5 ){
			FormattedString.outPrintln("%o est brûlé!", def.getSurnom() );
			def.setStatus(Status.BRULURE);
		}
	}
	
	
}