package jlppc.regimys.evolution;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.items.Item;

public class E_Item extends Evolution {
	
	protected Item itemForEvolve;
	
	public E_Item(Espece toEvolve, Item forEv) {
		super(toEvolve);
		itemForEvolve = forEv;
	}

	@Override
	public boolean checkEvolve(Pokemon toCheck) {
		// TODO Auto-generated method stub
		return false;
	}
	
	public boolean itemEvolve(Item forEvolve){
		return forEvolve.equals(itemForEvolve);
	}
}
