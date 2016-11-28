package jlppc.regimys.objects.items;

import jlppc.regimys.objects.attacks.*;
import jlppc.utils.WIP;
@WIP
public class CT <T> extends Item {
	
	Class<T> atk;
	
	public CT(Class<T> atk, int ctnumber) {
		super("CT" + ctnumber + atk.getName(), true, false,false, BagCat.CTS);
		this.atk = atk;
	}
	
	public CT(Class<T> atk, boolean isCS, int csnumber){
		super(((isCS) ? "CS" : "CT") + csnumber + atk.getName(), true, false,false, BagCat.CTS);
	}
	
	public Class<T> getAtk(){
		return atk;
	}
	
	public static void initCTs(){
		itemList.add(new CT<Aiguisage>(Aiguisage.class, 1));
		itemList.add(new CT<Dracogriffe>(Dracogriffe.class, 2));
		itemList.add(new CT<ChocPsy>(ChocPsy.class, 3));
		itemList.add(new CT<Plenitude>(Plenitude.class, 4));
		itemList.add(new CT<OndeBoreale>(OndeBoreale.class, 5));
		itemList.add(new CT<Toxik>(Toxik.class, 6));
		itemList.add(new CT<OndeFolie>(OndeFolie.class, 7));
		itemList.add(new CT<Gonflette>(Gonflette.class, 8));
	}
	
	
	
}
