package jlppc.regimys.evolution;

import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.items.Item;
/**Classe définissant une évolution par Objet
 * @author jlppc
 */
public class E_Item extends Evolution {
	
	protected Item itemForEvolve;
	
	public E_Item(int evo, Item forEv) {
		super(evo);
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
