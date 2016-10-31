package jlppc.regimys.objects.items;

import jlppc.regimys.objects.Attaque;
import jlppc.utils.WIP;
@WIP
public class CT extends Item {
	
	Class<Attaque> atk;
	
	public CT(Class<Attaque> atk) {
		super(atk.getName(), true, false, BagCat.CTS);
		this.atk = atk;
	}
	
	public static void initCTs(){
		
	}
	
	
	
}
